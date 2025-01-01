"""
This script reads execution time data from a CSV file and plots a time complexity graph.
Functions:
    - Reads data from 'dataSheet.csv' using pandas.
    - Plots the data using matplotlib with input size on the x-axis and execution time on the y-axis.
    - Sets the x-axis to a logarithmic scale.
    - Adds a title, labels, and grid to the plot.
    - Displays the plot.
    - pandas as pd
    - matplotlib.pyplot as mpl
"""
# Import necessary libraries
import pandas as pd
import matplotlib.pyplot as mpl

df = pd.read_csv('dataSheet.csv')
mpl.plot(df['Input_Size'], df['Exec_Time'], marker='.')
mpl.title('Time Complexity Analysis of the provided Algorithm')
mpl.xlabel('Input Size')
mpl.ylabel('Execution Time')
mpl.xscale('log')

mpl.grid(True)
mpl.show()
