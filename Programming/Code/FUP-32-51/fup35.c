

#include <stdio.h>

int main(){
	int v[10] = {2,2,3,4,5,6,7,8,9,10};
	int *p;
	
	printf("%d\n", *v);
	printf("\n-------------------\n");
	for(int i=0; i < 10; i++){
		printf("%d\n", *(v+i));
	}
	
	printf("\n-------------------\n");
	//FAZER p APONTAR PARA A MESMA POSICAO DE v
	p=v; 	
	for(int i=0; i < 10; i++){ 
		printf("%d\n", *p);
		p++;
	}
	
	printf("\n-------------------\n");
	p=v; 	
	for(int i=0; i < 10; i++){
		printf("%d\n", *p++);
	}

	
	return 0;
}
