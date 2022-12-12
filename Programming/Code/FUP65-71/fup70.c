
#include <stdio.h>
#define TAM 2

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
	
	
	for(int i =0; i <TAM; i++){
		setbuf(stdin,NULL); // limpar buffer
		scanf("%s", cadastros[i].nome);
		setbuf(stdin,NULL);
		scanf("%s", cadastros[i].sobrenome);
		setbuf(stdin,NULL);
		scanf("%d", &cadastros[i].idade);
		scanf("%f", &cadastros[i].peso);
		scanf("%f", &cadastros[i].altura);		
	}
	
	if((fp = fopen("igorbinario","w+")) == NULL){
		printf("falha ao abrir/criar arquivo");
	}
	
	//salva o vetor de struct em um arquivo binario
	int numRegistros = TAM;
	fwrite(&numRegistros, sizeof(int), 1, fp);
	fwrite(cadastros, sizeof(Cadastro),TAM, fp);
	
	fclose(fp);
	
	
	
	
	
}
