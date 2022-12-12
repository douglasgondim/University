#include <stdio.h>
int main(){
	int input;
	float grade, scores, aux;
	input=1;
	while(input==1){
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
		printf("novo calculo (1-sim 2-nao)\n");
		scanf("%d", &input);
		while(input!=1 && input!=2){
			printf("novo calculo (1-sim 2-nao)\n");
			scanf("%d", &input);
		}

	}	
	return 0;
}