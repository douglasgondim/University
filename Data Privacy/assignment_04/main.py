import pandas as pd
import numpy as np
import os
import matplotlib.pyplot as plt

def clearTerminal():
    os.system('cls||clear')

def realQ1(df):
    counties = df[['municipioCaso', 'resultadoFinalExame']]
    counties = counties.loc[counties.resultadoFinalExame == 'Positivo']
    counties = counties['municipioCaso']
    return counties.value_counts().index[-1]

def realQ2(df):
    races = df.loc[df.resultadoFinalExame == 'Negativo']
    races = races['racaCor'].dropna()
    races = races[races != 'Ignorado']
    races = races[races != 'Sem Informacao']
    return races.value_counts().index[0]

def scoreQ1(data):
    valueCounts = data.value_counts()
    maxScore = valueCounts[0]
    return dict(maxScore / valueCounts)

def scoreQ2(data):
    return dict(data.value_counts())  

def exponential(d, R, u, deltaU, epsilon):
    scores = u(d)

    numerator = [np.exp(epsilon * scores[r] / (2 * deltaU)) for r in R]
    denominator = sum([np.exp(epsilon * scores[r] / (2 * deltaU)) for r in R])

    probabilities = numerator / denominator

    probDict = {}

    for idx, p in enumerate(probabilities):
        probDict[R[idx]] = p

    return (np.random.choice(R, 1, p=probabilities)[0], probDict)

def sensitivityQ1(srs):
    valueCounts = srs.value_counts()
    sensitivity = valueCounts[0] / valueCounts[-1]
    return sensitivity

def sensitivityQ2(srs):
    srs = srs.value_counts()
    sensitivity = abs(srs[0] - srs[-1])
    return sensitivity

def Q1(df, eps):
    counties = df[['municipioCaso', 'resultadoFinalExame']]
    counties = counties.loc[counties.resultadoFinalExame == 'Positivo']
    counties = counties['municipioCaso']

    scores = scoreQ1(counties)

    valueCounts = counties.value_counts()
    R = np.array(valueCounts.index)
    
    sensitivity = sensitivityQ1(counties)
    return (exponential(counties, R, scoreQ1, sensitivity, eps), sensitivity, scores)

def Q2(df, eps):
    races = df.loc[df.resultadoFinalExame == 'Negativo']
    races = races['racaCor'].dropna()
    races = races[races != 'Ignorado']
    races = races[races != 'Sem Informacao']

    valueCounts = races.value_counts()

    scores = scoreQ2(races)

    R = np.array(valueCounts.index)
    sensitivity = sensitivityQ2(races)
    
    return (exponential(races, R, scoreQ2, sensitivity, eps), sensitivity, scores)

def most_common(lst):
    return max(set(lst), key=lst.count)

def executeQueries(df, epsValues):
    res = {
        'Q1': {
            'title': 'Q1: Qual o município com o menor número de casos positivos de COVID-19?',
            'resultadoReal' : None,
            'resultado': {'0.1': None, '0.5': None, '1': None, '10': None},
            'sensibilidade': None,
            'scores': None,
            'probabilidades': {'0.1': None, '0.5': None, '1': None, '10': None}
        },
        'Q2': {
            'title': 'Q2: Qual a raça com o maior número de casos negativos de COVID-19?',
            'resultadoReal': None,
            'resultado': {'0.1': None, '0.5': None, '1': None, '10': None},
            'sensibilidade': None,
            'scores': None,
            'probabilidades': {'0.1': None, '0.5': None, '1': None, '10': None}
        }
    }

    res['Q1']['resultadoReal'] = realQ1(df)
    res['Q2']['resultadoReal'] = realQ2(df)

    for eps in epsValues:
        Q1Res = Q1(df, eps)

        res['Q1']['probabilidades'][str(eps)] = Q1Res[0][1]
        res['Q1']['sensibilidade'] = Q1Res[1]
        res['Q1']['scores'] = Q1Res[2]

        Q2Res = Q2(df, eps)

        res['Q2']['probabilidades'][str(eps)] = Q2Res[0][1]
        res['Q2']['sensibilidade'] = Q2Res[1]
        res['Q2']['scores'] = Q2Res[2]
    
    Q1Results = {'0.1': [], '0.5': [], '1': [], '10': []}
    Q2Results = {'0.1': [], '0.5': [], '1': [], '10': []}

    for _ in range(10):
        for eps in epsValues:
            Q1Results[str(eps)].append(Q1(df, eps)[0][0])
            Q2Results[str(eps)].append(Q2(df, eps)[0][0])
    
    for r in res['Q1']['resultado']:
        res['Q1']['resultado'][r] = most_common(Q1Results[r])
        res['Q2']['resultado'][r] = most_common(Q2Results[r])

    return res

