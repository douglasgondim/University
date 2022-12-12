#include <stdio.h>


int main(){
	int num = 5;
	int *p;
	p = &num; //passando a posicao de memoria do num para o ponteiro p;
	
	//imprime o conteudo da memoria apontada
	printf("%d\n",*p); 
	
	*p = 1000;
	//imprimindo o conteudo da variavel num
	printf("%d\n",num); 
	
	num = 10;
	printf("%d\n",*p); 

	return 0;
}
