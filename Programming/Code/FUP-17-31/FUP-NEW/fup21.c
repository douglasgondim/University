//retorna o tamanho de um nome

#include <stdio.h>
#include <string.h>

int main(){
	char nome[100];
	int cont=0;
	scanf("%s", nome);
	
	while(nome[cont] != '\0')
		cont++;
		
	printf("o tamanho é: %d", cont);
	
	printf("\nUSANDO STRING.H: \n");
	printf("tamanho: %d", strlen(nome));

	return 0;
}
