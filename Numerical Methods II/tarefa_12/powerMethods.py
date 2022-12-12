from cmath import atan
import numpy as np
import decompositionLU as decomp
import math
import copy

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
    return (lambdaNew, vNormalized)

def inversePower(M, x, eps):
  (L, U) = decomp.LU(M)
  
  error = float('inf')
  prevEigenValue = 0
  x = x / np.linalg.norm(x)
  y = decomp.resolutionLU(L, U, x)

  eigenValue = ( x.transpose() @ y )
  eigenVector = x

  while (error > eps):
    prevEigenValue = eigenValue
    x = y / np.linalg.norm(y)
    y = decomp.resolutionLU(L, U, x)
    eigenValue = ( x.transpose() @ y )

    error = abs( ( prevEigenValue - eigenValue ) / eigenValue )


  eigenValue = 1.0 / eigenValue
  eigenVector = y / np.linalg.norm(y)
  
  return (eigenValue, eigenVector)

def powerShift(A, v, eps, u):
  AHat = A - u * np.identity(len(A))
  (lambdaHat, xHat) = inversePower(AHat, v, eps)
  return (lambdaHat + u, xHat)

def readMatrix():
  matrixSize = int(input("Insira o _size da matriz: "))
  eps = float(input("Insira o erro: "))
  M = np.zeros([matrixSize, matrixSize])
  x = np.zeros([matrixSize, 1])

  for i in range(matrixSize):
      M[i, :] = [float(j) for j in input("Insira a linha {} da matriz: ".format(i)).split(" ")]

  aux = [float(j) for j in input("Insira o vetor: ").split()]
  for i in range(matrixSize):
    x[i, 0] = aux[i]
  
  return {'M': M, 'v': x, 'eps': eps}

def findEigenValues(M, v, eps):
  eigenValues = []
  eigenVectors = []

  (maxEigenValue, maxEigenVector) = regularPower(M, v, eps)

  (minEigenValue, minEigenVector) = powerShift(M, v, eps, -abs(maxEigenValue) )
  eigenValues.append(minEigenValue)
  eigenVectors.append(minEigenVector)
  
  
  eigenValue = 0
  eigenVector = []
  i = int(-abs(maxEigenValue))
  while(i <= abs(maxEigenValue)):
    try:
      (eigenValue, eigenVector) = powerShift(M, v, eps, i)
    except:
      i += 1
      continue
    if(abs(eigenValue - eigenValues[-1]) > 0.1):
      eigenValues.append(eigenValue)
      eigenVectors.append(eigenVector)
      i = int(eigenValue)
    else:
      i += 1
  return(eigenValues, eigenVectors)


def norma(vetor, _size):
  acc = 0
  for i in range(_size):
    acc += vetor[i]*vetor[i]
  return math.sqrt(acc)

def _normalize(vetor, _size):
  q = [0 for _ in range(_size)]
  norm = norma(vetor, _size)

  for i in range(_size):
    q[i] = float(vetor[i]) / float(norm)

  return q

def MultiplicationVectorTransposed(_size, vetor1, vetor2):
  result = [[0 for _ in range(_size)] for _ in range(_size)]

  for i in range(_size):
    for j in range(_size):
      result[i][j] = vetor1[i] * vetor2[j]
  return result

def ScalarMultiplication(matriz, _size, valor):
  result = [[0 for _ in range(_size)] for _ in range(_size)]

  for i in range(_size):
    for j in range(_size):
      result[i][j] = matriz[i][j] * valor
  return result

def MultiplicationNxN(_size, matriz, matriz2):
  result = [[0 for _ in range(_size)] for _ in range(_size)]
  for row in range(_size):
    for col in range(_size):
      result[row][col] = 0
      for i in range(_size):
        result[row][col] += matriz[row][i] * matriz2[i][col]
  return result

def construirHH(Coeficients, j, _size, Hj):
  P = [0 for i in range(_size)]
  PLine = [0 for i in range(_size)]
  N = [0 for i in range(_size)]
  nNormalized = [0 for i in range(_size)]

  for i in range(j+1, _size):
    P[i] = Coeficients[i][j]
  
  normma = norma(P, _size)

  if(P[j+1] > 0):
    PLine[j+1] = -1*normma
  else:
    PLine[j+1] = normma

  for i in range(_size):
    N[i] = P[i] - PLine[i]
  
  nNormalized = _normalize(N, _size)

  matrixNNT = [[0 for _ in range(_size)] for _ in range(_size)]
  auxiliar = [[0 for _ in range(_size)] for _ in range(_size)]

  matrixNNT = MultiplicationVectorTransposed(_size, nNormalized, nNormalized)
  auxiliar = ScalarMultiplication(matrixNNT, _size, 2)

  for i in range(_size):
    for k in range(_size):
      Hj[i][k] = Hj[i][k] - auxiliar[i][k]
  
  return Hj



def HHMethod(Coeficients, _size, H):
  # Hj = [[0 for _ in range(_size)] for _ in range(_size)]

  Aanterior = copy.deepcopy(Coeficients)
  
  ACurrent = [[0 for _ in range(_size)] for _ in range(_size)]

  P = [[0 for _ in range(_size)] for _ in range(_size)]

  for i in range(_size-2):

    Hj = np.identity(_size)
    Hj = construirHH(Aanterior, i, _size, Hj)
    P = MultiplicationNxN(_size, Aanterior, Hj)
    ACurrent = MultiplicationNxN(_size, Hj, P)

    P = [[0 for _ in range(_size)] for _ in range(_size)]

    P = MultiplicationNxN(_size, H, Hj)
    H = copy.deepcopy(P)

    Aanterior = copy.deepcopy(ACurrent)
  
  Tridiagonal = copy.deepcopy(ACurrent)
  return (H, Tridiagonal)

