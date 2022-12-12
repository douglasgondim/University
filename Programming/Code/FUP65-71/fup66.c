//Arquivos

#include <stdio.h>

//forma classica: arquivos de texto e arquivos binarios
//arquivos de texto: com texto
//arquivos de binarios: de program

int main(){
	FILE *fp; //ponteiro para arquivo;
	
	char linha[100];
	//cria ou sobrescreve se existir
	fp = fopen("igor","r");
	if (fp == NULL){
		printf("erro ao abrir arquivo");
		return -1;
	}
	
	while(!feof(fp)){
		fgets(linha, 100, fp);
		printf("%s", linha);
	}
	
	fclose(fp);	

	return 0;
}
