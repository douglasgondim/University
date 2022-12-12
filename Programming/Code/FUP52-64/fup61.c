
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int info;
	struct Node *left;
	struct Node *right;
};

//funcao que cria um novo nó na arvore binaria

struct Node *criaNode(int valor){
	struct Node *no;
	no = (struct Node *) malloc (sizeof(struct Node));
	no->info = valor;
	return no;	
}

//insere o nofilho no noPai
void insereNaArvore(struct Node *noPai, struct Node *noFilho){
	if(noPai->info < noFilho->info){
		if(noPai->right == NULL){
			noPai->right = noFilho;
		}
		else
			insereNaArvore(noPai->right, noFilho);
	}
	else{
		if(noPai->left == NULL){
			noPai->left = noFilho;		
		}
		else
			insereNaArvore(noPai->left, noFilho);
	}
	
}

void imprimirArvore(struct Node *no){
	//visita em ordem
	if(no != NULL){
		printf("\n%d", no->info);
		imprimirArvore(no->left);
		imprimirArvore(no->right);
		
	}	
}

void desalocaArvore(struct Node *no){
	//visita em ordem
	if(no != NULL){
		desalocaArvore(no->left);
		desalocaArvore(no->right);
		free(no);		
	}	
}


void adicionaValorNaArvore(struct Node *no, int valor){
	struct Node *novoNo = criaNode(valor);
	insereNaArvore(no, novoNo);
}


int main(){
	struct Node *RAIZ;
	int qtdNos,valor;
	printf("\nDigite quantos nós você quer inserir: ");
	scanf("%d", &qtdNos);
	printf("\nDigite o Valor da Raiz :");
	scanf("%d", &valor);
	RAIZ = criaNode(valor);
	for(int i = 1; i < qtdNos; i++){
		printf("\nInsira o Valor do No: ");
		scanf("%d", &valor);
		adicionaValorNaArvore(RAIZ, valor);
	}

	imprimirArvore(RAIZ);
	desalocaArvore(RAIZ);
	imprimirArvore(RAIZ);
	
	
	
	

	return 0;
}
