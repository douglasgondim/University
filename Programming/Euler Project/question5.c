/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10
without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

//Função para checar se numero é divisivel pelo intervalo natural de 1 a 20.
int isDivisible1to20(int num){
	for(int i=2; i<20; i++){ // para i de 2 a 20 (2 porque todo numero é divisivel por 1).
		if(num%i != 0) // se num nao for divisivel por (ao menos um) i, return 0.
			return 0;
	}
	return 1; // se num for divisivel por todos os i's, return 1.
}

int main(){
	int num=20; // 20 é o menor numero que tem a possibilidade de ser divisivel pelo intervalo [1, 20].
	while(isDivisible1to20(num) != 1){ // enquanto a função isDivisible1to20 nao retornar 1
		num +=20; // incrementa num em 20, pois é o maior passo viável já que num tem que ser multiplo de 20.
	}	

	// imprime num
	printf("%d\n", num);


	return 0;
}