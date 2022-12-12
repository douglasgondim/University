-- 1 - Qual o maior salário?

SELECT max(Salario) FROM FUNCIONARIO;


-- 2 - Qual o total dos salários dos funcionários?

SELECT SUM(Salario) as soma FROM FUNCIONARIO;


-- 3 - Quantas horas o funcionário "Ronaldo" trabalha?

SELECT SUM(Horas) as Horas 
FROM TRABALHA_EM as TE
JOIN FUNCIONARIO as F on F.Cpf = TE.Fcpf 
where F.Pnome = "Ronaldo";


-- 4 - Quantos departamentos existem?

SELECT COUNT(Dnome) as Qtd_Departamentos 
FROM DEPARTAMENTO;


-- 5 - Quais os dependentes do funcionário "Fernando"?

SELECT dep.Nome_dependente as nome_dependente
FROM DEPENDENTE as dep JOIN FUNCIONARIO as F on F.Cpf = dep.Fcpf 
where F.Pnome = "Fernando";


-- 6 - Quantos dependentes tem o funcionário "André"?

SELECT COUNT(Nome_dependente) as dependentes
FROM DEPENDENTE as dep JOIN FUNCIONARIO as F ON dep.Fcpf = F.cpf 
Where F.Pnome = "André"; 


-- 7 - Quem trabalha no projeto "ProdutoX"?

SELECT Pnome as Nome FROM 
FUNCIONARIO as F JOIN TRABALHA_EM as TE on F.Cpf = TE.Fcpf 
JOIN PROJETO on TE.Pnr=PROJETO.Projnumero 
WHERE PROJETO.Projnome = 'ProdutoX';


-- 8 - Quais funcionários estão sendo supervisionados pelo "Fernando"

SELECT Pnome as Funcionarios 
FROM FUNCIONARIO as F WHERE F.Cpf_supervisor = (SELECT Cpf 
FROM FUNCIONARIO as F WHERE F.Pnome = "Fernando"); 
    

-- 9 - Quais funcionarios trabalham mais de 20 horas?

SELECT PNOME AS 'Funcionarios'
FROM FUNCIONARIO as F JOIN TRABALHA_EM as TE on F.Cpf=TE.Fcpf
where TE.Horas>20;


-- 10 - Quais funcionários trabalham no departamento de "Pesquisa"?

SELECT F.Pnome
FROM FUNCIONARIO AS F 
JOIN DEPARTAMENTO AS D ON D.Dnumero = F.Dnr
WHERE D.Dnome = "Pesquisa";


-- 11 - Quem mora na rua que tem "Flores" no nome?

SELECT F.PNOME AS NOME 
FROM FUNCIONARIO AS F 
WHERE F.ENDERECO like "%Flores%";


-- 12 - Qual a idades (anos) do funcionário "Jorge"?

SELECT Pnome,TIMESTAMPDIFF(YEAR,Datanasc, NOW()) AS ANOS
FROM FUNCIONARIO F
WHERE Pnome="Jorge";


-- 13 - Qual funcionário com a maior carga horária de trabalho?

SELECT F.PNOME AS NOME, sum(TE.Horas) as Horas
FROM FUNCIONARIO F
JOIN TRABALHA_EM TE ON F.Cpf = TE.Fcpf
WHERE TE.Horas IS NOT NULL
GROUP BY TE.Fcpf
ORDER BY Horas DESC
LIMIT 1;


-- 14 - Qual funcionário com a menor carga horária de trabalho?

SELECT F.PNOME AS NOME, sum(TE.Horas) as Horas
FROM FUNCIONARIO F
JOIN TRABALHA_EM TE ON F.Cpf = TE.Fcpf
WHERE TE.Horas IS NOT NULL
GROUP BY TE.Fcpf
ORDER BY Horas ASC
LIMIT 1;


-- 15 - Qual o menor salário?

SELECT MIN(Salario) AS 'MENOR SALARIO' 
FROM FUNCIONARIO;


-- 16 - Quantos funcionários são do sexo M?

SELECT PNOME 
FROM FUNCIONARIO 
WHERE SEXO="M";


-- 17 - Quantos dependentes cada funcionário possui?

SELECT F.Pnome as NOME, COUNT(F.Pnome) as Qtd_Dependents
FROM FUNCIONARIO F
JOIN DEPENDENTE D ON D.Fcpf=F.Cpf
GROUP BY F.Pnome;


-- 18 - Quantos dependentes do sexo feminino nasceram antes de 1980?

SELECT D.Nome_dependente,EXTRACT(YEAR FROM D.Datanasc) AS ANO
FROM DEPENDENTE D
WHERE D.Sexo='F'
HAVING ANO<1980;


-- 19 - Quantos dependentes do sexo masculino?

SELECT COUNT(D.Nome_dependente) as QTD_DEP
FROM DEPENDENTE D
WHERE D.Sexo='M';


