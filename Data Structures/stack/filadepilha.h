typedef struct pilha Pilha;
typedef struct fila Fila;
typedef struct no No;
typedef struct nodepilha NoDePilha;

struct no{
	int elemento;
	No* prox;
};

struct pilha{
	No* inicio;
	int tam;
};

struct nodepilha{
	Pilha* elemento;
	NoDePilha* prox;
};

struct fila{
	NoDePilha* inicio;
	NoDePilha* fim;
	int tam;
};

Pilha* criar_pilha(){
	Pilha* nova_pilha = (Pilha*)malloc(sizeof(Pilha));
	nova_pilha->inicio = NULL;
	nova_pilha->tam = 0;
	return nova_pilha;
}

void adicionar_pilha(Pilha* pilha, int elemento){
	No* novo = (No*)malloc(sizeof(No));
	novo->elemento = elemento;
	novo->prox = NULL; 
	if(pilha->tam == 0){
		pilha->inicio = novo;
	}else{
		novo->prox = pilha->inicio;
		pilha->inicio = novo;
	}
	pilha->tam++;
}

int remover_pilha(Pilha* pilha){
	if(pilha->tam > 0){
		No* lixo = pilha->inicio;
		int aux = lixo->elemento;
		if(pilha->tam == 1){
			pilha->inicio = NULL;
		}else{
			pilha->inicio = pilha->inicio->prox;
		}
		pilha->tam--;
		free(lixo);
		return aux;	
	}
	return -1;
}

int topo_pilha(Pilha* pilha){
	if(pilha->tam > 0){
		return pilha->inicio->elemento;
	}
	return -1;	
}

void imprimir_pilha(Pilha* pilha){
	printf("PILHA >>> ");
	if(pilha->tam > 0){
		No* aux = pilha->inicio;
		while(aux != NULL){
			printf("%d ", aux->elemento);
			aux = aux->prox;
		}
		printf("\n");
	}else{
		printf("VAZIA\n");
	}
}

Fila* criar_fila(){
	Fila* nova_fila = (Fila*)malloc(sizeof(Fila));
	nova_fila->inicio = NULL;
	nova_fila->fim = NULL;
	nova_fila->tam = 0;
	return nova_fila;
}

void adicionar_fila(Fila* filadepilha, Pilha* nova_pilha){
	NoDePilha* novo_no = (NoDePilha*)malloc(sizeof(NoDePilha));
	novo_no->elemento = nova_pilha;
	novo_no->prox = NULL;
	if(filadepilha->tam == 0){
		filadepilha->inicio = novo_no;
		filadepilha->fim = novo_no;
	}else{
		filadepilha->fim->prox = novo_no;
		filadepilha->fim = novo_no;
	}
	filadepilha->tam++;
}

Pilha* remover_fila(Fila* filadepilha){
	if(filadepilha->tam > 0){
		NoDePilha* lixo = filadepilha->inicio;
		Pilha* aux = lixo->elemento;
		if(filadepilha->tam == 1){
			filadepilha->inicio = NULL;
			filadepilha->fim = NULL;
		}else{
			filadepilha->inicio = filadepilha->inicio->prox;
		}
		free(lixo);
		filadepilha->tam--;
		return aux;
	}
	return NULL;
}

Pilha* frente_fila(Fila* filadepilha){
	if(filadepilha->tam > 0){
		return filadepilha->inicio->elemento;
	}
	return NULL;
}

Pilha* atras_fila(Fila* filadepilha){
	if(filadepilha->tam > 0){
		return filadepilha->fim->elemento;
	}
	return NULL;
}

void imprimir_fila_topo(Fila* filadepilha){
	printf("LISTA >>> ");
	if(filadepilha->tam > 0){
		NoDePilha* aux = filadepilha->inicio;
		while(aux != NULL){
			printf("%d ", topo_pilha(aux->elemento));
			aux = aux->prox;
		}
		printf("\n");
	}else{
		printf("VAZIA\n");
	}
}

void imprimir_fila(Fila* filadepilha){
	printf("LISTA:\n");
	if(filadepilha->tam > 0){
		NoDePilha* aux = filadepilha->inicio;
		while(aux != NULL){
			imprimir_pilha(aux->elemento);
			aux = aux->prox;
		}
		printf("\n");
	}else{
		printf("VAZIA\n");
	}
}