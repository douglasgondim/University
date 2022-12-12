#include <stdio.h>
#include <stdlib.h>
#include "no.h"

No* raiz = NULL;


No* No_INIT(int chave){
	No* novo_No = malloc(sizeof(No));
	novo_No->chave = chave;
	novo_No->dir = NULL;
	novo_No->esq = NULL;
	return novo_No;
}



No* buscar(No* pt, int chave){
	if(pt==NULL){
		return pt;
	}else{
		if(chave>pt->chave){
			if(pt->dir==NULL){
				return pt;
			}else{
				buscar(pt->dir, chave);
			}
		}else{
			if(pt->esq==NULL){
				return pt;
			}else{
				buscar(pt->esq, chave);
			}
		}
	}
}



void add(No* pt2, int chave){
	No* novo_No = No_INIT(chave);
	No* no_vazio = buscar(pt2, chave);
	
	if(no_vazio==pt2){
		pt2 = novo_No;
	}else{
		if(chave>no_vazio->chave){
			no_vazio->dir = novo_No;
		}else{
			no_vazio->esq = novo_No;
		}
	}
}

void adi(int valor){
	No* novo_No = raiz;
	if(raiz == NULL)
		raiz->chave=valor;
	else
		add(novo_No, valor);
}
void imprimir_in_ordem(No* pt){
	if(pt != NULL){
		imprimir_in_ordem(pt->esq);
		printf("%d\n", pt->chave);
	
		
			imprimir_in_ordem(pt->dir);
			// printf("%d\n", pt->chave);
	}
}



int main(){
	adi(5);
	// add(raiz, 6);
	// add(raiz, 7);
	// add(raiz, 10);
	// add(raiz, 11);
	// printf("a\n");
	// if(buscar(raiz, 6)!=NULL){
	// 	printf("a\n");
	// }
	printf("%d\n", raiz->chave);

	imprimir_in_ordem(raiz);

	return 0;
}