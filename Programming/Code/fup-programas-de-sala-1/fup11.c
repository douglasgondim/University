
//PROGRAMA QUE CALCULA A MEDIA DE UMA TURMA DE 4 ALUNOS
// IMPRIME AS NOTAS QUE ESTIVEREM ACIMA DA MEDIA

#include <stdio.h>

int main(){
	float acm,n1,n2,n3,n4;
	float media; // media da turma
	
	scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
	
	acm = (n1 + n2 + n3 + n4);
	media = acm/4;
	printf("a media eh:  %f\n", media);
	if(n1 > media) printf("%f",n1);
	if(n2 > media) printf("%f",n2);
	if(n3 > media) printf("%f",n3);
	if(n4 > media) printf("%f",n4);

	return 0;
}
