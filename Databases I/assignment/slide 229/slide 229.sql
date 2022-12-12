-- José Douglas Gondim Soares, 485347

/*create procedure premios
as
select v.nome as 'Vendedor', f.nome as 'Filial',
case when count(h.matrvend)*100 < sum(distinct v.salario) then
cast(count(h.matrvend)*100 as decimal(9,2)) else 
sum(distinct v.salario) end as 'Premiação (R$)'
from historico h right outer join vendedores v on h.matrvend=v.matr
join filiais f on f.cod = v.codfil
group by h.matrvend, v.nome, f.nome
order by 3 desc
*/

/*
create function item_vendedor
(@cod_item int, @matr_vendedor int)
returns table
as
return 
select e.ref as 'Ítem', v.nome as 'Vendedor',
sum(h.qtde) as 'Quantidade'
from vendedores v join historico h on v.matr = h.matrvend
join estoque e on e.cod = h.coditem
where h.coditem = @cod_item and v.matr = @matr_vendedor
group by h.coditem, e.ref, v.nome
*/

-- consulta para teste
/*
select * from item_vendedor(7,3)
*/





