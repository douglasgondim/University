def troca(A, i, j):
    aux = A[i]
    A[i] = A[j]
    A[j] = aux

def ordenaIndex(A, n, j):
    while(j < n and A[j] >= A[j+1]):
        troca(A, j, j+1)
        j += 1

def intercalaInplace(A, n):
    i = 0
    j = int(n/2)+1

    while(i < j):
        if(A[i] <= A[j]):
            i += 1
        else:
            troca(A, i, j)
            ordenaIndex(A, n, j)
            i += 1
B = [2,6,10,12,20,45,147]
C = [3,4,9,11,20,200]

A = B + C

print('Desordenado: ', A)
intercalaInplace(A, len(A)-1)
print('Ordenado: ', A)


