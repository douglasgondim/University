
import pandas as pd
from datetime import datetime
import math
import numpy as np
import matplotlib.pyplot as plt
import pylab
import json
import unidecode
import os

def clearTerminal():
    os.system('cls||clear')

def calculateAge(born):
    today = datetime.today()
    return today.year - born.year - ((today.month, today.day) < (born.month, born.day))

def filterValidDates(date):
    try:
        datetime.strptime(date,"%Y-%m-%d")
        if(int(date.split('-')[0]) >= 1901 and int(date.split('-')[0]) <= 2100):
            return date
    except:
        return math.nan
    return math.nan

def realAgeMean(df):
    return df['idade'].mean()

def numberPositiveExams(df):
    return df[df['resultadoFinalExame'] == 'Positivo']['resultadoFinalExame'].count()

def totalPerCounty(df):
    return df.groupby('municipioCaso').size()

# Média da idade dos indivíduos representados no dataset.
def Q1(df, eps):
    a, b = 0, 150
    n = len(df['idade'])
    deltaF = (b - a) / n
    noise = np.random.laplace(loc=0, scale=float(deltaF)/float(eps))
    globalSensitivity = b - a
    return  (realAgeMean(df) + noise, globalSensitivity)

# Número de exames positivos
def Q2(df, eps):
    deltaF = 1
    noise = np.random.laplace(loc=0, scale=float(deltaF)/float(eps))
    globalSensitivity = 1
    return (numberPositiveExams(df) + noise, globalSensitivity)

# Total de exames realizados por município
def Q3(df, eps):
    deltaF = 1
    noise = np.random.laplace(loc=0, scale=float(deltaF)/float(eps))
    globalSensitivity = 1
    return (totalPerCounty(df).apply(lambda x : x + noise), globalSensitivity)

def executeQueries(df, epsValues):
    res = { 
            "Q1": { "sensibilidadeGlobal": None, "valorReal" : 0, "valoresAnonimizados": [] },
            "Q2": { "sensibilidadeGlobal": None, "valorReal" : 0, "valoresAnonimizados": [] }, 
            "Q3": { "sensibilidadeGlobal": None, "valorReal" : None, "valoresAnonimizados": [] }}

    res['Q1']['valorReal'] = realAgeMean(df)
    res['Q2']['valorReal'] = int(numberPositiveExams(df))
    res['Q3']['valorReal'] = totalPerCounty(df).to_dict()


    for eps in epsValues:
        (anonymizedResult, globalSensitivity) = (Q1(df, eps))
        res['Q1']['valoresAnonimizados'].append(anonymizedResult)
        res['Q1']['sensibilidadeGlobal'] = float(globalSensitivity)

        (anonymizedResult, globalSensitivity) = (Q2(df, eps))
        res['Q2']['valoresAnonimizados'].append(anonymizedResult)
        res['Q2']['sensibilidadeGlobal'] = float(globalSensitivity)

        (anonymizedResult, globalSensitivity) = (Q3(df, eps))
        res['Q3']['valoresAnonimizados'].append(anonymizedResult.to_dict())
        res['Q3']['sensibilidadeGlobal'] = float(globalSensitivity)
     
    return res

def plotGraphQ3(bin, epsValues):
    print(epsValues)

    height = [bin[1]['valorReal']] + bin[1]['valoresAnonimizados']   
    bars = ['Valor Real'] + epsValues

    if(len(epsValues) == 1):
        epsValueArr = [0.1, 0.5, 1, 10]
        pos = epsValueArr.index(epsValues[0])
        height = [bin[1]['valorReal']] + [bin[1]['valoresAnonimizados'][pos]]
        bars = ['Valor Real'] + [epsValues[0]]


    y_pos = np.arange(len(bars))
    
    fig = pylab.gcf()
    fig.canvas.manager.set_window_title(bin[0])

    plt.tight_layout()
    plt.title(bin[0])
    plt.bar(y_pos, height)
    plt.xlabel("Valores de Epsilon")
    plt.ylabel("Resultado")
    plt.ylim([min(height) - min(height)*0.01 , max(height) + max(height)*0.01])

    # Create names on the x-axis
    plt.xticks(y_pos, bars)

    # Show graphic
    plt.show()

def plotGraphQ1Q2(query, res, epsValues, title = '', showAllEps = False,):
    height = bars = None
    bars = ['Valor Real'] + epsValues

    if showAllEps:
        height = [res[query]['valorReal']] + res[query]['valoresAnonimizados']
    else:
        pos = [0.1, 0.5, 1, 10].index(epsValues[0])
        height = [res[query]['valorReal'],  res[query]['valoresAnonimizados'][pos]]

    y_pos = np.arange(len(bars))
    
    fig = pylab.gcf()
    fig.canvas.manager.set_window_title(title)


    plt.tight_layout()
    plt.title(title)
    plt.bar(y_pos, height)
    plt.xlabel("Valores de Epsilon")
    plt.ylabel("Resultado")
    plt.ylim([min(height) - min(height)*0.001 , max(height) + max(height)*0.001])

    # Create names on the x-axis
    plt.xticks(y_pos, bars)

    # Show graphic
    plt.show()


def createBins(res):
    res = res['Q3']
    counties = {}
    bins = {}
    with open('municipios.json') as json_file:
        counties = json.load(json_file)
    
    for county in enumerate(res['valorReal']):
        mesoregion = counties[unidecode.unidecode(county[1]).lower()]['mesorregiao']
        if mesoregion not in bins.keys():
            bins[mesoregion] = {}
            bins[mesoregion]['valorReal'] = []
            bins[mesoregion]['valoresAnonimizados'] = [[], [], [], []]
        
        bins[mesoregion]['valorReal'].append(res['valorReal'][county[1]])
        bins[mesoregion]['valoresAnonimizados']

        for idx, dict in enumerate(res['valoresAnonimizados']):
            bins[mesoregion]['valoresAnonimizados'][idx].append(dict[county[1]])
        
    for bin in bins:
        bins[bin]['valorReal'] = float(sum( bins[bin]['valorReal'])) / float(len(bins[bin]['valorReal']))
        for idx, epsRes in  enumerate(bins[bin]['valoresAnonimizados']):
           bins[bin]['valoresAnonimizados'][idx] = float(sum(epsRes)) / float(len(epsRes))
    
    return bins

