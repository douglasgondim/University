from time import perf_counter
import random

def findMatch(array, i, j):
    if(i > j): return "Not found!"
    if(array[i] == i): return i
    if(array[j] == j): return j
    if(array[i] > i and array[j] < j): return findMatch(array, array[i], array[j])
    if(array[i] < i and array[j] > j): return findMatch(array, i+1, j-1)
    if(array[i] > i): return findMatch(array, array[i], j-1)
    if(array[j] < j): return findMatch(array, i+1, array[j])

def interactiveFindMatch(array):
    i =0
    j = len(array)-1
    while(i <= j):
        if(array[i] == i): return i
        elif(array[j] == j): return j
        elif(array[i] > i and array[j] < j):
            i = array[i]
            j = array[j]
        elif(array[i] < i and array[j] > j):
            i += 1
            j -= 1
        elif(array[i] > i):
            i = array[i]
            j -= 1
        elif(array[j] < j):
            i += 1
            j = array[j]
    return "Not Found!"


def findMatch2(array):
    for i in range(len(array)):
        if(array[i] == i): return i
    return "Not found!"

# array = [1,2,3,4,4,15,15,15]

array = [random.randint(0, 1000000) for _ in range(1000000)]

array.sort()
colisao = 0
# for i in range(len(array)):
#     if(array[i] == i):
#         colisao +=1

for i in range(len(array)):
    if(array[i] == i and (i < 400000 or i > 600000 or colisao > 0) ):
        array[i] += 1
    elif(array[i] == i and i > 400000 and i < 600000 and colisao == 0):
        colisao += 1 


# array = []
# for i in range(100000000):
#     array.append(i+1)
# array[99999999] = 99999999

start_time = perf_counter()
# print(interactiveFindMatch(array))
print(findMatch2(array))
# print(findMatch(array,0,len(array)-1))
print(perf_counter() - start_time, "seconds")

start_time = perf_counter()
print(interactiveFindMatch(array))
# print(findMatch2(array))
# print(findMatch(array,0,len(array)-1))
print(perf_counter() - start_time, "seconds")