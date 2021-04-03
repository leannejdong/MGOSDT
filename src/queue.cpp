#include "queue.hpp"
//#include<memory>

Queue::Queue(void) {
    return;
}

Queue::~Queue(void) {
    std::cerr << "In Queue destructor, queue size =" << queue.size() << "\n";
    return;
}

bool Queue::push(Message const & message) {
   // std::shared_ptr<message_type> internal_message = std::make_shared<message_type>();
    message_type * internal_message = new message_type();
    * internal_message = message;
   // std::cerr << "Create message  " << message << "\n";

    // Attempt to copy content into membership set
    if (this -> membership.insert(std::make_pair(internal_message, true))) {
        this -> queue.push(internal_message);
       // std::cerr << "Create message " << message << "\n";
        return true;
    } else {
       // std::cerr << "Delete message " << message << "\n";
        delete internal_message;
        return false;
    }
}

bool Queue::empty(void) const { return size() == 0; }

unsigned int Queue::size(void) const { return this -> queue.size(); }


bool Queue::pop(Message & message) {
    message_type * internal_message;
    if (this -> queue.try_pop(internal_message)) {
        this -> membership.erase(internal_message); // remove membership
        message = * internal_message;
       // std::cerr << "Delete message " << message << "\n";
        delete internal_message;
       // std::cerr << "Delete message " << message << "\n";

        return true;
    } else {
        return false;
    }
}
