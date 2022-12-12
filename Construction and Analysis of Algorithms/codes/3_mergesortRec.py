def intercalate(array_1, array_2, array_3):
    i = 0
    j = 0
    k = 0
    final_array = []

    while(i < len(array_1) and j < len(array_2) and k < len(array_3)):
        if(array_1[i] < array_2[j] and array_1[i] < array_3[k]):
            final_array.append(array_1[i])
            i = i + 1
        elif(array_2[j] < array_1[i] and array_2[j] < array_3[k]):
            final_array.append(array_2[j])
            j = j + 1
        else:
            final_array.append(array_3[k])
            k = k + 1

    while(i < len(array_1) and j < len(array_2)):
        if(array_1[i] < array_2[j]):
            final_array.append(array_1[i])
            i = i + 1
        else:
            final_array.append(array_2[j])
            j = j + 1
    
    while(i < len(array_1) and k < len(array_3)):
        if(array_1[i] < array_3[k]):
            final_array.append(array_1[i])
            i = i + 1
        else:
            final_array.append(array_3[k])
            k = k + 1
    
    while(j < len(array_2) and k < len(array_3)):
        if(array_2[j] < array_3[k]):
            final_array.append(array_2[j])
            j = j + 1
        else:
            final_array.append(array_3[k])
            k = k + 1

    while(i < len(array_1)):
        final_array.append(array_1[i])
        i = i + 1

    while(j < len(array_2)):
        final_array.append(array_2[j])
        j = j + 1

    while(k < len(array_3)):
        final_array.append(array_3[k])
        k = k + 1
    
    return final_array


array_a = [1,4,7]
array_b = [2,5,8,20]
array_c = [3,6,9]

# print(intercalate(array_a, array_b, array_c))

def mergeSortRec3(array):
    if (len(array) <= 1): return array
    elif (len(array) == 2):
        array_1 = [array[0]]
        array_2 = [array[1]]
        array_3 = []
    else:
        array_1 = array[:len(array)//3]
        array_2 = array[len(array)//3:(len(array)//3)*2]
        array_3 = array[(len(array)//3)*2:]

    return intercalate(mergeSortRec3(array_1), mergeSortRec3(array_2), mergeSortRec3(array_3))

array = [ 1,-6,8,4,12,3,10]

print(mergeSortRec3(array))