#include <stdio.h>
int main(){
	float N1, N2, N3, N4, N5, average;
	scanf("%f %f %f %f", &N1, &N2, &N3, &N4);
	average = (N1*2 + N2*3 + N3*4 + N4)/10;
	printf("Media: %.1f\n", average);
	if(average>=7)
		printf("Aluno aprovado.\n");
	else if(average<5)
		printf("Aluno reprovado.\n");
	else if(average>=5 && average<7){
		printf("Aluno em exame.\n");
		scanf("%f", &N5);
		printf("Nota do exame: %.1f\n", N5);
		if((average+N5)/2>=5){
			printf("Aluno aprovado.\n");
			printf("Media final: %.1f\n", (average+N5)/2);
		}else{
			printf("Aluno reprovado.\n");
			printf("Media final: %.1f\n", (average+N5)/2);
		}
	}

	return 0;
}