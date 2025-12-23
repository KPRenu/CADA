import numpy as np
import pandas as pd
from sklearn import metrics, preprocessing
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

df = pd.read_csv(r"C:\Users\HPR\Desktop\ML Syllabus\Play Tennis.csv")

le = preprocessing.LabelEncoder()
df = df.apply(le.fit_transform)

feature_cols = ['Outlook', 'Temprature', 'Humidity', 'Wind']
X = df[feature_cols]
y = df.Play_Tennis

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.30, random_state=100
)

classifier = DecisionTreeClassifier(criterion="gini", random_state=100)
classifier.fit(X_train, y_train)

y_pred = classifier.predict(X_test)

print("Accuracy:", accuracy_score(y_test, y_pred))

data_p = pd.DataFrame({'Actual': y_test, 'Predicted': y_pred})
print(data_p)

print(confusion_matrix(y_test, y_pred))
print(classification_report(y_test, y_pred))
