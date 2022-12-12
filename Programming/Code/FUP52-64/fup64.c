

#include <stdio.h>

#define TAM 100

struct Livro {
	int codigo;
	char titulo[100];
	char autor[100];
	int isbn;
	int ano;
};

typedef struct Livro Livro;

void carregaLivro( Livro *livro, int codigo){
		livro->codigo = codigo;
		setbuf(stdin,NULL);
		printf("\nDigite o Titulo: ");
		scanf("%[^\n]s", livro->titulo);
		setbuf(stdin,NULL);
		printf("\nDigite o autor: ");
		scanf("%[^\n]s", livro->autor);
		setbuf(stdin,NULL);
		printf("\nDigite o ISBN: ");
		scanf("%d", &livro->isbn);
		printf("\nDigite o ano: ");
		scanf("%d", &livro->ano);
}

void imprimeLivro(Livro *livro){
		printf("\nTitulo : %s", livro->titulo);
		printf("\nAutor : %s", livro->autor);
		printf("\nISBN : %d", livro->isbn);
		printf("\nano : %d", livro->ano);
}

void inicializaBiblioteca(Livro *biblioteca){
	for(int i=0; i < TAM; i++){
		biblioteca[i].codigo = -1;
	}
}

void cadastrarNovoLivro(Livro *biblioteca, int codigo){
	for(int i=0; i < TAM; i++){
		if(biblioteca[i].codigo == -1){
			carregaLivro(&biblioteca[i], codigo);
			break;
		}
	}	
}

int main(){
	int codigo;
	Livro biblioteca[TAM]; // declarando vetor do tipo Livro
						// com 5 posicoes;


	inicializaBiblioteca(biblioteca);

	printf("\nDigite o Codigo do livro ");
	scanf("%d", &codigo);
	
	while(codigo != -1){
		printf("\nInsira um livro ");
		cadastrarNovoLivro(biblioteca,codigo);				
		printf("\nDigite o Codigo do livro ");
		scanf("%d", &codigo);	
	}

	printf("\nDados inseridos:");
	for(int i =0; i < TAM; i++){
		if(biblioteca[i].codigo != -1)
			imprimeLivro(&biblioteca[i]);
	} 	
	

	return 0;
}

