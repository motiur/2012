#Download pylab from http://sourceforge.net/projects/matplotlib/files/matplotlib/matplotlib-1.1.0/
#Download numpy from http://sourceforge.net/projects/numpy/files/NumPy/

import pylab 
from numpy import *
import random
import datetime
import matplotlib.dates

number = int(raw_input("Enter a value around 5000: "))
#print number


#Insertion Sort ------------------------------>
arr = []
for i in range(0, number):
  arr.append( random.randrange(0,number))



def insertionsort(arr):

  for j in range(2,len(arr)):

    key = arr[j]

    i = j - 1
    
    while ( i > 0 ) and (arr [i] > key):

      arr[i+1] = arr[i]

      i = i -1

    arr[i+1] = key

  return arr




#Merge sort ------------------------------------>

arr2 = []
for i in range(0, number):
  arr2.append( random.randrange(0,number))

arr3 = []
for i in range(0, number):
  arr3.append( random.randrange(0,number))


def merge(left,right):

  result = []

  i, j = 0,0

  while i < len(left) and j < len(right):

    if left[i] <= right[j]:

      result.append(left[i])

      i = i + 1

    else:

      result.append(right[j])

      j = j + 1

  while ( i < len(left)):

    result.append(left[i])

    i = i + 1

  while ( j < len(right)):

    result.append(right[j])

    j = j + 1

  return result


def improvedmergesort(arr):

  #print arr

  if len(arr) < 2 : return arr[:]
  if len(arr)<= 44:

    return insertionsort(arr)


  else:

    middle = (len(arr) / 2)

    left = improvedmergesort(arr[:middle])

    right = improvedmergesort(arr[middle:])

    together = merge(left,right)

    return together



def normalmergesort(arr):

  #print arr

  if len(arr) < 2 : return arr[:]
  else:

    middle = (len(arr) / 2)

    left = normalmergesort(arr[:middle])

    right = normalmergesort(arr[middle:])

    together = merge(left,right)

    return together
      

#calling function
m1 = matplotlib.dates.date2num(datetime.datetime.now())

improvedmergesort(arr2)

m2 = matplotlib.dates.date2num(datetime.datetime.now())

nm1 = matplotlib.dates.date2num(datetime.datetime.now())

normalmergesort(arr3)

nm2 = matplotlib.dates.date2num(datetime.datetime.now())

i1 = matplotlib.dates.date2num(datetime.datetime.now())

insertionsort(arr)

i2 = matplotlib.dates.date2num(datetime.datetime.now())

time1 = (i2-i1)
time2 = (m2 - m1)
time3 = (nm2 - nm1)
print "insertionsort:",time1,"sec"
print "improvedmergesort:",time2,"sec"
print "normalmergesort:",time3,"sec"

#Visualization---------------------->
#N.B-- This visualization would have worked ,
#but the execution time is slow to be displayed
#accurately.


##import numpy as np
##import matplotlib.pyplot as plt
##
##
##
##fig = plt.figure()
##ax = fig.add_subplot(111)
##ax.plot(['0',number],['0',time1],'y--',['0',number],['0',time2],'r--',['0',number],['0',time3],'g--')
##leg = ax.legend(('Insertion Sort','Improvedmergesort','Normal merge Sort'),
##           'upper center', shadow=True)
##ax.grid(True)
##ax.set_xlabel('Number of values*1000------>')
##ax.set_ylabel('Time in log------>')
##ax.set_ybound(0,10000000*time2)
##ax.set_xbound(0,50)
##ax.set_title('Complexity')
##
##plt.show()
##
