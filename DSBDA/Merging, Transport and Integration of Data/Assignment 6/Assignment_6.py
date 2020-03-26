#import pandas
import pandas as pd
import numpy as np
#import matplotlib
import matplotlib.pyplot as plt

data = pd.read_csv("fb.csv",sep=';')

#PRINT HEADER LINES
print("\n-----------------------------HEAD----------------------------")
print(data.head())

#PRINT LAST LINES
print("\n-----------------------------LAST----------------------------")
print(data.tail(5))

#PRINT DESCRIPTION
print("\n-----------------------------DESC----------------------------")
print(data.describe())

#PRINTING  COLUMN NAMES
print("\n--------------------COLUMNS NAMES----------------------------")
for col in data.columns:
	print(col)


#------------------------------------CLEANING OF DATA---------------------------- 

print("\n----------------------CLEANING OF DATA---------------------------")
#DROP SPECIFIC COLUMNS
print("\n--------------------DROP SPECIFIC COLUMNS---------------------------")
todrop = ['Paid', 'Lifetime Post Total Reach', 'Lifetime Post Total Impressions', 'Lifetime Engaged Users', 'Lifetime Post Consumers', 'Lifetime Post Consumptions', 'Lifetime Post Impressions by people who have liked your Page', 'Lifetime Post reach by people who like your Page', 'Lifetime People who have liked your Page and engaged with your post']
cleandata = data.drop(todrop, inplace=False,axis=1)
print(cleandata.head())

#CHECKING VALUES ARE NULL OR NOT
print("\n------------------CHECKING NULL VALUES OF 'Paid' COLUMN--------------------")
print(data['Paid'].isnull())



#---------------------------------DATA INTERGRATION------------------------------

print("\n----------------------DATA INTEGRATION---------------------------")
students = pd.read_csv("students.csv", header = 0)
marks = pd.read_csv("marks.csv", header = 0)

#PRINT HEADER LINES
print("\n-----------------------------HEAD----------------------------")
print(students.head())

#PRINT LAST LINES
print("\n-----------------------------LAST----------------------------")
print(marks.tail(5))

#MERGING BASED ON COMMON COLUMN 'Student_id'
print("\n-------------------------MERGING TWO DATASETS-------------------")
df = pd.merge(students, marks, on = 'Student_id')
print(df.head(10))

#--------------------------DATA TRANSFORMATION--------------------------------------

#CATEGORICAL COLUMNS OF DATAFRAMES
print("\n-------------CATEGORICAL COLUMNS OF DATAFRAMES---------------")
df_categorical = df.select_dtypes(exclude=[np.number])
print(df_categorical)

#UNIQUE VALUES IN GRADE COLUMN
print("\n-------------UNIQUE VALUES IN GRADE COLUMN---------------")
print(df_categorical['Grade'].unique())

#TOTAL VALUES COUNT IN GRADE COLUMN
print("\n-------------TOTAL VALUES COUNT IN GRADE COLUMN---------------")
print(df_categorical.Grade.value_counts())

#GENDER VALUES COUNT
print("\n-------------GENDER VALUES COUNT---------------")
print(df_categorical.Gender.value_counts())

#DROP THE COLUMNS WITH NA
print("\n--------------DROP THE COLUMNS WITH NA--------------")
data.dropna()
print(data.head())

#DROP THE COLUMNS WITH ALL HAVE NA VALUES 
print("\n--------------DROP THE COLUMNS WITH ALL HAVE NA VALUES--------------")
data.dropna(axis=1)
print(data.head())

#MAKE COLUMN TEXT TO UPPERCASE
print("------------------MAKE COLUMN TEXT TO UPPERCASE--------------------")
#students[‘Gender’].str.upper()
print(students.head())
