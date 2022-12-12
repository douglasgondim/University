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


No* procurarNo(No* pt, int chave){
	if(pt==NULL){
		return NULL;
	}

	if(pt->chave == chave){
		return pt;
	}else{
		if(chave > pt->chave){
			if(pt->dir != NULL){
				procurarNo(pt->dir, chave);
			}else{
				return pt;
			}

		}else{
			if(pt->esq != NULL){	
				procurarNo(pt->esq, chave);
			}else{
				return pt;
			}
		}
	}

}

void inserir(No** pt, int chave){
	if(chave >0){
		No* novo_No = No_INIT(chave);
		No* noEncaixe = procurarNo(*pt, chave);

		if(noEncaixe == NULL){
			*pt = novo_No;
		}else if(chave > noEncaixe->chave){
			noEncaixe->dir = novo_No;
		}else{
			noEncaixe->esq = novo_No;
		}
	}

}

No* remover(No** pt, int chave){
	if((*pt) == NULL){
		return NULL;
	}

	if(chave < (*pt)->chave){
		remover(&(*pt)->esq, chave);
	}else if(chave > (*pt)->chave){
		remover(&(*pt)->dir, chave);
	}else{
		No* deletar;
		deletar = *pt;
		if((*pt)->dir == NULL){
			*pt = (*pt)->esq;
			free(deletar);
		}else if((*pt)->esq == NULL){
			*pt = (*pt)->dir;
			free(deletar);
		}else{
			No* substitui = (*pt)->esq;
			No* anterior = *pt;
			while(substitui->dir != NULL){
				anterior = substitui;
				substitui = substitui->dir;
			}
			(*pt)->chave = substitui->chave;
			if(anterior != *pt){
				anterior->dir = substitui->esq;
			}else{
				anterior->esq = substitui->esq;
			}
			free(substitui);
		}
	}

	

}


void imprimeInOrdem(No* pt){
	if(pt->esq != NULL)
		imprimeInOrdem(pt->esq);

	printf("%d\n", pt->chave);

	if(pt->dir != NULL)
		imprimeInOrdem(pt->dir);
	

}


void imprimePosOrdem(No* pt){
	if(pt->esq != NULL)
		imprimePosOrdem(pt->esq);

	if(pt->dir != NULL)
		imprimePosOrdem(pt->dir);

	printf("%d\n", pt->chave);
	

}

void imprimePreOrdem(No* pt){
	printf("%d\n", pt->chave);

	if(pt->esq != NULL)
		imprimePreOrdem(pt->esq);

	if(pt->dir != NULL)
		imprimePreOrdem(pt->dir);
	

}

int main(){
	inserir(&raiz, 100);
	inserir(&raiz, 50);
	inserir(&raiz, 200);
	inserir(&raiz, 80);
	inserir(&raiz, 90);
	inserir(&raiz, 70);
	inserir(&raiz, 60);
	inserir(&raiz, 120);
	inserir(&raiz, 140);
	inserir(&raiz, 250);
	inserir(&raiz, 300);

	remover(&raiz, 100);
	remover(&raiz, 80);
	remover(&raiz, 120);
	imprimePosOrdem(raiz);

	// 8 3 1 6 4 7 10 14 13

	
	return 0;
}
