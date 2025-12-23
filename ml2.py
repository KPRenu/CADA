import pandas as pd
import numpy as np

data = pd.read_csv(r"C:\Users\HPR\Desktop\ML Syllabus\2.csv")
concepts = np.array(data.iloc[:, 0:-1])
target   = np.array(data.iloc[:, -1])

def learn(concepts, target):
    n_attrs = concepts.shape[1]

    specific_h = None
    for i, cls in enumerate(target):
        if cls.lower() == "yes":
            specific_h = concepts[i].copy()
            break
    if specific_h is None:
        raise ValueError("No positive examples found.")

    print("initialization of specific_h \n", specific_h)

    general_h = [["?" for _ in range(n_attrs)] for _ in range(n_attrs)]
    print("initialization of general_h \n", general_h)

    for i, h in enumerate(concepts):
        if target[i].lower() == "yes":
            print("If instance is Positive ")
            for x in range(n_attrs):
                if h[x] != specific_h[x]:
                    specific_h[x] = "?"
                    general_h[x][x] = "?"
        elif target[i].lower() == "no":
            print("If instance is Negative ")
            for x in range(n_attrs):
                if h[x] != specific_h[x]:
                    general_h[x][x] = specific_h[x]
                else:
                    general_h[x][x] = "?"

        print(f" step {i+1}")
        print(specific_h)
        print(general_h)
        print("\n")

    all_q = ["?"] * n_attrs
    general_h = [gh for gh in general_h if gh != all_q]

    return specific_h, general_h

s_final, g_final = learn(concepts, target)
print("Final Specific_h:", s_final, sep="\n")
print("Final General_h:", g_final, sep="\n")
