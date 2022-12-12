#include <stdio.h>
#include <stdlib.h>

No *raiz;

No busca_arvore(No pt, int label){
	if(pt == NULL){
		return NULL;
	}else if(pt->label == label){
		return pt;
	}else if(label < pt->label){
		if(pt->esq != NULL){
			busca_arvore(pt->esq, label);
		}else if(pt->dir != NULL){
			busca_arvore(pt->dir, label);			
		}
	}
}
