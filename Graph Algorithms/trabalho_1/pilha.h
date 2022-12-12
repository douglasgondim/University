No_pilha* no_pilha_INIT(Vertice* elemento){
	No_pilha* novo_no;
	novo_no = (No_pilha*) malloc(sizeof(No_pilha));
	novo_no->elemento = elemento;
	novo_no->prox = NULL;
	return novo_no;

}

Pilha* pilha_INIT(){
	Pilha* nova_pilha;
	nova_pilha = (Pilha*) malloc(sizeof(Pilha));
	nova_pilha->topo = NULL;
	nova_pilha->tam = 0;
	return nova_pilha;
}

void push(Pilha* pilha, Vertice* elemento){
	No_pilha* novo_no = no_pilha_INIT(elemento);

	if(pilha->tam==0){
	}else{
		novo_no->prox = pilha->topo;
	}
	pilha->topo = novo_no;
	pilha->tam++;
}

Vertice* peek(Pilha* pilha){
	return pilha->topo->elemento;
}

Vertice* pop(Pilha* pilha){
	if(pilha->tam>0){
		No_pilha* lixo = pilha->topo;
		Vertice* aux = pilha->topo->elemento;
		if(pilha->tam==1){
			pilha->topo = NULL;
		}else{
			pilha->topo = (No_pilha*) pilha->topo->prox;
		}
		free(lixo);
		pilha->tam--;
		return aux;
	}
	return NULL;
}

// void imprimePilha(Pilha* pilha){
// 	No_pilha* aux = pilha->topo;
// 	while(aux != NULL){
// 		printf("%d\n", aux->elemento);
// 		aux = (No_pilha*) aux->prox;
// 	}
// }
