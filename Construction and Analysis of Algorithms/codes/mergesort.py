import time
import random

def intercalate(array_1, array_2):
    i = 0
    j = 0
    final_array = []
    while(i < len(array_1) and j < len(array_2)):
        if(array_1[i] < array_2[j]):
            final_array.append(array_1[i])
            i = i + 1
        else:
            final_array.append(array_2[j])
            j = j + 1
    
    while( i < len(array_1)):
        final_array.append(array_1[i])
        i = i + 1

    while(j < len(array_2)):
        final_array.append(array_2[j])
        j = j + 1

    return final_array



def mergeSortRec(array):
    if(len(array) == 1): return array
    k = len(array)//2
    array_1 = array[:k]
    array_2 = array[k:]
    return intercalate(mergeSortRec(array_1), mergeSortRec(array_2))

array = [random.randint(1,10000) for _ in range(1000)]

start_time = time.clock()

print(mergeSortRec(array))

print(time.clock() - start_time, "seconds")
