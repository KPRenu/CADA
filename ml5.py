import numpy as np
import pandas as pd
from sklearn import preprocessing
from sklearn.tree import DecisionTreeRegressor

df = pd.read_csv(r"C:\Users\HPR\Desktop\ML Syllabus\Play_Tennis_reg.csv")
df

X = df.drop("Golf Players", axis=1)
y = df["Golf Players"]

le = preprocessing.LabelEncoder()
X = X.apply(le.fit_transform)

reg = DecisionTreeRegressor()
reg.fit(X, y)

print("Result is:", reg.predict([[2, 1, 0, 1]]))
print("Result is:", reg.predict([[2, 1, 0, 0]]))
print("Result is:", reg.predict([[1, 2, 0, 0]]))
