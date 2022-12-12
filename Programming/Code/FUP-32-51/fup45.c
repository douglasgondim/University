//O QUE É FUNCAO?
//É UM PROCEDIMENTO QUE RECEBE ARGUMENTOS E RETORNA UM VALOR

/*
 * tipo_de_valor_retornado NOME_DA_FUNCAO(tipo param1, tipo param2,..., tipo paramn){
 * 
 * 
 * 		return valor; //caso a funcao REALMENTE tenha que retornar um valor
 * }
 * 
 * 
 */


//EXEMPLO 
//PROGRAMA COM UMA FUNCAO QUE DETERMINA SE UM NUMERO É PRIMO OU NAO
#include <stdio.h>

//retornar 1 se for primo, 0 caso contrario;
int verificaPrimo(int num){
	int contador=0;
	for(int i =1; i <=num; i++){
		if(num%i==0) contador++;
	}
	if(contador == 2){ 
		return 1;
	}
	return 0;
}

int main(){
	int n, saida;
	printf("Digite um numero qualquer positivo: ");
	scanf("%d", &n);
	saida = verificaPrimo(n);
	if(saida==1)
		printf("É primo");
	else
		printf("Não é primo");

	return 0;
}
