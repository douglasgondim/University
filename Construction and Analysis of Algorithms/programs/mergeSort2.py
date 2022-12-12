# intercalation

def intercalate(array_1, array_2):
    i = 0
    j = 0
    new_array = []

    while(i < len(array_1) and j < len(array_2)):
        if(array_1[i] <= array_2[j]):
            new_array.append(array_1[i])
            i = i + 1
        else:
            new_array.append(array_2[j])
            j = j + 1

    while(i < len(array_1)):
        new_array.append(array_1[i])
        i = i + 1
    while(j < len(array_2)):
        new_array.append(array_2[j])
        j = j + 1

    array = new_array
    return array


def mergeSort(array):
    if (len(array) == 1): return array
    return intercalate(mergeSort(array[:len(array)//2]), mergeSort(array[len(array)//2:]))



array = [5,6,1,7,8,-5,-6,15,12,100,14,3,4]
print(mergeSort(array))





