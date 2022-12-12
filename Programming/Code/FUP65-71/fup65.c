//Arquivos

#include <stdio.h>

//forma classica: arquivos de texto e arquivos binarios
//arquivos de texto: com texto
//arquivos de binarios: de program

int main(){
	FILE *fp; //ponteiro para arquivo;
	
	//cria ou sobrescreve se existir
	fp = fopen("igor","w+");
	
	fputs("Igor Nery\n",fp);
	fputs("Matricula 123456\n",fp);
	fputs("Idade 18\n",fp);
	fputs("elo bronze",fp);
	
	fclose(fp);	

	return 0;
}
