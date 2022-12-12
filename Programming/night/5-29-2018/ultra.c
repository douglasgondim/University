//ordenar um vetor ( numeros pares, impares, negativos em ordem crescente)

#include <stdio.h>
int main(){
	int *v, n, countEven;

	printf("Size of vector: ");
	scanf("%d", &n);
	v = (int*) malloc(sizeof(int)*n);

	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}

	for(int i=0; i<n; i++){
		if(v[i]%2 == 0)

	}



	return 0;
}