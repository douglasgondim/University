#include <stdio.h>
#include <string.h>
/*
 * tipos primitivos: 
 * int (inteiro)
 * float (ponto flutuante)
 * char (caractere)
 * double(ponto flutuante de dupla precisao)
 * bool (nao tem a partir até c99)
 * 
 * tipo estruturado homogeneo:
 * vetores 
 * matrizes
 * 
 * */
 // struct  - Registro - register
 //tipo estruturado heterogeneo
 
struct Musica {
	char titulo[100];
	char autor[100];
	char album[100];
	int duracao;
	int ano;	
}; 

int main(){
	struct Musica musica_1, musica_2; //declaracao de variavel
	
	//carregando os dados
	strcpy(musica_1.titulo,"O segundo sol");
	strcpy(musica_1.autor,"Nando Reis");
	strcpy(musica_1.album,"Com você, meu mundo ficaria completo");
	musica_1.duracao = 200;
	musica_1.ano = 2001;
	
	printf("\nTITULO: %s", musica_1.titulo);
	printf("\nAUTOR: %s", musica_1.autor);
	printf("\nALBUM: %s", musica_1.album);
	printf("\nDURACAO: %d", musica_1.duracao);
	printf("\nANO: %d", musica_1.ano);
	
	printf("\nDados da segunda musica: ");
	scanf("%[^\n]s", musica_2.titulo);
	scanf(" %[^\n]s", musica_2.autor);
	scanf(" %[^\n]s", musica_2.album);
	scanf(" %d", &musica_2.duracao);
	scanf(" %d", &musica_2.ano);
	
	printf("INFORMACOES DA SEGUNDA MUSICA");
	printf("\nTITULO: %s", musica_2.titulo);
	printf("\nAUTOR: %s", musica_2.autor);
	printf("\nALBUM: %s", musica_2.album);
	printf("\nDURACAO: %d", musica_2.duracao);
	printf("\nANO: %d", musica_2.ano);
	
	

	return 0;
}
