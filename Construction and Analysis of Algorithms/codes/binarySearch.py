import time
import random

def binarySearch(array, i, n, x):
    if(i > n): return "x not found"
    k = (i+n)//2
    if(x == array[k]): return k
    elif(x < array[k]): return binarySearch(array, i, k-1, x)
    elif(x > array[k]): return binarySearch(array, k+1, n, x)
    
def search(array, x):
    for (index, i) in enumerate(array):
        if (i == x): return index
    return "x not found"

array = []
for i in range(1000000000):
    array.append(i)


# start_time = time.clock()

# search(array, 99999999)

# print(time.clock() - start_time, "seconds")

start_time = time.clock()

binarySearch(array, 0, len(array)-1, 99999999)

print(time.clock() - start_time, "seconds")