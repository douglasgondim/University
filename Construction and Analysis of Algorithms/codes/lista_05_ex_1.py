def order(array):
    len_array = len(array)
    aux_array = [ [] for j in range(2*len_array) ]
    for i in range(len_array):
        if(array[i] > 0 and array[i] <= 2*len_array):
            aux_array[array[i]-1].append(array[i])
    array = []
    for i in range(2*len_array):
        while(aux_array[i] != []):
            array.append(aux_array[i].pop(0))
    return array

array = [1,2,3,4,5,6]

print(order(array))
