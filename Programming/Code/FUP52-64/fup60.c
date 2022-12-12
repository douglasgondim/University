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

void imprimirArvore(struct Node *no){
	//visita em ordem
	if(no != NULL){
		imprimirArvore(no->left);
		imprimirArvore(no->right);
		printf("\n%d", no->info);
	}	
}


int main(){
	struct Node *RAIZ, *filho1, 
		*filho2, *filho3, *filho4, *filho5, *filho6;
	RAIZ = criaNode(10);
	filho1 = criaNode(15);
	filho2 = criaNode(8);
	filho3 = criaNode(7);	
	filho4 = criaNode(9);
	filho5 = criaNode(14);
	filho6 = criaNode(17);
	
	RAIZ->right = filho1;
	RAIZ->left  = filho2;
	filho1->right = filho6;
	filho1->left = filho5;
	filho2->right = filho4;
	filho2->left = filho3;
	
	//printf("%d", RAIZ->right->right->info);
	
	//imprime a arvore inteira
	imprimirArvore(RAIZ);
	
	
	
	

	return 0;
}
