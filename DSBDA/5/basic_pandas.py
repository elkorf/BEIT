import matplotlib.pyplot as plt
import pandas as pd

read_file = pd.read_csv("dataset.csv")
print(read_file)

read_file.drop(columns='name', inplace=True)
print(read_file)
read_file = get_dtype_counts()