def buildJ(A, j, _size):
  J = np.identity(_size)
  teta = math.atan(A[j+1][j]/ A[j][j])
  
  J[j][j] = math.cos(teta)
  J[j+1][j] = -1*math.sin(teta)
  J[j][j+1] = math.sin(teta)
  J[j+1][j+1] = math.cos(teta)

  return J


def decompositionQR(A, _size):
  Qt = np.identity(_size)
  R = [[0 for _ in range(_size)] for _ in range(_size)]
  J = []
  ACurrent = copy.deepcopy(A)
  P = [[0 for _ in range(_size)] for _ in range(_size)]

  for j in range(_size - 1):
    #  P = [[0 for _ in range(_size)] for _ in range(_size)]
    J = buildJ(ACurrent, j, _size)
    P = MultiplicationNxN(_size, J, ACurrent)
    ACurrent = copy.deepcopy(P)
    P = MultiplicationNxN(_size, J, Qt)
    Qt = copy.deepcopy(P)
  
  # P = [[0 for _ in range(_size)] for _ in range(_size)]

  P = list(np.array(Qt).transpose())

  Qt = copy.deepcopy(P)
  R = copy.deepcopy(ACurrent)


  return (Qt, R)

def QRMethod(Coeficients, _size, erro):
  eigenValues = [[0 for _ in range(_size)] for _ in range(_size)]
  eigenVectors = []
  AMatrices = []

  Q = []
  R = []
  A = np.identity(_size)
  eigenVectors = np.identity(_size)
  (eigenVectors, A) = HHMethod(Coeficients, _size, eigenVectors)

  P = []

  norma = 0


  while(True):
    (Q, R) = decompositionQR(A, _size)
    A = MultiplicationNxN(_size, R, Q)
    P = MultiplicationNxN(_size, eigenVectors, Q)

    eigenVectors = copy.deepcopy(P)

    for i in range(_size):
      for j in range(_size):
        if(i != j):
          norma += A[i][j] * A[i][j]

    norma = math.sqrt(norma)
    val = 0
    for i in range(_size):
      for j in range(_size):
        if i > j:
          val += math.pow(A[i][j], 2)

    AMatrices.append(A)
    if(val < erro): break

  for i in range(_size):
    eigenValues[i] = A[i][i]
  eigenVectors = copy.deepcopy(P)


  return (AMatrices, eigenValues, eigenVectors)


def main():

  # Aula 20
  # 1) e 2)
  print("Aula 20:")
  print("1) Implemente o método de Householder e aplique-o sobre A para encontrar:")
  _size = 5 
  eps = 0.00001
  coeficients = list(np.array([[40, 8, 4, 2, 1], [8, 30, 12, 6, 2], [4, 12, 20, 1, 2], [2, 6, 1, 25, 4], [1, 2, 2, 4, 5]]))
  # coeficients = [[55.0, 4.0, 3.0, 2.0, 1.0, -4.0],
  #   [4.0, 33.0, 4.0, -3.0, -2.0, 1.0],
  #   [3.0, 4.0, 15.0, 7.0, -3.0, -2.0],
  #   [2.0, -3.0, 7.0, 52.0, 5.0, 0.0],
  #   [1.0, -2.0, -3.0, 5.0, 25.0, -7.0],
  #   [-4.0, 1.0, -2.0, 0.0, -7.0, 35.0]]

  HouseHolder = np.identity(_size)
  
  (H, Tridiagonal) = HHMethod(coeficients, _size, HouseHolder)
 

  print("\ni) Matriz Tridiagonal:\n")
  print(np.array(Tridiagonal).round(4))
  print()

  print("\nii) Matriz Householder:\n")
  print(np.array(H).round(4))



# 3)
  print("\n3) Use os métodos da potência para encontrar os autovalores e autovetores da matriz A_barra.")
  (eigenValues, eigenVectors) = findEigenValues(np.array(Tridiagonal), np.array([[1 for _ in range(_size)]]).transpose(), eps)

  print("\nAutovalores da matriz tridiagonal: \n")
  eigenValuesList = []
  for eigenValue in eigenValues:
    eigenValuesList.append(eigenValue[0][0])
  print(eigenValuesList)


  print("\nAutovetores da matriz tridiagonal: \n")
  for eigenVector in eigenVectors:
    print(np.array(eigenVector).transpose()[0])

# 4)
  print("\n4) Usando a matriz H e os autovetores da matriz A_barra encontre os autovetores da matriz A.\n")
  for v in eigenVectors:
    # print(v)
    print(np.array(dot(H, v)))

# 5)
  print("\n5) Encontre os autovalores da matriz A. \n")
  print(eigenValuesList)

# Aula 22

  print("\nAula 22:")
  (AMatrices, eigenValues, eigenVectors) = QRMethod(coeficients, _size, eps)

  print("\n1) Implemente o método QR e aplique-o sobre A para encontrar")
  print("\ni. Matriz diagonal A_barra: ")
  print(np.array(AMatrices[-1]))

  print("\nii) Matriz acumulada P = Q1*Q2*Q3...")
  print(np.array(eigenVectors))

  print("\niii) Matriz que sai de cada iteração QR:")
  
  for idx, m in enumerate(AMatrices):
    print(f"Iteração {idx}:")
    print(np.array(m), '\n')

  print('\niv) Autovalores e Autovetores de A:')

  print("\nAutovalores:")
  print(eigenValues, '\n')

  print("\nAutoVetores:")

  for i in eigenVectors:
    print(i, '\n')


  # A = np.array([[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]])
  # print(A)

  # for i in range(len(A)):
  #   for j in range(len(A)):
  #     if i > j:
  #       print(A[i][j])




    


main()