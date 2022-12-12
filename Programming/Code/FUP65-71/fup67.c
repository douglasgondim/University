
\//Arquivos

#include <stdio.h>

//forma classica: arquivos de texto e arquivos binarios
//arquivos de texto: com texto
//arquivos de binarios: de program

int main(){
	FILE *fp; //ponteiro para arquivo;
	
	char c;
	//cria ou sobrescreve se existir
	fp = fopen("igor","r");
	if (fp == NULL){
		printf("erro ao abrir arquivo");
		return 0;
	}
	//pega caractere a caractere
	while(!feof(fp)){
		c = fgetc(fp);
		printf("%c",c);
	}
	
	fclose(fp);	

	return 0;
}
