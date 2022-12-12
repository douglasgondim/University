#include <stdio.h>
#include <limits.h>

//	(unsigned) int x; // declaracao de inteiro
//  (unsigned) short int x; // declaracao de inteiro curto
//  (unsigned) long int x; // declaracao de inteiro longo


//	float y; // declaracao de float
//	double a; // declaracao de double
//	char c; // declaracao de char

int main(){

	//range dos inteiros e tamanho
	printf("O maior inteiro é: %d\n", INT_MAX);
	printf("O menor inteiro é: %d\n", INT_MIN);
	printf("O tamanho do inteiro: %ld", sizeof(int));
	
	printf("\n---------------------------\n");
	
	//range dos short inteiros e tamanho
	printf("O maior valor de short int: %d\n",SHRT_MAX);
	printf("O menor valor de short int: %d\n",SHRT_MIN);
	printf("O tamanho do short int: %ld\n", sizeof(short int));
	
	printf("\n---------------------------\n");
	
	//range dos inteiros long e tamanho
    printf("O maior valor de long int: %ld\n",LONG_MAX);
	printf("O menor valor de long int: %ld\n",LONG_MIN);
	printf("O tamanho do long int: %ld\n", sizeof(long int));
	
		printf("\n---------------------------\n");
		
		//range dos inteiros long e tamanho
    printf("O maior valor de unsigned long int: %llu\n",ULLONG_MAX);
	printf("O tamanho do unsigned long int: %ld\n", sizeof(unsigned long int));

    printf("\n---------------------------\n");
	
	printf("tamanho do char: %ld", sizeof(char));
	
	
	


	return 0;
}
