
#include <stdio.h>

int main(){
	char nome[100],cpf[20]; //vetor de caracteres
					//string    							
    scanf("%s", nome); 	//leitura de string	
    scanf("%s", cpf); //leitura de string
    
    printf("nome: %s\n",nome); //imprimindo na tela	
    printf("CPF: %s\n", cpf); //imprimindo na tela	
    
    int i=0;
    while(nome[i] != '\0'){
		printf("%c ",nome[i]);
		i++;
	}
    

	return 0;
}

