/// This wrapper function calls the set of optimal trees via the root key which identifies the root of the dependency graph
void Optimizer::models(std::unordered_set< Model > & results) {
    if (Configuration::model_limit == 0) { return; }
    std::unordered_set<std::shared_ptr<Model>, std::hash<std::shared_ptr<Model>>, std::equal_to<std::shared_ptr<Model>>> local_results;
    models(this -> root, local_results);
    /// Copy into final results
    for (auto iterator = local_results.begin(); iterator != local_results.end(); ++iterator) {

        results.insert(**iterator);
    }
}
/// The function creates the set of optimal trees
void Optimizer::models(key_type const & identifier, std::unordered_set<std::shared_ptr<Model>> & results, bool leaf){
    vertex_accessor task_accessor;
    if (State::graph.vertices.find(task_accessor, identifier) == false) { return; }
    Task & task = task_accessor -> second;
    /// The predicate considers if cutting the subtree short with a stump would result in an optimal tree
    if (task.base_objective() <= task.upperbound() + std::numeric_limits<float>::epsilon()) {
        std::shared_ptr<Model> model = std::make_shared<Model>(std::make_shared<Bitmask>(task.capture_set()));
        model -> identify(identifier);
        model -> translate_self(task.order());
        results.insert(model);
    }

    bound_accessor bounds;
    if (!State::graph.bounds.find(bounds, identifier)) { return; }
/// from this onward, we consider each feature that could be used based on their optimal scores. If a feature is
/// selected for resulting in an optimal tree, the function recurses onto the left and right subsets of the data to find
/// the optimal subtrees to plug into the left and right side. If there are multiple equally good left subtrees(and right subtrees)
/// then all possible left-right pair are generated
    for (bound_iterator iterator = bounds -> second.begin(); iterator != bounds -> second.end(); ++iterator) {
        // std::cout << "Bound\n";
        if (std::get<2>(* iterator) > task.upperbound() + std::numeric_limits<float>::epsilon()) { continue; }
        int feature = std::get<0>(* iterator);
        // std::cout << "Feature: " << feature << "\n";
        std::unordered_set<std::shared_ptr<Model>> negatives;
        std::unordered_set<std::shared_ptr<Model>> positives;
        bool ready = true;

        child_accessor left_key, right_key;
        if (State::graph.children.find(left_key, std::make_pair(identifier, -(feature + 1)))) {    
            models(left_key -> second, negatives);
            left_key.release();
        } else {
            Bitmask subset(task.capture_set());
            State::dataset.subset(feature, false, subset);
            std::shared_ptr<Model> model = std::make_shared<Model>(std::make_shared<Bitmask>(subset));
            negatives.insert(model);
        }
        if (State::graph.children.find(right_key, std::make_pair(identifier, feature + 1))) {
            models(right_key -> second, positives);
            right_key.release();
        } else {
            Bitmask subset(task.capture_set());
            State::dataset.subset(feature, true, subset);
            std::shared_ptr<Model> model = std::make_shared<Model>(std::make_shared<Bitmask>(subset));
            positives.insert(model);
        }

        if (negatives.size() == 0 || positives.size() == 0) { continue; }
        
        if (Configuration::rule_list) {
            float potential, min_loss, info, left_leaf_risk, right_leaf_risk;
            unsigned int target_index;
            Bitmask negative_subset(State::dataset.height());
            Bitmask positive_subset(State::dataset.height());
            negative_subset = task.capture_set();
            State::dataset.subset(feature, false, negative_subset);
            State::dataset.summary(negative_subset, info, potential, min_loss, left_leaf_risk, target_index, 0);
            positive_subset = task.capture_set();
            State::dataset.subset(feature, true, positive_subset);
            State::dataset.summary(positive_subset, info, potential, min_loss, right_leaf_risk, target_index, 0);

            left_leaf_risk += Configuration::regularization;
            right_leaf_risk += Configuration::regularization;

            for (auto negative_it = negatives.begin(); negative_it != negatives.end(); ++negative_it) {
                float risk = right_leaf_risk + (**negative_it).loss() + (**negative_it).complexity();                
                if (risk <= task.upperbound() + std::numeric_limits<float>::epsilon()) {
                    if (Configuration::model_limit > 0 && results.size() >= Configuration::model_limit) { continue; }

                    std::shared_ptr<Model> negative(* negative_it);
//                    std::shared_ptr<Model> positive(new Model(std::shared_ptr<Bitmask>(new Bitmask(positive_subset))));
                    auto positive = std::make_shared<Model>(std::make_shared<Bitmask>(positive_subset));
//                     Model * model = new Model(feature, negative, positive);
                    std::shared_ptr<Model> model = std::make_shared<Model>(feature, negative, positive);
                    model -> identify(identifier);
                    model -> translate_self(task.order());
                    translation_accessor negative_translation, positive_translation;
                    if (negative -> identified()
                        && State::graph.translations.find(negative_translation, std::make_pair(identifier, -(feature + 1)))) {
                        model -> translate_negatives(negative_translation -> second);
                    }
                    negative_translation.release();
                    if (positive -> identified()
                        && State::graph.translations.find(positive_translation, std::make_pair(identifier, feature + 1))) {
                        model -> translate_positives(positive_translation -> second);
                    }
                    positive_translation.release();
                    results.insert(model); 
                }
            }
            for (auto positive_it = positives.begin(); positive_it != positives.end(); ++positive_it) {
                float risk = left_leaf_risk + (**positive_it).loss() + (**positive_it).complexity();
                if (risk <= task.upperbound() + std::numeric_limits<float>::epsilon()) {
                    if (Configuration::model_limit > 0 && results.size() >= Configuration::model_limit) { continue; }

//                    std::shared_ptr<Model> negative(new Model(std::shared_ptr<Bitmask>(new Bitmask(negative_subset))));
                    auto negative = std::make_shared<Model>(std::make_shared<Bitmask>(negative_subset));
                    std::shared_ptr<Model> positive(* positive_it);
                    std::shared_ptr<Model> model = std::make_shared<Model>(feature, negative, positive);
                   // Model * model = new Model(feature, negative, positive);
                    model -> identify(identifier);
                    model -> translate_self(task.order());
                    translation_accessor negative_translation, positive_translation;
                    if (negative -> identified()
                        && State::graph.translations.find(negative_translation, std::make_pair(identifier, -(feature + 1)))) {
                        model -> translate_negatives(negative_translation -> second);
                    }
                    negative_translation.release();
                    if (positive -> identified()
                        && State::graph.translations.find(positive_translation, std::make_pair(identifier, feature + 1))) {
                        model -> translate_positives(positive_translation -> second);
                    }
                    positive_translation.release();
                    results.insert(model);
                }
            }
        } else {
            for (auto negative_it = negatives.begin(); negative_it != negatives.end(); ++negative_it) {
                for (auto positive_it = positives.begin(); positive_it != positives.end(); ++positive_it) {

                    if (Configuration::model_limit > 0 && results.size() >= Configuration::model_limit) { continue; }
                    
                    std::shared_ptr<Model> negative(* negative_it);
                    std::shared_ptr<Model> positive(* positive_it);
                    //Model * model = new Model(feature, negative, positive);
                    std::shared_ptr<Model> model = std::make_shared<Model>(feature, negative, positive);
                    model -> identify(identifier);
                    model -> translate_self(task.order());
                    translation_accessor negative_translation, positive_translation;
                    if ((** negative_it).identified()
                        && State::graph.translations.find(negative_translation, std::make_pair(identifier, -(feature + 1)))) {
                        model -> translate_negatives(negative_translation -> second);
                    }
                    negative_translation.release();
                    if ((** positive_it).identified()
                        && State::graph.translations.find(positive_translation, std::make_pair(identifier, feature + 1))) {
                        model -> translate_positives(positive_translation -> second);
                    }
                    positive_translation.release();
                    results.insert(model); 
                }
            }
        }
    }
    return;
}
