//Dada uma sequencia n dizer quantas vezes cda posição aparece na sequência.
//Ex: n=8

#include <stdio.h>
#define N 10
int main(){
	int vector[N], aux;
	for (int i=0; i<N; i++){
		scanf("%d", &vector[i]);
	}

	for (int i=0; i<N; i++){
		aux =0;
		for (int j=0; j<N; j++){
			if (vector[i]==vector[j]){
				aux++;
			}
		}

		printf("%d occurs %d times\n", vector[i], aux);
		
		
	}




	return 0;
}

