import time
import random

def intercalate(array, start, middle, end):
    beginning = start
    j = middle + 1
    # final_array = []
    while(start <= middle and j <= end):
        if(array[start] > array[j]):
            aux = array[end]
            array[end] = array[start]
            array[start] = aux
            # final_array.append(array[start])
            start += 1
        else:
            aux
            # final_array.append(array[j])
            j += 1
    
    while( start <= middle):
        final_array.append(array[start])
        start += 1

    while(j <= end):
        final_array.append(array[j])
        j += 1

    array[beginning:end+1] = final_array



def mergeSortRec(array, i, j):
    if(i == j): return
    k = int((i+j)/2)
    mergeSortRec(array, i, k)
    mergeSortRec(array, k+1, j)
    intercalate(array, i, k, j)
    


array = [random.randint(0,2) for _ in range(1000000)]

start_time = time.clock()

mergeSortRec(array, 0, len(array)-1)

print(time.clock() - start_time, "seconds")
# print(array)
