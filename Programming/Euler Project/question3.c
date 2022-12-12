/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>

int main(){
	long long int number=600851475143; // número para análise.
	int largest; // maior fator primo;
	int i=3; // variável de controle 
	
	while(1){
		while(number%i==0){ //Enquanto o número for divisível por i.
			number /= i;    // número = número/i.
			largest = i;
		}
		if(number==1)       // se número = 1
			break;
		i += 2;             // i = i + 2, pois números pares não precisam ser testados.

	}

	// imprime maior fator primo de number.
	printf("%d\n", largest);

	return 0;
}
