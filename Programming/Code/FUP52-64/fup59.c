#include <stdio.h>

struct Node {
	int info;
	struct Node *left;
	struct Node *right;
};

int main(){
	struct Node raiz, f_esq, f_dir;
	raiz.info = 10;
	f_esq.info = 9;
	f_dir.info = 8;
	
	raiz.left = &f_esq; //}passando o endereco de f_esq para o ponteiro *left;
	raiz.right = &f_dir; //passando o endereco de f_dir para o ponteiro *right;
	
	printf("informacao da raiz: %d", raiz.info); 
	printf("\ninformacao do nó esquerdo: %d", raiz.left->info);
	printf("\ninformacao do nó direito: %d", raiz.right->info);
	
	return 0;
}


