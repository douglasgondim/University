def order(array):
    i = 0
    j = 0
    k = 0
    aux_arr = array[:]
    for r in range(0, len(array)):
        if(array[r] == -1):
            j += 1
    for k in range(0, len(array)):
        if(array[k] == -1):
            aux_arr[i] = array[k]
            i += 1
        else:
            aux_arr[j] = array[k]
            j += 1
    return aux_arr

array = [1,-1,1,-1]

print(order(array))


   
