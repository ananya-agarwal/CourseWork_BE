#importing all the necessary libraries
from matplotlib import pyplot as plt
from scipy.stats import norm
import statistics
import numpy as np
import pandas as pd
import seaborn as sea
import sys

#remove warnings
from os import environ

def suppress_qt_warnings():
    environ["QT_DEVICE_PIXEL_RATIO"] = "0"
    environ["QT_AUTO_SCREEN_SCALE_FACTOR"] = "1"
    environ["QT_SCREEN_SCALE_FACTORS"] = "1"
    environ["QT_SCALE_FACTOR"] = "1"

if __name__ == "__main__":
    suppress_qt_warnings()

#read the output file of the first program
df1 = pd.read_csv(sys.argv[1])

#Total-of-all column
df1["Total-of-all"] = df1.sum(axis=1)

#histogram chart b/w Count of P1 VS P1
plt.hist(df1['P1'])
plt.title('Count of P1 Vs P1')
plt.xlabel('P1')
plt.ylabel('Count of P1')
plt.savefig('102083036-histogram_P1-count.png')
plt.close()

#histogram chart b/w Count of P3 VS P3
plt.hist(df1['P3'])
plt.title('Count Vs P3')
plt.xlabel('P3')
plt.ylabel('Count of P3')
plt.savefig('102083036-histogram_P3-count.png')
plt.close()

#line chart b/w Submissions and their Standard Deviation
sd = df1[['P1','P2','P3','P4','P5']].std()
sd.to_list()
xval = ['P1','P2','P3','P4','P5']

plt.plot(xval, sd, marker = 'o', color='cyan')
plt.ylim(0, 10)
plt.title('Standard Deviation VS Submissions')
plt.xlabel('Submissions')
plt.ylabel('Standard Deviation')

plt.savefig('102083036-line.png')
plt.close()

#pie chart b/w Submissions and their mean
meanList = df1[['P1','P2','P3','P4','P5']].mean()
meanList.to_list()

fig = plt.figure()
labels = ['P1','P2','P3','P4','P5']
myexplode = [0.05, 0.05, 0.05, 0.05, 0.05]
mycolors = ["green", "hotpink", "cyan", "red", "yellow"]
plt.pie(meanList[0:5], labels=labels, explode = myexplode, colors = mycolors)
plt.legend(title = "Submissions", loc ="lower left")

plt.savefig('102083036-pie-mean.png')
plt.close()

#pie chart b/w Submissions and their count
s1 = df1[['P1','P2','P3','P4','P5','Total-of-all']].sum()
s1.to_list()

fig = plt.figure()
labels = ['P1','P2','P3','P4','P5']
myexplode = [0.05, 0.05, 0.05, 0.05, 0.05]
mycolors = ["green", "hotpink", "cyan", "red", "yellow"]
plt.pie(s1[0:5], labels=labels, explode = myexplode, colors = mycolors)
plt.legend(title = "Submissions", loc ="lower left")

plt.savefig('102083036-pie-count.png')
plt.close()

#graph1 (scatter plot):
medianList = df1[['P1','P2','P3','P4','P5']].median()
medianList.to_list()

plt.scatter(labels, medianList, c="red",linewidth=3,marker="s",edgecolor="green",s=100)
plt.xlabel("Submissions")
plt.ylabel("Median")

plt.savefig('102083036-graph1_Scatter.png')
plt.close()


#graph2 (distribution graph):
fig, axs = plt.subplots(2, 3, figsize = (10,5))
fig.suptitle("Density Plots")
k = 0
for i in range(2):
    for j in range(3):
        k += 1
        sea.kdeplot(ax = axs[i,j], data = df1.iloc[:, k], linewidth = 3)
        axs[i, j].set_title(f"Density Plot for {df1.columns[k]}")
        axs[i, j].set(xlabel = f"Marks in {df1.columns[k]}", ylabel = "Density")
fig.tight_layout(pad = 3.0)

plt.savefig("102083036-graph2_distribution.png", facecolor = "w", edgecolor = "b")
plt.close()