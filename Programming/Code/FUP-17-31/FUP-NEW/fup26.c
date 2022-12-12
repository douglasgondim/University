#include <stdio.h>
#include <string.h>

int main(){

	char nome[100] = "IGOR";
	char sobrenome[100] = "NERY";
	char nomeCompleto[100];
	
	strcpy(nomeCompleto, nome);
	printf("%s\n", nomeCompleto);
	
	strcpy(nomeCompleto, sobrenome);
	printf("%s", nomeCompleto);
	
	return 0;
}

