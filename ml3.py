import numpy as np
import pandas as pd
from sklearn import preprocessing
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier

# Load dataset
df = pd.read_csv(r"C:\Users\HPR\Desktop\ML Syllabus\Play Tennis.csv")
df

# Encode categorical values
label_encoder = preprocessing.LabelEncoder()
df = df.apply(label_encoder.fit_transform)

# Feature selection
feature_cols = ['Outlook', 'Temprature', 'Humidity', 'Wind']
X = df[feature_cols]
y = df.Play_Tennis

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.30)

# Create and train model
classifier = DecisionTreeClassifier(criterion="entropy", random_state=100)
classifier.fit(X_train, y_train)

# Prediction
y_pred = classifier.predict(X_test)

# Accuracy
print("Accuracy:", accuracy_score(y_test, y_pred))

# Actual vs Predicted
data_p = pd.DataFrame({'Actual': y_test, 'Predicted': y_pred})
print(data_p)

# Evaluation metrics
print(confusion_matrix(y_test, y_pred))
print(classification_report(y_test, y_pred))
