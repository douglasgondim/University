import math

def dot(v1,v2):
    dp = 0.0 
    for i in range(len(v1)):
        dp += v1[i] * v2[i]
    return dp

def norm(v):
    return math.sqrt(dot(v, v))

def normalize(v):
    l = norm(v)
    aux = []
    for i in range(len(v)):
        aux.append(float(v[i])/float(l))
    return aux

def matrixVec(m, v):
    s = 0.0
    b = []
    for i in range(len(m)):
        s = 0
        for k in range(len(m)):
            s += m[i][k] * v[k]
        b.append(s)
    return b




def regularPower(A, v, eps):
    lambdaOld = lambdaNew = error = lambdaNew = 0

    while True:
        lambdaOld = lambdaNew
        vNormalized = normalize(v)
        v = matrixVec(A, vNormalized)
        lambdaNew = dot(vNormalized, v)
        error = abs((lambdaNew - lambdaOld)/ float(lambdaNew))
        if(error <= eps):
            break

    vNormalized = normalize(v)

    print(f"Autovalor = {lambdaNew}")
    print(f"Autovetor = {vNormalized}")


def main():
    print("Bem vindo ao programa que calcula o método da potência regular")

    print("[1] para o exemplo da matriz A1.")
    print("[2] para exemplo da matriz A2.")
    print("[3] para inserir outra matriz.")
    i = input()

    if(i == '1'):
        regularPower([[5, 2, 1],[2, 3, 1], [1, 1, 2]], [1, 1, 1], 0.00001)
    elif(i == '2'):
        regularPower([[40, 8, 4, 2, 1], [8, 30, 12, 6, 2], [4, 12, 20, 1, 2], [2, 6, 1, 25, 4], [1, 2, 2, 4, 5]], [1, 1, 1, 1 ,1], 0.00001)
    else:
        matrixSize = int(input("Digite o tamanho da matriz A: "))
        eps = float(input("Digite a tolerância desejada: "))

        A = [[0 for _ in range(matrixSize)] for _ in range(matrixSize)]

        for i in range(matrixSize):
            print(f"Digite a linha {i} da matriz A:", end=" ")
            A[i] = [float(i) for i in input().split()]

        print("Digite os valores arbritários do vetor inicial (separados por espaço):", end=" ")

        v =[float(i) for i in input().split()]

        regularPower(A, v, eps)


main()
