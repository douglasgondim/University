def maiorSeq(array, i, j):
    if(i > j): return 0
    if(i == j): return array[i]
    k = int((i+j)/2)
    esq = maiorSeq(array, i, k)
    dirto = maiorSeq(array, k+1, j)
    if(j-i == tam):
        return max(somaNum(esq, dirto, i, j), somaDoMeio(array, i,j))
    return somaNum(esq, dirto, i, j)

def somaNum(esq, dirto, i, j):
    if(esq < 0):
        if(dirto > 0):
            return dirto
        return 0
    elif(dirto < 0):
        return 0
    elif(esq > 0 and dirto > 0 and  j-i == int(tam)):
        return max(dirto, esq)
    else:
        return dirto + esq

def somaDoMeio(array, i, j):
    k = int((i+j)/2)
    somaTotal = 0
    i = k
    while(i >=0 and array[i] >= 0 ):
        somaTotal += array[i]
        i -= 1
    
    i = k+1
    while(i <= tam and array[i] >= 0):
        somaTotal += array[i]
        i += 1
    return somaTotal




    

array=[1,-9,50,-49,2,60,-10,63]
tam = len(array)-1
print(maiorSeq(array, 0, len(array)-1))
# print(maiorSeq(array, 0, len(array)-1))

