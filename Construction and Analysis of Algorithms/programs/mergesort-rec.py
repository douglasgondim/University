def mergeArrays(array_1, array_2):
    final_array = []

    while array_1 or array_2:  #enquanto tiver elementos nos array 1 ou 2
        if not array_1:        # se o array 1 estiver vazio
            while array_2:     # enquanto tiver elementos no array 2
                final_array.append(array_2[0])  #adiciona primeiro elemento do array 2 no array final
                array_2.pop(0)                  # remove primeiro elemento do array 2
        elif not array_2:                       # se o array 2 estiver vazio
            while array_1:                      # enquanto tiver elementos no array 1
                final_array.append(array_1[0])  # adicional primeiro elemento do array 1 no array final
                array_1.pop(0)                  # remove primeiro elemento do array 1
        else:
            while (array_1 and array_2) and array_1[0] <= array_2[0]: # enquanto o 1º elemento do array 1 for menor que o 1º do array 2
                final_array.append(array_1[0])
                array_1.pop(0)
            while (array_1 and array_2) and array_2[0] <= array_1[0]:
                final_array.append(array_2[0])
                array_2.pop(0)
    

    return final_array   # retorna array final intercalado

                


def mergeSort(array):
    if len(array) == 1:  # se o tamanho do array for 1
        return array     
    array_1 = array[:len(array)//2] # primeira metade do array
    array_2 = array[len(array)//2:] # segunda metade do array
    return mergeArrays(mergeSort(array_1), mergeSort(array_2))

    


array = [5,6,4,1,2,12,10,100,20, 13, -5, -6, -2]

print("Original array:")
print(array)
print("Ordered array:")
print(mergeSort(array))

