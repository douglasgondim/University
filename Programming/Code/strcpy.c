#include <stdio.h>
#include <string.h>

int main(){

	char nome[100] = "IGOR";
	char sobrenome[100] = "NERY";
	char nomeCompleto[100];
	
	for (int i=0;i<100;i++){
		nomeCompleto[i] = nome[i];
	}
	printf("%s\n", nomeCompleto);
	

	printf("%s", nomeCompleto);
	
	return 0;
}
