#!/usr/bin/python
import matplotlib.pyplot as graph_plot
import csv

x = []
y = []

with open('calculation.dat','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=':')
    for line in plots:
        x.append(int(line[0]))
        y.append(int(line[1]))

graph_plot.plot(x,y, label='calculation.dat')
graph_plot.xlabel('Power of 2')
graph_plot.ylabel('Time taken')
graph_plot.title('Cache size vs Time')
graph_plot.legend()
graph_plot.show()
