def conjuntos(problema):
    if(len(problema) == 0): return []
    e = escolheMaior(problema)
    problemaMenor = simplifica(problema, e)
    s = conjuntos(problemaMenor)
    solucao = soluciona(s, e)
    return solucao


def soluciona(s, e):
    soma1 = 0
    for i in range(len(s[0])):
        soma1 += s[0][i]
    
    soma2 = 0
    for i in range(len(s[1])):
        soma2 += s[1][i]

    if(soma1 < soma2):
        return s[0] + e
    else:
        return s[1] + e


def escolheMaior(array):
    bigger = array[0]
    for i in range(len(array)):
        if(array[i] > bigger):
            bigger = array[i]
    return bigger

def simplifica(array, e):
    array.remove(e)
    return array


array = [2, 4, 6, 8]

print(escolheMaior(array))

# print(conjuntos(array))
# print(simplifica(array, 2))

# array2 = [ [2,4], [3,7]]

# print(soluciona(array2, 9))

