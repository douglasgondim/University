# intercalation

def intercalate(array, maxOFArray):
    i = 0
    j = int (len(array)/2)
    k = 0


    while(i < int (len(array)/2) and j < len(array)):
        if(array[i] <= array[j]):
            if( i-k ==0):
                i = i + 1
            else:
                array[k] = array[k] + array[i] * maxOFArray
                k = k + 1
                # i = i + 1
                array[i] = array[j]
                j = j + 1
        else:
            array[k] = array[k] + array[j] * maxOFArray
            k = k + 1
            j = j + 1

    while(i < int (len(array)/2)):
        array[k] = array[k] * maxOFArray
        i = i + 1
        k = k + 1
    while(j < int (len(array))):
        array[k] = array[k] + array[j] * maxOFArray
        j = j + 1
        k = k + 1

    i = int (len(array)/2)-1
    j = int (len(array))-1
    # for i in range(int (len(array)/2)-1, -1,-1):
    #     array[j] = int(array[i]/maxOFArray)
    #     array[j-1] = array[i]%maxOFArray
    #     # print(array[i]%maxOFArray)
    #     j = j - 2

    return array


# def mergeSort(array, maxOFArray):
#     if (len(array) == 1): return array
#     return intercalate(mergeSort(array[:len(array)//2]), mergeSort(array[len(array)//2:]))



array = [5,6,1,7,8,-5,-6,15,12,100,14,3,4]
array_2 = [1,4,5]

maxOFArray = array_2[0]
for i in array_2:
    if(i > maxOFArray):
        maxOFArray = i


print(intercalate(array_2, maxOFArray))
# for i in range(0,-1,-1):
    # print(i)




