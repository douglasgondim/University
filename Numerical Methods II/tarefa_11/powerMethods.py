import numpy as np
import decompositionLU as decomp
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
  matrixSize = int(input("Insira o tamanho da matriz: "))
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



def main():

    print("Bem vindo ao programa que calcula o método da potência inverso e potência com deslocamento.")

    print("[1] Potência Inverso.")
    print("[2] Potência com deslocamento.")
    print("[3] Calcular todos os Autovalores e Autovetores de uma matriz.")

    method = input()

    print("[1] para o exemplo da matriz A1.")
    print("[2] para exemplo da matriz A2.")
    print("[3] para exemplo da matriz A3.")
    print("[4] para inserir outra matriz.")

    i = input()

    eps = 0.000001
    u = 0
    A1 = np.array([[5, 2, 1], [2, 3, 1], [1, 1, 2]])
    A2 = np.array([[-14, 1, -2], [1, -1, 1], [-2, 1, -11]])
    A3 = np.array([[40, 8, 4, 2, 1], [8, 30, 12, 6, 2], [4, 12, 20, 1, 2], [2, 6, 1, 25, 4], [1, 2, 2, 4, 5]])
    v = []

    if(method == '1'):
      eigenValue = 0
      eigenVector = []       

      if(i != '4'):
        eps = float(input("Digite o valor da tolerância: "))

      if(i == '1'):
        (eigenValue, eigenVector) = inversePower(A1, np.array([[1, 1, 1]]).transpose(), eps)
      elif(i == '2'):
        (eigenValue, eigenVector) = inversePower(A2, np.array([[1, 1, 1]]).transpose(), eps)
      elif(i == '3'):
        (eigenValue, eigenVector) = inversePower(A3, np.array([[1, 1, 1, 1, 1]]).transpose(), eps)
      else:
        res = readMatrix()
        (eigenValue, eigenVector) = inversePower(res['M'], res['v'], res['eps'])

      print("Auto valor: {}\n\nAuto Vetor:\n{}".format(eigenValue, eigenVector / eigenVector[2, 0]))
    elif(method == '2'):
      u = float(input("Digite o valor do desclocamento: "))
      if (i != '4'):
        eps = float(input("Digite o valor da tolerância: "))


      if(i == '1'):
        (eigenValue, eigenVector) = powerShift(A1, np.array([[1, 1, 1]]).transpose(), eps, u)
      elif(i == '2'):
        
        (eigenValue, eigenVector) = powerShift(A2, np.array([[1, 1, 1]]).transpose(), eps, u)
      elif(i == '3'):
        
        (eigenValue, eigenVector) = powerShift(A3, np.array([[1, 1, 1, 1, 1]]).transpose(), eps, u)
      else:
        res = readMatrix()
        

        (eigenValue, eigenVector) = powerShift(res['M'], res['v'], res['eps'], u)
      print("Auto valor: {}\n\nAuto Vetor:\n{}".format(eigenValue, eigenVector))
    elif(method == '3'):
      eigenValues = []
      eigenVectors = []

      if(i != '4'):
        eps = float(input("Digite o valor da tolerância: "))

      if(i == '1'):
       (eigenValues, eigenVectors) = findEigenValues(A1, np.array([[1, 1, 1]]).transpose(), eps)
      elif(i == '2'):
        (eigenValues, eigenVectors) = findEigenValues(A2, np.array([[1, 1, 1]]).transpose(), eps)
      elif(i == '3'):
        (eigenValues, eigenVectors) = findEigenValues(A3, np.array([[1, 1, 1, 1, 1]]).transpose(), eps)
      elif(i == '4'):
        res = readMatrix()
        (eigenValues, eigenVectors) = findEigenValues(res['M'], res['v'], res['eps'])


      for idx, i in enumerate(eigenValues):
        print(f"Autovalor {idx}: ", i)
        print(f"Autovetor {idx}:", eigenVectors[idx])
        print("\n------------")


main()