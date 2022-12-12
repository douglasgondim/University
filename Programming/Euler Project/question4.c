/*
A palindromic number reads the same both ways. The largest palindrome made from the 
product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include <stdio.h>

// função para testar se número é palindromo.
int isPalindrome(int a){ 
	int aux=0; // variavel para inverter numero.
	int num = a; // salva numero original em num.
	while(a!=0){ // enquanto numero for diferente de zero.
		aux = (aux*10)+(a%10); // aux recebe aux * 10 (adiciona nova casa decimal) + ultimo digito de a.
		a = a/10; // remove último dígito número original.
	}
	// se num for igual a aux o número é igual de traz pra frente e retorna 1
	if(num==aux){
		return 1;
	}else{            // se num for diferente de aux, num não é igual de tras pra frente e retorna 0.
		return 0;
	}

}	


int main(){
	int largest=0; // maior palindromo.
	// loop para multiplicar todos os numeros de 3 digitos.
	for(int i=999; i>99; i--){
		for(int j=999; j>99; j--){
			if((isPalindrome(i*j)==1) && (i*j)> largest){ // se i*j for palindromo e maior que largest:
				largest = i*j;  // largest recebe i*j.
			}
		}
	}
	// imprime maior palindromo da multiplicação de dois numeros de 3 digitos.
	printf("%d\n", largest); 
	return 0;
}