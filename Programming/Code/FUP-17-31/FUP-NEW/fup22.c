
#include <stdio.h>
#include <string.h>

int main(){
	char nome[100];	
	printf("\ndigite o nome completo: \n");
	fgets(nome, 100, stdin);
	printf("%s",nome);
	
	return 0;
}
