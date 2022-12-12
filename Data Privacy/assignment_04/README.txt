# Instruções para executar o programa
Nosso trabalho é composto pela main.py, que contem as funções e interface, o dataset covide_ce, disponiblizado pela classroom, um reducer.py que é apenas um artifício
que utilizamos para reduzir o dataset, cuja finalidade foi realizar testes sobre dados reduzidos. Alem disso, contém também esse readme.txt.

Para executar o programa basta criar um ambiente e ativá-lo, instalar as bibliotecas pandas, numpy e matplotlib utilizando o pip. E, em seguida abrir um terminal e executar python3 main.py.
A interface é bem amigável e seu uso é intuitivo para as dadas consultas.

# Privacidade Diferencial

Dado que sabemos o conceito de privacidade diferencial, que é um conjunto de práticas que ajuda a manter dados seguros e privados. Onde seu objetivo é que apos alteração no banco não
seja possível inferir muito sobre um indivíduo em particular. Iremos agora utilizar a abordagem do mecanismo exponencial.

## Mecanismo exponencial
O mecanismo exponencial é conduzido por uma função que mapeia de forma randômica em cima de possíveis respostas, cada uma de determinado domínio pra uma saída em um intervalo R.
A ideia é que o mecanismo retorne as respostas de maneira que a função de utilidade seja maximizada e garantindo a privacidade diferencial.

## Contextualização
Nós tínhamos duas consultas para aplicar novamente sobre o dataset covid ce, onde realizamos uma filtragem nos dados e em seguida aplicamos o mecanismo e obtemos uma saída
diferencialmente privada com as aproximações, gráficos e tudo que foi requisitado para esse trabalho.

## Metodologia
A nossa metodologia seguiu a mesma, as implementações foram feitas em python, utilizamos algumas bibliotecas. Nosso programa é composto por esses arquivos.
Por uma questão de organização nossa estratégia utilizamos um dicionário de consultas, e cada consulta possui essa estrutura aqui, possui um título, um resultado real,
o resultado anonimizado, sensibilidade, score, e as probabilidades.

## Consulta Q1 Real:
Primeiro filtramos o dataframe para ter so municipioCaso e resultadoFinalExame e em seguida filtramos para deixar apenas aqueles em que resultadoFinal era positivo e por
fim tiramos a coluna do resultadoFinal deixando apenas a de município e para consulta real utilizamos o value_counts e retornamos a última posição, ou seja o que menos ocorre.
E esse é o resultado final, que é o menor número de positivos.


## Consulta Q2 real:
Novamente filtramos o dataframe por apenas aqueles resultados negativos e em seguida pegamos as raças e aplicamos um dropna(). Removemos as raças que eram ignoradas e sem informação,
fazemos o value_counts das raças e retorna o primeiro, que é o que mais ocorre, ou seja o que tem mais negativos.

## Score Q1:
Contamos a ocorrência dos municípios e selecionamos aquele com a maior ocorrência e retornamos um dicionário dividindo o maxScore pelo valueCounts, foi assim que fizemos para
que os municípios que ocorrem mais tenham um score menor e os que ocorrem menos tenham um score maior.

## Score Q2:
Basta retornar o valueCounts das raças, pois a que mais ocorre tem um score maior.

## Função Exponencial:
Calculamos primeiro os scores e salvamos em um dicionário de scores. Numerador e denominador é aquela equação do slide que vimos durante a aula, e as probabilidades é justamente
fazer essa divisão do numerador pelo denominador. Criamos um dicionário de probabilidades para poder retornar as informações de município e sua probabilidade, iteramos o
dicionário colocando a probabilidade de cada município acontecer. Essa função exponencial retorna uma escolha, o choice escolhe uma opção dada as opções R, o 1 representa a quantidade
que ele escolherá apenas 1, e esse p=probabilidade é a probabilidade e aqui retornamos tbm o dicionário de probabilidades.

## Sensibilidade Q1:
Fazemos o valueCounts e a sensibilidade é o que mais ocorre dividido pelo que menos ocorre.

## Sensibilidade Q2:
Fazemos o valueCounts e a sensibilidade vai ser o que mais ocorre menos o que menos ocorre e aí vai ser a maior variação e retorna essa sensibilidade.

## Consulta Q1 Anonimizada:
Primeiro fazemos a filtragem dos municípios e resultados, apenas os positivos e ficamos apenas com os municípios e em seguida calculamos os scores desses municípios e contamos eles,
esse R são as nossa possibilidades, onde pegamos os nomes dos municípios únicos, calculamos a sensibilidade e retornamos o resultado do exponencial que é justamente o resultado e o
dicionário de probabilidades, a sensibilidade e os scores.

## Consulta Q2 Anonimizada:
Fazemos o filtro das raças, realizamos a contagem usando o value_counts, calcula os escores, pega cada raça específica e salva nesse R, calcula a
sensibilidade e depois retorna o exponencial, com a raça, resultado e todas essas informações que calculamos.