def plotGraph(res, query, epsValues, title = ''):
    mylist = [1.0 for _ in epsValues] + [1.0]
    nameslist = [res[query]['resultadoReal']]

    if(len(epsValues) == 1):
        nameslist.append(res[query]['resultado'][str(epsValues[0])])
    else:
        for d in res[query]['resultado']:
            nameslist.append(res[query]['resultado'][d])

    fig, ax = plt.subplots(figsize=(10.0, 5.0))

    width = 0.9
    ax.bar(nameslist, mylist, width)
    for i, (name, height) in enumerate(zip(nameslist, mylist)):
        ax.text(i, height *1.05, ' ' + name, color='black',
                ha='center', va='top', rotation=0, fontsize=8)

    ax.set_title(title)
    plt.ylim([0, 1.5])
    plt.xlim([-1, len(nameslist)])

    plt.xlabel("Valores de Epsilon")
    plt.ylabel("Resultado")
    plt.xticks(np.arange(len(epsValues) + 1), ["Valor Real"]  + [str(x) for x in epsValues])
    
    plt.show()


def goBackResultsMenu(res, query, epsValues):
    input("\n[ ] Pressione qualquer tecla para retornar.")
    resultsMenu(res, query, epsValues)

def resultsMenu(res, query, epsValues):
    clearTerminal()
    print("[1] Resultado Real.")
    print("[2] Resultado Anonimizado.")
    print("[3] Sensibilidade.")
    print("[4] Scores.")
    print("[5] Probabilidades.")
    print("[6] Visualizar gráfico comparativo.")
    print("[b] Retornar ao menu anterior.")
    print("[m] Retornar ao menu inicial.")


    i = input("\n")
    clearTerminal()
    if i == '1':
        print(res[query]['resultadoReal'])
        goBackResultsMenu(res, query, epsValues)
    elif i == '2':
        result = res[query]['resultado']
        if(len(epsValues) == 1):
            result = {str(epsValues[0]): result[str(epsValues[0])]}
        print(pd.DataFrame.from_dict(result, orient='index', columns=['Resultado']))
        goBackResultsMenu(res, query, epsValues)
    elif i == '3':
        print(res[query]['sensibilidade'])
        goBackResultsMenu(res, query, epsValues)
    elif i == '4':
         scores = res[query]['scores']
         print(pd.DataFrame.from_dict(scores, orient='index', columns=['Score']))
         goBackResultsMenu(res, query, epsValues)
    elif i == '5':
        probabilities = res[query]['probabilidades']
        if(len(epsValues) == 1):
            probabilities = {str(epsValues[0]): probabilities[str(epsValues[0])]}
        
        for p in probabilities:
            print("\n\n-------------------")
            print(f"Epsilon = {p}\n")
            print(pd.DataFrame.from_dict(probabilities[p], orient='index', columns=['Probabilidade']))
        goBackResultsMenu(res, query, epsValues)
    elif i == '6':
        plotGraph(res, query, epsValues, res[query]['title'])
        resultsMenu(res, query, epsValues)
    elif i == 'b':
        secondaryMenu(res, query)
    elif i == 'm':
         mainMenu(res)


def secondaryMenu(res, query):
    clearTerminal()
    print("Escolha para qual valor de Epsilon deseja anonimizar a sua consulta:")
    print("[1] Para ε = 0.1.")
    print("[2] Para ε = 0.5.")
    print("[3] Para ε = 1.")
    print("[4] Para ε = 10.")
    print("[5] Para ε = [0.1, 0.5, 1, 10].")
    print("[b] Retornar ao menu anterior.")
    print("")

    i = input()

    epsValues = [0.1, 0.5, 1, 10]
    if(i == '1' or i == '2' or i == '3' or i == '4'):
        epsValues = [epsValues[int(i) - 1]]
        resultsMenu(res, query, epsValues)
    elif i == '5':
        resultsMenu(res, query, epsValues)
    elif i == 'b':
        mainMenu(res)

def mainMenu(res):
    clearTerminal()
    print("Bem vindo ao programa que implementa o mecanismo exponencial da privacidade diferencial sobre o dataset \"Covid_CE\".\n")

    print("[1] Q1: Qual o município com o menor número de casos positivos de COVID-19?")
    print("[2] Q2: Qual a raça com o maior número de casos negativos de COVID-19?")
    print("[r] Recalcular resultados.")
    print("[q] Encerrar o programa.")
    print("")

    i = input()

    if i == '1' or i == '2':
        secondaryMenu(res, f"Q{int(i)}")
    elif i == 'q':
        exit()
    elif i == 'r':
        main()


def main():
    clearTerminal()
    print("Lendo os dados...")
    pd.set_option('display.max_rows', 300)
    df = pd.read_csv('Dataset_Covid_CE.csv')
    # df = pd.read_csv('Dataset_Covid_CE_Reduzido.csv')
    df = df[['municipioCaso', 'resultadoFinalExame', 'racaCor', ]]

    res = executeQueries(df, [0.1, 0.5, 1, 10])

    mainMenu(res)


main()



