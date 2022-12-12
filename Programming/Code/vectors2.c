// Dado um vetor de 10 posições preenchido pelo usuário, 
// coloque o maior número digitado na última posição.
// detalhe: o vetor final deve possuir os mesmos números
// informados pelo usuário

#include <stdio.h>
int main(){
	int vector[10], i, bigger;
	scanf("%d", &vector[0]);

	for (i=1; i <10; i++){
		scanf("%d", &vector[i]);
		if (vector[i] > vector[i-1]){
			bigger = vector[i];

		}
		vector[9] = bigger;
	}
	printf("%d", vector[9]);

	return 0;
}



#include <stdio.h>
int main(){
	int values[QTT]
	return 0;
}