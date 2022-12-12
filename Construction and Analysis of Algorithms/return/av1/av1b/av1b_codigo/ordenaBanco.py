import mergesort as m
import random, math

# função flip do algoritmo panqueca
def flip(array, flipPos):
    array[:] = array[flipPos::-1]  + array[flipPos+1:]

def acharSegmentos(bdUFC):
    i = 0
    segmentos = []

    while(i < len(bdUFC)):
        aux_array = [bdUFC[i]]
        if(i < len(bdUFC)-1 and bdUFC[i] + 1 == bdUFC[i+1]):
            while(i < len(bdUFC)-1 and bdUFC[i] + 1 == bdUFC[i+1]):
                aux_array.append(bdUFC[i+1])
                i += 1

        elif(i < len(bdUFC)-1 and bdUFC[i] - 1 == bdUFC[i+1] ):
            while(i < len(bdUFC)-1 and bdUFC[i] - 1 == bdUFC[i+1]):
                aux_array.append(bdUFC[i+1])
                i += 1
            aux_array = aux_array[::-1]

        i += 1
        segmentos.append(aux_array)
        aux_array = []
    return segmentos

def ordenaBD(bdUFC):
    segmentos = acharSegmentos(bdUFC)
    m.mergeSortRec(segmentos, 0, len(segmentos)-1)
    
    k = 0
    for i in range(0, len(segmentos)):
        for j in range(0, len(segmentos[i])):
            bdUFC[k] = segmentos[i][j]
            k += 1


arrayPanqueca = []
n = 10

# cria array ordenado de tamanho n
for i in range(n):
    arrayPanqueca.append(i)
    
# realiza raiz de n flips
for i in range(int(math.sqrt(n))):
    flip(arrayPanqueca, random.randint(0, len(arrayPanqueca)-1))

print(arrayPanqueca)
ordenaBD(arrayPanqueca)
print(arrayPanqueca)
