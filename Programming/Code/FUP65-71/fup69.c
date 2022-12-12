	
//Arquivos

#include <stdio.h>
#include <string.h>

//forma classica: arquivos de texto e arquivos binarios
//arquivos de texto: com texto
//arquivos de binarios: de program

int main(){
	FILE *fp; //ponteiro para arquivo;
	char linha[100];
	char nome[30];
	char sobrenome[30];
	char nomeCompleto[60];
	int idade;
	float peso, altura;
	
	//adiciona ao fim de arquivo
	fp = fopen("arquivodedados","r");
	if (fp == NULL){
		printf("erro ao abrir arquivo");
		return -1;
	}
	while(!feof(fp)){
		fgets(linha,100,fp);
		sscanf(linha, "%s %s %d %f %f", nome, sobrenome, &idade, &peso, &altura);		
		strcpy(nomeCompleto,"");
		strcat(nomeCompleto, nome);
		strcat(nomeCompleto, " ");
		strcat(nomeCompleto, sobrenome);
	
		printf("NOME: %s\n", nome);	
		printf("SOBRENOME: %s\n", sobrenome);
		printf("NOME COMPLETO: %s\n", nomeCompleto);			
		printf("IDADE: %d\n", idade);
		printf("PESO: %.2f\n", peso);	
		printf("ALTURA: %.2f\n", altura);
	}
	
	

	
	fclose(fp);	

	return 0;
}
