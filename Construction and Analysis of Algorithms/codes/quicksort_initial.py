def partition(array):
    j = 1
    k = len(array)-1
    pivot = array[0]
    while(j <= k):
        if(array[j] > pivot and array[k] <= pivot):
            aux = array[k]
            array[k] = array[j]
            array[j] = aux
        if(array[j] <= pivot):
            j += 1
        if(array[k] > pivot):
            k -= 1
    aux = array[0]
    array[0] = array[k]
    array[k] = aux
    return k



def quicksort(array, start, end):
    if len(array) <=1:
        return

    p = partition(array)
    quicksort(array[start:p-1], start, p-1)
    quicksort(array[p+1:end],p+1, end)


array = [5,3,4,10,20,1,2,26]

# print(partition(array))
# print(array)

quicksort(array, 0, len(array)-1)
print(array)
