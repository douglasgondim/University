# Privacidade Diferencial

Privacidade diferencial é um conjunto de práticas que objetivam a manutenção da segurança e privacidade dos dados de indivíduos. A privacidade diferencial adiciona ruído ou aleatoriedade aos dados , de maneira que não seja possível identificar aspectos de dados individuais e impactando minimamente na precisão dos dados.

# Metodologia
Como dados de entrada utilizamos o dataset covid_CE.csv, e realizamos algumas consultas utilizando esse dataset como base. Inicialmente fazemos uma validação nos dados antes de obter os dados privados e em seguida aplicamos o mecanismo pra então obter uma saída diferencialmente privada com os dados solicitados nos requisitos desse trabalho.

# Implementação
As implementações foram feitas em python, utilizamos o ambiente anaconda, e algumas bibliotecas como pandas, numpy, matplotlib, além de alguns módulos.

# Arquivos do projeto
Os arquivos que compõem o projeto são a main, onde estão as funções do programa, arquivos json de mesorregiões e municípios.
Na consulta 3 para criar os bins, usamos dados do IBGE de mesorregiões para poder agrupar os municípios em sua dada mesorregião e filtramos apenas os dados que precisávamos. Com isso, criamos um dicionário de municípios. Nesse dicionário a chave são os nomes dos municípios em minúsculo e sem acentuação. Nesse dicionário temos o nome do município e sua mesorregião. 
Obs: Esse procedimento foi realizado no trabalho um, e reaproveitamos nesse trabalho, o que foi muito útil para criação dos bins na consulta 3.

# Consultas Q1, Q2, Q3
Q1: Para essa consulta assumimos que os limites das idades estariam entre 0 e 150.
n é o tamanho do dataset e para calcular o deltaF, fazemos (b-a)/n.
A ideia foi calcular a media real das idades e adicionar o ruido, que é calculado usando a função de Laplace do python, passando loc = 0, para garantir a media, e o scale = deltaF/epsilon.

Q2: Nessa consulta não foi necessário calcular o deltaF, assumimos que ele seria 1, por se tratar de uma contagem. A sensibilidade global também é 1. Então é calculado o número de exames e adicionado o ruido que é calculado da mesma maneira que a consulta Q1.

Q3: Nessa consulta também assumimos que deltaF  e a sensibilidade global seriam 1, pelo mesmo motivo da anterior. De acordo com os e-mails de tira dúvida, nos foi confirmado que a diferença entre datasets vizinho seria no máximo 1, então nesse caso não faria sentido calcular o deltaF. Então após fazer o calculo dos exames adicionado o ruido a consulta retorna o valor.

A nossa ideia foi calcular tudo e salvar os valores em uma estrutura, um dicionário. Temos esse dicionário de consultas, onde cada consulta contém seu valor de sensibilidade global, o valor real e os valores anonimizados. 
Para calcular os valores anonimizados, utilizamos um array, onde a posição 1 é o épsilon 0.1, a posição 2 é o épsilon iguale 0.5 a posição 3 é o épsilon igual a 1 é a posição 4 é o épsilon igual a 10.