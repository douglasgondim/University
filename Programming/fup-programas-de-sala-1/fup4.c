
//programa que calcula a media de 10 alunos

#include <stdio.h>

int main(){
	int qtdAluno; // quantidade de aluno
	int i; // variavel de controle
	float media, acm, nota;
	acm = 0; //inicializando o acumulador
	
	printf("Insira a quantidade de alunos: ");
	scanf("%d", &qtdAluno);
	//inicializacao, condicao, incremento
	for(i=0; i < qtdAluno; i=i+1){
		printf("Coloque a nota do aluno %d: ",i+1);
		scanf("%f",&nota);
		acm = acm + nota; //acumulando as notas
	}
	media = acm/qtdAluno;
	printf("A media final é: %f", media);
	
	return 0;
}
