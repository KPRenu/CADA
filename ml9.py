import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics

iris = load_iris()

X = iris.data
y = iris.target

num_samples = X.shape[0]
print(f'Number of samples in the Iris dataset: {num_samples}')

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=1
)

print(f'Number of samples in the training set: {X_train.shape[0]}')
print(f'Number of samples in the testing set: {X_test.shape[0]}')

rf = RandomForestClassifier(n_estimators=100)
rf.fit(X_train, y_train)

y_pred = rf.predict(X_test)

print(
    "Random Forest model accuracy (in %):",
    metrics.accuracy_score(y_test, y_pred) * 100
)

df = pd.DataFrame({'Actual': y_test, 'Predicted': y_pred})
print(df)

label_mapping = {
    0: "iris-setosa",
    1: "iris-versicolor",
    2: "iris-virginica"
}

new_pred = rf.predict([[3, 3, 2, 2]])
print("Result is:", label_mapping[new_pred[0]])
