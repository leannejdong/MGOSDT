import pandas as pd
import numpy as np
from model.gosdt import GOSDT

#dataframe = pd.DataFrame(pd.read_csv("/home/leanne/Dev/mgosdt/experiments/datasets/monk_2/data.csv"))
dataframe = pd.DataFrame(pd.read_csv("/home/leanne/Dev/mgosdt/experiments/datasets/iris/data.csv"))
X = dataframe[dataframe.columns[:-1]]
y = dataframe[dataframe.columns[-1:]]

hyperparameters = {
    "regularization": 0.1,
    "time_limit": 3600,
    "verbose": True,
}

model = GOSDT(hyperparameters)
model.fit(X, y)
print("Execution Time: {}".format(model.time))

prediction = model.predict(X)
training_accuracy = model.score(X, y)
print("Training Accuracy: {}".format(training_accuracy))
print(model.tree)
