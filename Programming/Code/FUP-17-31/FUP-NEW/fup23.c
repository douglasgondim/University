

#include <stdio.h>
#include <string.h>

int main(){
	char nome[100];	
	printf("\ndigite o nome completo: \n");
	scanf("%[^\n]s",nome);
	printf("%s",nome);
	
	return 0;
}
