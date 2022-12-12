# array = [0,3,1,6,5,2,4]

def ordPermutation(array):
    i = 0
    while(i < len(array)-1):
        if(array[i] != i):
            aux = array[array[i]]
            array[array[i]] = array[i]
            array[i] = aux
            print(array)
        else:
            i = i + 1
            
    return array


# print(array)
# ordPermutation(array)

array = [1,2,3,0]

def ordPermutation2(array):
    i = 0
    while(i < len(array)):
        if(array[i] != i and  int(array[i]/2) != i):
            if(array[i] < len(array)):
                posicao = array[i]
            else:
                posicao = int (array[i]/2)

            if(array[posicao] != 2*posicao + 1):
                if(array[posicao] != posicao +1 and array[posicao] > array[i]):
                    aux = array[posicao]
                    array[posicao] = array[i]
                    array[i] = aux
                else:
                    i = i + 1
            else:
                aux = array[posicao-1]
                array[posicao-1] = array[i]
                array[i] = aux
        else:
            i = i + 1
        # print(array)

    return array

print(ordPermutation2(array))

            