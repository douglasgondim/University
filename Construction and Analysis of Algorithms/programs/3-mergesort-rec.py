def mergeArrays(array_1, array_2, array_3):
    final_array = []

    while array_1 or array_2 or array_3:
        if not (array_1 or array_3):
            while array_2:
                final_array.append(array_2[0])
                array_2.pop(0)
        elif not (array_2 or array_3):
            while array_1:
                final_array.append(array_1[0])
                array_1.pop(0)
        elif not (array_1 or array_2):
            while array_3:
                final_array.append(array_3[0])
                array_3.pop(0)
                
        else:
            while (array_1 and array_2) and (not array_3) and array_1[0] <= array_2[0]:
                final_array.append(array_1[0])
                array_1.pop(0)
            while (array_1 and array_2) and (not array_3) and array_2[0] <= array_1[0]:
                final_array.append(array_2[0])
                array_2.pop(0)

            while (array_1 and array_3) and (not array_2) and array_1[0] <= array_3[0]:
                final_array.append(array_1[0])
                array_1.pop(0)
            while (array_1 and array_3) and (not array_2) and array_3[0] <= array_1[0]:
                final_array.append(array_3[0])
                array_3.pop(0)

            while (array_2 and array_3) and (not array_1) and array_2[0] <= array_3[0]:
                final_array.append(array_2[0])
                array_2.pop(0)
            while (array_2 and array_3) and (not array_1) and array_3[0] <= array_2[0]:
                final_array.append(array_3[0])
                array_3.pop(0)


            while(array_1 and array_2 and array_3 and array_1[0] <= array_2[0] and array_1[0] <= array_3[0]):
                final_array.append(array_1[0])
                array_1.pop(0)
            while ( array_1 and array_2 and array_3 and array_2[0] <= array_1[0] and array_2[0] <= array_3[0]):
                final_array.append(array_2[0])
                array_2.pop(0)
            while (array_1 and array_2 and array_3 and array_3[0] <= array_1[0] and array_3[0] <= array_2[0]):
                final_array.append(array_3[0])
                array_3.pop(0)          
    

    return final_array

                


def mergeSort(array):
    if len(array) <= 1:
        return array
        
    if len(array) == 2:
        array_1 = [array[0]]
        array_2 = [array[1]]
        array_3 = []
    else:
        array_1 = array[:len(array)//3]
        array_2 = array[len(array)//3:(len(array)//3)*2]
        array_3 = array[(len(array)//3)*2:]
    return mergeArrays(mergeSort(array_1), mergeSort(array_2), mergeSort(array_3))

    


array = [6,5, 9, -5]

print(mergeSort(array))




# array_1 = array[:len(array)//3]
# array_2 = array[len(array)//3:(len(array)//3)*2]
# array_3 = array[(len(array)//3)*2:]


# print(array_1)
# print(array_2)
# print(array_3)


