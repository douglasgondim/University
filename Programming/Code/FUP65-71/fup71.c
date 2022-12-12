#include <stdio.h>
#define TAM 3

struct Cadastro{
	char nome[30];
	char sobrenome[30];
	int idade;
	float peso;
	float altura;
};

typedef struct Cadastro Cadastro;

int main(){
	FILE *fp;
	Cadastro cadastros[TAM];
	
	if((fp = fopen("igorbinario","r")) == NULL){
		printf("falha ao abrir/criar arquivo");
	}
	
	int numCadastros;
	fread(&numCadastros, sizeof(int),1,fp);
	fread(cadastros, sizeof(Cadastro), numCadastros, fp);
	
	for(int i =0; i < numCadastros ; i++){
		printf("%s\n", cadastros[i].nome);
		printf("%s\n", cadastros[i].sobrenome);		
		printf("%d\n", cadastros[i].idade);
		printf("%f\n", cadastros[i].peso);
		printf("%f\n", cadastros[i].altura);	
	}
	
	fclose(fp);
	
	return 0;
}
