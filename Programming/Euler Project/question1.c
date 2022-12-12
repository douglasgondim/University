/* If we list all the natural numbers below 10 that are multiples of 3 or 5, 
we get 3, 5, 6 and 9. 
The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000. */

#include <stdio.h>
int main(){
	int sum=0; // soma dos múltiplos.

	
	for(int i=3; i<1000; i++){ // para "i" de 3 a 999.
		if(i%3 == 0 || i%5 == 0){ // se "i" for divisível por 3 ou 5, 
			sum += i; //sum é incrementada pelo valor de "i".
		}
	}

	// imprime a soma de todos os multiplos de 3 ou 5 menor que 1000.
	printf("%d\n", sum);

	return 0;
}