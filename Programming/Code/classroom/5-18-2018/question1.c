/*
1-) Crie um algoritmo que leia um vetor n números inteiros e gere um segundo vetor cujo 
as posições pares são o dobro, e as ímpares são o triplo. (Use alocação dinâmica).

*/

#include <stdio.h>
#include <stdlib.h>
int main(){
	int *n, *m;
	int len;
	
	scanf("%d", &len);
	n = (int*) malloc(sizeof(int)*len);
	m = (int*) malloc(sizeof(int)*len);

	for (int i=0; i<len; i++){
		scanf("%d", &n[i]);
	}

	for (int i=0; i<len; i++){
		if (i % 2 == 0){
			m[i] = n[i] * 2;
		}else{
			m[i] = n[i] * 3;
		}
	}

	for (int i=0; i<len; i++){
		printf("%d ", m[i]);
	}

	return 0;
}