/*
2-) Leia n números inteiros em um vetor, 
depois gere um segundo vetor do mesmo tamanho, 
de maneira invertida.(Use alocação dinâmica).
*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int *a, *b;
	int len, aux;

	scanf("%d", &len);
	a = (int*) malloc(sizeof(int)*len);
	b = (int*) malloc(sizeof(int)*len);

	for (int i=0; i<len; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	for (int i=0; i<len/2; i++){
		aux = b[i];
		b[i] = b[len-i-1];
		b[len-i-1] = aux;
	}
	for (int i=0; i<len; i++){
		printf("%d ", b[i]);
	}
	return 0;
}