def showAnonymizedResultsMenu(res, query, eps):
    clearTerminal()
    print("[1] Imprimir o valor anonimizado.")
    print("[2] Visualizar gráfico comparativo entre os valores real e anonimizado.")
    print("[b] Retornar ao menu anterior.")
    print("[m] Retornar ao menu principal.")
    print("")
    
    i = input()

    if i == '1':
        clearTerminal()
        if eps == '5':
            print(res[query]['valoresAnonimizados'])
        else:
            print(res[query]['valoresAnonimizados'][int(eps) - 1])
        input('\n\n[ ] Pressione qualquer tecla para voltar ao menu anterior.')
        showAnonymizedResultsMenu(res, query, eps)
    elif i == '2':
        queryLabels = {
            'Q1': 'Média das idades',
            'Q2': 'Número de exames positivos',
            'Q3': 'Total de exames realizados por município'
        }

        epsValues = [0.1, 0.5, 1, 10]
       

        if(eps == '5'):
            epsValue = epsValues
        else:
            epsValue = [epsValues[int(eps)-1]]

        

        if query == 'Q1' or query == 'Q2':
            plotGraphQ1Q2(query, res, epsValue, showAllEps= (eps == '5'), title = queryLabels[query])
        elif query == 'Q3':
            bins = createBins(res)

            for bin in bins.items():
                plotGraphQ3(bin, epsValue)

        showAnonymizedResultsMenu(res, query, eps)
    elif i == 'b':
        chooseEpsMenu(res, query)
    elif i == 'm':
        mainMenu(res)

def chooseEpsMenu(res, query):
    clearTerminal()
    print("[1] Para ε = 0.1.")
    print("[2] Para ε = 0.5.")
    print("[3] Para ε = 1.")
    print("[4] Para ε = 10.")
    print("[5] Para ε = [0.1, 0.5, 1, 10].")
    print("[b] Retornar ao menu anterior.")
    print("")

    i = input()

    if(i == '1' or i == '2' or i == '3' or i == '4' or i == '5'):
        showAnonymizedResultsMenu(res, query, i)
    elif i == 'b':
        secondaryMenu(res, query)




def secondaryMenu(res, query):
    clearTerminal()
    print("[1] Imprimir resultado real.")
    print('[2] Imprimir sensibilidade global.')
    print("[3] Anonimizar resultado por ε.")
    print("[b] Retornar ao menu anterior.")
    print("")

    i = input()

    if(i == '1'):
        clearTerminal()
        print(res[query]['valorReal'])
        input('\n\n[ ] Pressione qualquer tecla para voltar ao menu anterior.')
        secondaryMenu(res, query)
    elif(i == '2'):
        clearTerminal()
        print(res[query]['sensibilidadeGlobal'])
        input('\n\n[ ] Pressione qualquer tecla para voltar ao menu anterior.')
        secondaryMenu(res, query)
    elif(i == '3'):
        chooseEpsMenu(res, query)
    elif(i == 'b'):
        mainMenu(res)
        





def mainMenu(res):
    clearTerminal()
    print("Bem vindo ao programa que realiza consultas ao dataset \"Covid_CE\" utilizando a privacidade diferencial de Laplace.\n\n")

    print("[1] Q1: Média da idade dos indivíduos representados no dataset.")
    print("[2] Q2: Número de exames positivos.")
    print("[3] Q3: Total de exames realizados por município.")
    print("[4] Recalcular resultados.")
    print("[q] Encerrar o programa.")
    print("")

    i = input()

    if(i == '1' or i == '2' or i == '3'):
        i = "Q" + i
        secondaryMenu(res, i)
    elif(i == '4'):
        main()
    elif(i == 'q'):
        exit()




def main():
    clearTerminal()
    print("Inicializando...")
    df = pd.read_csv('Dataset_Covid_CE.csv')
    df = df[['dataNascimento', 'resultadoFinalExame', 'municipioCaso']]
    df['dataNascimento'] = df[df.dataNascimento.notna()]['dataNascimento'].apply(lambda x : filterValidDates(x))
    df['idade'] = df[df.dataNascimento.notna()]['dataNascimento'].apply(lambda x : calculateAge(datetime.strptime(x,"%Y-%m-%d")))

    epsValues = [0.1, 0.5, 1.0, 10]
    res = executeQueries(df, epsValues)
    mainMenu(res)


    
    # with open("res.json", "w") as outfile:
    #     json.dump(res, outfile)

    # print(res)

    # with open('res.json') as json_file:
    #     res = json.load(json_file)
    # a = pd.DataFrame([res['Q3']['valorReal']] + res['Q3']['valoresAnonimizados']).transpose()

    # a.to_csv('Q3.csv')

    # plotGraphQ1Q2('Q1', res, [0.1,0.5,1,10], showAllEps=True)
    # print(createBins(res))
    # mainMenu(res)
    # bins = createBins(res)
    # for bin in bins.items():
    #     # print(bin)
    #     # bin[0]
    #     # bin[1]['valorReal']
    #     # print(bin[1]['valoresAnonimizados'])

    #     # print("\n\n----")
    #     plotGraphQ3(bin, epsValues)
    #     # break
    




        



main()

