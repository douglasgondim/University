import time
import random

def intercalate(array, start, middle, end):
    beginning = start
    j = middle + 1
    final_array = []
    while(start <= middle and j <= end):
        if(array[start] < array[j]):
            final_array.append(array[start])
            start += 1
        else:
            final_array.append(array[j])
            j += 1
    while( start <= middle):
        final_array.append(array[start])
        start += 1

    while(j <= end):

        final_array.append(array[j])
        j += 1

    # w = 0
    # for i in range(start, n+1):
    #     array[i] = final_array[w]
    #     w += 1
    array[beginning:end+1] = final_array

def contaInversao(array, array2, i, j,):
    cont = 0
    for i in range(j+1):
        aux = array2.index(array[i])
        if(aux-i > 0):
            cont += aux-i
    return cont

def totalInversoes(array, i, j):
    if(i == j): return
    k = int((i+j)/2)
    totalInversoes(array, i, k)
    totalInversoes(array, k+1, j)
    intercalate(array, i, k, j)
    if(i + j == len(array)-1):
        return contaInversao(array,array2, i, j )

    # intercalate(intercalate(i, 0, len(i)//2, len(i)-1), intercalate(k+1, 0, len(k+1)//2, len(k+1)-1))  


# array = [random.randint(1,100000000) for _ in range(100000000)]

# start_time = time.clock()
array1 = [10,9,8,1]
array2 = []
for i in range(len(array1)):
    array2.append(array1[i])


print(totalInversoes(array1, 0, len(array1)-1))
# array1.sort()

# print(time.clock() - start_time, "seconds")
# print(array1)

