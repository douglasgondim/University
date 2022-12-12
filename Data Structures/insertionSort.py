def insertionSort(array, m, n):
    for i in range(1, n+1):
        j = i
        while(j > 0 and array[j] < array[j-1]):
            aux = array[j-1]
            array[j-1] = array[j]
            array[j] = aux
            j -= 1

    return array

array = [4,1,9,8,7,5,6,12,-5,-4.6]

print(insertionSort(array, 0, len(array)-1))
# for i in range(1, 2):
#     print(i)