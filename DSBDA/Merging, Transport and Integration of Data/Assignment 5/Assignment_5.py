#import pandas
import pandas as pd

#import matplotlib
import matplotlib.pyplot as plt

#reading the file(facebook dataset)
data = pd.read_csv("fb.csv",sep=';')

#printing the top line from file
print("-----------------HEAD--------------------")
print(data.head())

#printing the description of file
print("------------------DESC--------------------")
print(data.describe())

#sorting the data 
sorted_data = data.sort_values(by=['share'])
print("-------------SORTED DATA----------------")
print(sorted_data.head())

#printing specific 'columns'
print("-----------SUBSET (TYPE, COMMENT, LIKE, SHARE)--------")
sub1 = data[['Type','comment','like','share']]
print(sub1.head())

#printing the data with like >100 
print("------------SUBSET (TYPE, COMMENT, LIKE, SHARE) WITH CONDTION AT LEAST 100 LIKES-------")
sub2 = sub1[sub1.like>100]
print(sub2)

#printing the data with like>50 and comment>50 and share>50
print("----------SUBSET (TYPE, COMMENT, LIKE, SHARE) WITH CONDTION AT LEAST 50 LIKES COMMENTS AND SHARES--------")
sub3 = sub1[(sub1.like>50)&(sub1.comment>50)&(sub1.share>50)]
print(sub3)

#print the addition of likes,comments and shares
print("-----------------------------SUBSET (TYPE, COMMENT, LIKE, SHARE) SUM----------------------------")
sub4 = [sub1.like.sum(),sub1.comment.sum(),sub1.share.sum()]
print(sub4)

#PLOT SHOWING TOTAL NUMBER OF LIKES COMMENTS AND SHRARES
title = ["like","comment","share"]
plt.bar(title,sub4)
plt.gcf().canvas.set_window_title('LIKES VS. COMMENTS VS. SHARES')
plt.show()


#PLOT HISTOGRAM OF COMMENTS
hist = plt.hist(data['comment'],bins=30)
plt.gcf().canvas.set_window_title('HISTOGRAM FOR COMMENTS')
plt.show(hist)


#PLOT SCATTER OF CATEGORY VS LIKES
graph = plt.scatter(data['Type'],data['comment'])
plt.xlabel('category')
plt.ylabel('comments')
plt.gcf().canvas.set_window_title('TYPE VS. COMMENTS [SCATTER PLOT]')
plt.show(graph)

#PLOT SCATTER OF CATEGORY VS TOTAL INTERACTIONS
graph = plt.scatter(data['Type'],data['Total Interactions'])
plt.xlabel('category')
plt.ylabel('interactions')
plt.gcf().canvas.set_window_title('TYPE VS. INTERACTIONS [SCATTER PLOT]')
plt.show(graph)


#PLOT SCATTER OF PAID VS TYPE
graph = plt.scatter(data['Paid'],data['Type'])
plt.xlabel('Paid')
plt.ylabel('Type')
plt.gcf().canvas.set_window_title('PAID VS. TYPE [SCATTER PLOT]')
plt.show(graph)