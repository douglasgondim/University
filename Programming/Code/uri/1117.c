#include <stdio.h>
int main(){
	float grade, scores, aux;
	scores=0;
	aux = 0;
	while(scores<2){
		scanf("%f", &grade);
		if(grade>=0 && grade<=10){
			aux+=grade;
			scores++;
		}
		else
			printf("nota invalida\n");
	}
	printf("media = %.2f\n", aux/2 );

	return 0;
}