-- 20 - Quantas esposas são dependentes?

SELECT COUNT(D.Nome_dependente) as QTD_DEP
FROM DEPENDENTE D
WHERE D.Parentesco='Esposa';


-- 21 - Qual o local do projeto Informatização?

SELECT LD.Dlocal as LOCALIZACAO
FROM PROJETO P
JOIN LOCALIZACAO_DEP LD
ON P.Dnum=LD.Dnumero
WHERE P.Projnome='Informatização';


-- 22 - Quantos funcionários cada supervisor supervisiona?

SELECT (SELECT FF.Pnome FROM FUNCIONARIO FF WHERE FF.Cpf=F.Cpf_supervisor) as NOME_SUP, COUNT(F.Cpf) as QTD_FUNC
FROM FUNCIONARIO F
WHERE F.Cpf_supervisor IS NOT NULL
GROUP BY F.Cpf_supervisor;


-- 23 - Qual o funcionário mais velho?
  
SELECT Pnome, EXTRACT(YEAR FROM CURRENT_DATE)-EXTRACT(YEAR FROM Datanasc) as Anos
FROM FUNCIONARIO
ORDER BY Anos DESC
LIMIT 1;


-- 24 - Qual o dependente mais novo?

SELECT Nome_dependente, EXTRACT(YEAR FROM CURRENT_DATE)-EXTRACT(YEAR FROM Datanasc) as Anos
FROM DEPENDENTE
ORDER BY Anos ASC
LIMIT 1;


-- 25 - Quantos funcionários são do sexo F?

SELECT COUNT(Pnome) as QTD_FUNC_F
FROM FUNCIONARIO
WHERE Sexo='F'


-- 26 - Quantos funcionários do sexo feminino estão no projeto “Informatização”?

SELECT COUNT(Pnome) as QTD_FUNC
FROM FUNCIONARIO F
JOIN PROJETO P ON F.Dnr=P.Dnum
WHERE Sexo='F'
AND P.Projnome='Informatização';


-- 27 - Quantos funcionários cada projeto tem?

SELECT P.Projnome, COUNT(F.Dnr) as QTD_FUNC_PROJ
FROM FUNCIONARIO F
JOIN PROJETO P ON F.Dnr=P.Dnum
GROUP BY P.Projnome;


-- 28 - Quantos dependentes são do sexo F?

SELECT COUNT(D.Nome_dependente) as QTD_DEP_F
FROM DEPENDENTE D
WHERE D.Sexo='F';


-- 29 - Quais os projetos?
 
SELECT P.Projnome
FROM PROJETO P;


-- 30 - Quais o local de cada departamento?
 
SELECT D.Dnome,LD.Dlocal
FROM DEPARTAMENTO D
JOIN LOCALIZACAO_DEP LD
ON D.Dnumero=LD.Dnumero;


-- 31 - Qual o local de cada projeto?

SELECT P.Projnome,LD.Dlocal
FROM PROJETO P
JOIN LOCALIZACAO_DEP LD
ON P.Dnum=LD.Dnumero;

-- 33 - Qual projeto “Jennifer” trabalha?

SELECT P.Projnome
FROM PROJETO P
JOIN FUNCIONARIO F
ON P.Dnum=F.Dnr
JOIN TRABALHA_EM TE
ON TE.Fcpf=F.Cpf
WHERE F.Pnome="Jennifer";


-- 34 - Qual supervisor trabalha a mais tempo no seu respectivo departamento?

SELECT DISTINCT(F.Cpf_supervisor) as Supervisor, SUM(TE.Horas) as Horas
FROM FUNCIONARIO F
JOIN TRABALHA_EM TE ON F.Cpf_supervisor=TE.Fcpf
WHERE F.Cpf_supervisor IS NOT NULL
AND Horas IS NOT NULL
GROUP BY Supervisor
ORDER BY Horas DESC
LIMIT 1;


-- 35 - Quais funcionários ganham menos de R$ 40.000?

SELECT F.Pnome, F.Salario
FROM FUNCIONARIO F
WHERE F.Salario<40000;


-- 36 – Qual departamento trabalha o funcionário com maior salário?

SELECT F.Pnome, D.Dnome
FROM  FUNCIONARIO as F join TRABALHA_EM as T on F.Cpf = T.Fcpf 
JOIN PROJETO as P on T.Pnr = P.Projnumero 
JOIN DEPARTAMENTO as D on P.Dnum = D.Dnumero
ORDER BY Salario DESC
LIMIT 1;


-- 37 – Qual o funcionário mais novo?

SELECT Pnome, EXTRACT(YEAR FROM CURRENT_DATE)-EXTRACT(YEAR FROM Datanasc) as Anos
FROM FUNCIONARIO
ORDER BY Anos
LIMIT 1;
