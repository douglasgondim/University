import time
import random

def intercalate(array, i, m, n):
    beginning = i
    j = m + 1
    final_array = []
    while(i <= m and j <= n):
        if(array[i] < array[j]):
            final_array.append(array[i])
            i += 1
        else:
            final_array.append(array[j])
            j += 1
    
    while( i <= m):
        final_array.append(array[i])
        i += 1

    while(j <= n):
        final_array.append(array[j])
        j += 1

    array[beginning:n+1] = final_array



def mergeSortRec(array, i, j):
    if(i == j): return
    k = int((i+j)/2)
    mergeSortRec(array, i, k)
    mergeSortRec(array, k+1, j)
    intercalate(array, i, k, j)


# array = [random.randint(1,1000) for _ in range(1000)]

# start_time = time.clock()

# mergeSortRec(array, 0, len(array)-1)
# # array.sort()

# print(time.clock() - start_time, "seconds")
# print(array)
