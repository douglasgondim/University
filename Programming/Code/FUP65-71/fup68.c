
//Arquivos

#include <stdio.h>

//forma classica: arquivos de texto e arquivos binarios
//arquivos de texto: com texto
//arquivos de binarios: de program

int main(){
	FILE *fp; //ponteiro para arquivo;

	//adiciona ao fim de arquivo
	fp = fopen("igor","a");
	if (fp == NULL){
		printf("erro ao abrir arquivo");
		return 0;
	}
	fputs("vai para a liga diamante\n",fp);

	
	fclose(fp);	

	return 0;
}
