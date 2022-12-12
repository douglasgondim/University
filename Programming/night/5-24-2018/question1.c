// Receba 100 numeros e mostre em ordem crescente

#include <stdio.h>
#define N 5
int main(){
	int vector[N], aux;

	for (int i=0; i<N; i++){
		scanf("%d", &vector[i]);
	}

	for (int i=0; i<N; i++){
		for (int j=0; j<N-i; j++){
			if (vector[j]> vector[j+1]){
				aux = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = aux;
		}   }

	}

	for (int i=0; i<N; i++){
		printf("%d ", vector[i]);
	}


	return 0;
}