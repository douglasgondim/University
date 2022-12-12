
Fila* fila_INIT(){
	Fila* nova_fila;
	nova_fila = (Fila*)malloc(sizeof(Fila));
	nova_fila->inicio = NULL;
	nova_fila->fim = NULL;
	nova_fila->tam = 0;
	return nova_fila;
}

No_fila* no_fila_INIT(Vertice* elemento){
	No_fila* novo_no;
	novo_no = malloc(sizeof(No_fila));
	novo_no->elemento = elemento;
	novo_no->prox = NULL;
	return novo_no;
}


void inserir_fila(Fila* fila, Vertice* elemento){
	No_fila* novo_no = no_fila_INIT(elemento);
	if(fila->tam == 0){ //inicio == null
	 fila->inicio = novo_no;
	}else{
	 fila->fim->prox = novo_no;	 
	}
	fila->fim = novo_no;
	fila->tam++;
}

void imprimeFila(Fila* fila) {
    No_fila* aux = fila->inicio;
  
    for (aux; aux != NULL; aux = aux->prox){ 
    	No_lista* aux_2 = aux->elemento->vertices_adjacentes->inicio;
    	printf ("%c(%d/%d)->", aux->elemento->label, aux->elemento->tempo_chegada, aux->elemento->tempo_final);
    	for(aux_2; aux_2 != NULL; aux_2 = aux_2->prox){
    		printf(" %c", aux_2->elemento->label);
    	}
    	printf(" cor: %d\n", aux->elemento->cor);
    }
}

No_fila* remover_fila(Fila* fila){
	No_fila *aux = fila->inicio;
	if(fila->tam>0){
		if(fila->tam==1){
			fila->inicio = NULL;
			fila->fim = NULL;
		}else{
			fila->inicio = fila->inicio->prox;
		}
		fila->tam--;
		return aux;
	}
	return NULL;
}
