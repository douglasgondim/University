# Dupla: José Douglas Gondim Soares, 485347
# Fernanda Costa de Sousa, 485347

import os
import pandas as pd
import numpy as np
import time
import random
import json
import unidecode
import copy

df = pd.read_csv('Dataset_Covid_CE.csv')
df_copy = copy.deepcopy(df)

number_of_tuples_to_print = 20
counties = {}

with open('municipios.json') as json_file:
    counties = json.load(json_file)

def viewTable(tables):
    clearTerminal()
    print('Original:\n')
    print(df_copy[tables].dropna().head(number_of_tuples_to_print), end='\n\n')
    print("Anonimizado:\n")
    print(df[tables].dropna().head(number_of_tuples_to_print), end='\n\n')

    print('[ ] Pressione qualquer tecla para voltar ao menu principal.')
    input()
    interactiveMenu()

def viewDataSet():
    clearTerminal()
    print("[1] Vizualizar atributo município.")
    print("[2] Vizualizar atributo data de nascimento.")
    print("[3] Digite uma lista de atributos separada apenas por vírgula.")
    print("[b] Voltar ao menu anterior.\n")
    i = input()
    if i == '1':
        viewTable('municipioCaso')
    elif i == '2':
        viewTable('dataNascimento')
    elif i == '3':
        clearTerminal()
        print("Atributos separados por vírgula: ", end=" ")
        i = input()
        viewTable(i.split(','))
    elif i == 'b':
        interactiveMenu()
    else:
        print("Opção inválida! Tente novamente.")
        time.sleep(2)

    
def suppressAttribute():
    clearTerminal()
    print("Digite o nome do atributo que deseja suprimir:", end=' ')
    paramName = input()
    print("\nDigite o valor para a substituição:", end=' ')
    symbol = input()
    answer = confirmationDialog()
    if answer:
        df[paramName] = df[paramName].dropna().apply(lambda _ : symbol)
        clearTerminal()
        print("Suprimindo valores...")
        time.sleep(2)
    
def generalizeCounty():
    clearTerminal()
    print("[1] Generalizar por mesorregião.")
    print("[2] Generalizar por estado." )
    print("[b] Voltar ao menu anterior.\n")
    i = input()
    clearTerminal()
    if i == '1':
        print("Generalizando municípios...")
        df['municipioCaso'] = df['municipioCaso'].dropna().apply(lambda x : counties[unidecode.unidecode(x).lower()]['mesorregiao'])
        interactiveMenu()
    elif i == '2':
        print("Generalizando municípios...")
        df['municipioCaso'] = df['municipioCaso'].dropna().apply(lambda x : counties[unidecode.unidecode(x).lower()]['estado_sigla'])
        interactiveMenu()
    elif i == 'b':
        interactiveMenu()
    else:
        print("Opção inválida! Tente novamente.")
        time.sleep(2)
        generalizeCounty()


def generalizeDateOfBirthYearMonth():
    clearTerminal()
    print("Generalizando datas...")
    df['dataNascimento'] = df['dataNascimento'].dropna().str.split('-').apply(lambda x : x[0] + '-' + x[1])
    time.sleep(2)
    
    
def generalizeDateOfBirthYear():
    clearTerminal()
    print("Generalizando datas...")
    df['dataNascimento'] = df['dataNascimento'].dropna().str.split('-').apply(lambda x : x[0])
    time.sleep(2)

def perturbNumericalAttribute():
    clearTerminal()
    print("Digite o atributo que deseja pertubar:", end=' ')
    paramName = input()
    print("Digite o tamanho da pertubação:", end=' ')
    pertubationRange = input()
    if not pertubationRange.isnumeric():
        print("\nO tamanho da pertubação precisa ser um número.")
        time.sleep(3)
        return
    else:
        if type(pertubationRange) == int:
            pertubationRange = int(pertubationRange)
        else:
            pertubationRange = float(pertubationRange)
    print("Digite [1] para atributo Int ou [2] para atributo Float:", end=' ')
    attrType = input()
    clearTerminal()
    print("Perturbando valores...")
    if attrType == '1':
        df[paramName] = df[paramName].dropna().apply(lambda x : int(int(x) + random.uniform(-pertubationRange, pertubationRange)))
    elif attrType == '2':
         df[paramName] = df[paramName].dropna().apply(lambda x : float(x) + random.uniform(-pertubationRange, pertubationRange))
    else:
        clearTerminal()
        print("Valor do tipo do atributo inválido!.")
        time.sleep(2)
        return
    time.sleep(2)



def perturbAphaNumericalAttribute():
    clearTerminal()
    print("Digite o atributo que deseja pertubar:", end=' ')
    paramName = input()
    df[paramName] = df[paramName].dropna().apply(lambda x : ''.join(random.sample(x,len(x))))
    print("\nPerturbando valores...")
    time.sleep(2)

def clearTerminal():
    os.system('cls||clear')

def confirmationDialog():
    print("\nTem certeza que deseja continuar? [S - Sim | N - Não]:", end=' ')
    i = input()
    if i == 's' or i == 'S' or i == "Sim" or i == "sim":
        return True
    elif i == 'n' or i == 'N' or  i == "não" or  i == "Não":
        return False
    else:
        confirmationDialog()

   
def interactiveMenu():
    clearTerminal()
    print("Bem-Vindo!\n")

    print("Escolha uma das opções abaixo para anonimizar o arquivo Dataset_Covid_CE.csv\n")

    print("[1] Suprimir um atributo.")
    print("[2] Generalizar um atribututo.")
    print("[3] Perturbar um atributo.")
    print("[4] Visualizar dados.")
    print("[5] Desfazer todas as alterações.")
    print("[s] Salvar alterações em arquivo." )
    print("[q] Encerrar.\n")

    option = input()
    if option == '1':
        suppressAttribute()
        interactiveMenu()
       
    elif option == '2':
        clearTerminal()
        print("Escolha uma das opções abaixo: \n")

        print("[1] Generalizar município.")
        print("[2] Generalizar Data de Nascimento (ANO/MÊS).")
        print("[3] Generalizar Data de Nascimento (ANO).")
        print("[b] Voltar ao menu anterior.\n")
        option = input()

        if option == '1':
            generalizeCounty()
        elif option == '2':
            generalizeDateOfBirthYearMonth()
            interactiveMenu()
        elif option == '3':
            generalizeDateOfBirthYear()
            interactiveMenu()
        elif option == 'b':
            interactiveMenu()
    elif option == '3':
        clearTerminal()
        print("Escolha uma das opções abaixo: \n")
        
        print("[1] Perturbar atributo numérico.")
        print("[2] Perturbar atributo alfanumérico.")
        print("[b] Voltar ao menu anterior.\n")
        option = input()

        if option == '1':
            perturbNumericalAttribute()
            interactiveMenu()
        elif(option == '2'):
            perturbAphaNumericalAttribute()
            interactiveMenu()
        elif option == 'b':
            interactiveMenu()
    elif option == '4':
        viewDataSet()
    elif option == '5':
        clearTerminal()
        print("Desfazendo alterações...")
        global df
        df = copy.deepcopy(df_copy)
        interactiveMenu()
        
    elif option == 's':
        clearTerminal()
        print("Salvando arquivo...")
        df.to_csv("covid_publico.csv")
        time.sleep(2)
    elif option == 'q':
        exit()
    else:
        interactiveMenu()
        pass 
        
interactiveMenu()




