//PROGRAMA QUE CALCULA A MEDIA DE UMA TURMA DE 4 ALUNOS
// IMPRIME AS NOTAS QUE ESTIVEREM ACIMA DA MEDIA

#include <stdio.h>
#define QTD 4 //constante

int main(){
	int i; //índice
	float acm, notas[QTD], media;	
	acm = 0;
	
	for(i = 0; i < QTD; i++){
		scanf("%f", &notas[i]);
		acm += notas[i];
	}
	
	media = acm/QTD;
	
	printf("A média é: %f\n", media);
	
	for(i = 0 ; i < QTD; i++){
		if(notas[i] > media)
			printf("%f\n",notas[i]);
	}
	
	return 0;
}
