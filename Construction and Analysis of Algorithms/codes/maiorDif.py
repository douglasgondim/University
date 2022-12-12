def maiorDif(array, i, j):
    if(i >= j): return -100
    if(j == i+1): return abs(array[i]-array[j])
    k = int(((j-1)/2))
    # print(k)
    return max(maiorDif(array, i, k), maiorDif(array, k+1, j))

def finalComp(array, i, j):
    dif = maiorDif(array, i, j)
    k = int(((j-1)/2))
    menor= array[0]
    maior = array[k]

    for r in range(0, k+1):
        if(array[r] < menor):
            menor = array[r]
    for r in range(k+1, j+1):
        if(array[r] > maior):
            maior = array[r]

    return max(dif, abs(maior-menor))




# def maxdif(array, i, j):
#     k = (j-1/2)

array = [1,2,4,3,10]

print(finalComp(array, 0, len(array)-1))
# print(max(1,-100))
