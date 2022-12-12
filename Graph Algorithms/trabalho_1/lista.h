// inicializa uma lista
Lista* lista_INIT(){
	Lista* nova_lista;
	nova_lista = (Lista*)malloc(sizeof(Lista));
	nova_lista->inicio = NULL;
	nova_lista->fim = NULL;
	nova_lista->tam = 0;
	return nova_lista;
}


// inicializa um nó de uma lista
No_lista* no_lista_INIT(Vertice* elemento){
	No_lista* novo_no;
	novo_no = malloc(sizeof(No_lista));
	novo_no->elemento = elemento;
	novo_no->prox = NULL;
	return novo_no;
}

void addInicio(No_lista* novo_no, Lista* lista){	
	if(lista->tam == 0){ //inicio == null
	 lista->fim = novo_no;
	}else{
	 novo_no->prox = lista->inicio;	 
	}
	lista->inicio = novo_no;
	lista->tam++;
}


void addFim(No_lista* novo_no, Lista* lista){

	if(lista->tam == 0){ //inicio == null
	 lista->inicio = novo_no;
	}else{
	 lista->fim->prox = novo_no;	 
	}
	lista->fim = novo_no;
	lista->tam++;
}

void add(Lista* lista, int posicao, Vertice* elemento){
    if(posicao >= 0 && posicao <= lista->tam){
		No_lista* novo_no = no_lista_INIT(elemento);
      if(posicao == 0){ 
	  addInicio(novo_no, lista);
      }else if(posicao == lista->tam){
	  addFim(novo_no, lista);	 
      }else{
	  No_lista* aux = lista->inicio;
	  int i;
	  for(i=0; i<posicao-1; i++){
	    aux = aux->prox;
	  }
	  novo_no->prox = aux->prox;
	  aux->prox = novo_no;
	  lista->tam++;
      }
   }
}

// achar posição de um vértica na lista
int acharPosicao(Lista* lista, Vertice* elemento){
	No_lista* aux;
	int posicao = 0;
    for (aux = lista->inicio; aux != NULL; aux = aux->prox){
    	if(aux->elemento->label < elemento->label){
    		posicao++;
    	}
    }	
    return posicao;
}

// achar posição que o vértice deveria estar em uma lista
int acharPosicaoOrdenada(Lista* lista, Vertice* elemento){
	No_lista* aux;
	int posicao = 0;
    for (aux = lista->inicio; aux != NULL; aux = aux->prox){
    	if(aux->elemento->label == elemento->label){
    		return posicao;
    	}else{
    		posicao++;
    	}
    }	
    return -1;
}



void addEmOrdem(Lista* lista, int posicao, Vertice* elemento){
	posicao = acharPosicao(lista, elemento);
    if(posicao >= 0 && posicao <= lista->tam){
		No_lista* novo_no = no_lista_INIT(elemento);
      if(posicao == 0){ 
	  addInicio(novo_no, lista);
      }else if(posicao == lista->tam){
	  addFim(novo_no, lista);	 
      }else{
	  No_lista* aux = lista->inicio;
	  int i;
	  for(i=0; i<posicao-1; i++){
	    aux = aux->prox;
	  }
	  novo_no->prox = aux->prox;
	  aux->prox = novo_no;
	  lista->tam++;
      }
   }
}

// procurar vértice no grafo a partir do seu label
Vertice* procurarLista(Lista* lista, char label){
	No_lista* aux;
    for (aux = lista->inicio; aux != NULL; aux = aux->prox){
    	if(aux->elemento->label == label){
    		Vertice* novo_vertice = aux->elemento;
    		return novo_vertice;
    	}
    }
    return NULL;
}

// imprime lista de vértice
void imprimeLista(Lista* lista) {
    No_lista* aux = lista->inicio;
  
    for (aux; aux != NULL; aux = aux->prox){ 
    	No_lista* aux_2 = aux->elemento->vertices_adjacentes->inicio;
    	printf ("%c(%d/%d)->", aux->elemento->label, aux->elemento->tempo_chegada, aux->elemento->tempo_final);
    	for(aux_2; aux_2 != NULL; aux_2 = aux_2->prox){
    		printf(" %c", aux_2->elemento->label);
    	}
    	printf(" cor: %d\n", aux->elemento->cor);
    }
}

// imprime resultado da BFS
void imprimeListaBFS(Lista* lista) {
    No_lista* aux = lista->inicio;
  
    for (aux; aux != NULL; aux = aux->prox){ 
			fprintf (fp2, "%c: %d --> ", aux->elemento->label, aux->elemento->distancia);
			printf ("%c: %d --> ", aux->elemento->label, aux->elemento->distancia);
			if(aux->elemento->pai != NULL){
				Pilha* pilha_caminho_minimo; 
				Vertice* vertice_pai = aux->elemento->pai;
				while(vertice_pai != NULL){
					push(pilha_caminho_minimo, vertice_pai);
					vertice_pai = vertice_pai->pai;
				}
				while(pilha_caminho_minimo->tam > 0){
					char label_removido = pop(pilha_caminho_minimo)->label;
					fprintf(fp2, "%c-", label_removido );
					printf("%c-", label_removido);
				}
				fprintf(fp2, "%c", aux->elemento->label);
				printf("%c", aux->elemento->label);
			}else{
				if(aux->elemento->distancia != -1){
					fprintf(fp2, "%c", aux->elemento->label);
					printf("%c", aux->elemento->label);
				}else{
					fprintf(fp2, "null");
					printf("null");
				}
			}
			fprintf(fp2, "\n");
			printf("\n");

    }
}

// reseta cores dos vértices para branca
void resetarCoresVertices(Lista* lista_vertices){
	No_lista* aux = lista_vertices->inicio;
	for(aux; aux != NULL; aux = aux->prox){
		aux->elemento->cor = 0;
	}
}

// faz cópia ordenada de uma lista
void* copiaListaEOrdena(Lista* destino, Lista* fonte){
	No_lista* aux = fonte->inicio;
  
    for (aux; aux != NULL; aux = aux->prox){ 
  		addEmOrdem(destino, destino->tam, aux->elemento);
    }
}

// faz cópia de uma lista
void* copiaLista(Lista* destino, Lista* fonte){
	No_lista* aux = fonte->inicio;
  
    for (aux; aux != NULL; aux = aux->prox){ 
  		add(destino, destino->tam, aux->elemento);
    }
}

void rmInicio(Lista* lista){
	No_lista *aux = lista->inicio;
	if(lista->tam>0){
		if(lista->tam==1){
			lista->inicio = NULL;
			lista->fim = NULL;
		}else{
			lista->inicio = lista->inicio->prox;
		}
		lista->tam--;
	}
}

// remove posição e fim(linear)
No_lista* removerLista(Lista* lista, int posicao){
	int i;
	No_lista* aux = lista->inicio;
	No_lista* lixo;
	No_lista* retorno;
	if(posicao>=0 && posicao<lista->tam && lista->tam>0){
		if(posicao==0){
			retorno = lista->inicio;
			rmInicio(lista);
			
		}else{
			for(i=0;i<posicao-1;i++){
				aux = aux->prox;
			}
			lixo = aux->prox;
			retorno = lixo;
			aux->prox = aux->prox->prox;
			lista->tam--;
			

		}

		return retorno;
	}
	return NULL;
}

// corpia ordenação de uma lista para outra
void copiaOrdenacaoLista(Lista* lista_1, Lista** lista_2){   // copia ordem da lista_1 para lista_2
	No_lista* aux = lista_1->inicio;
	Lista* aux_2 = lista_INIT();
	Vertice* vertice_aux;
	for(aux; aux != NULL; aux = aux->prox){
		vertice_aux = procurarLista(*lista_2, aux->elemento->label);
		add(aux_2, aux_2->tam, vertice_aux);
	}

	*lista_2 = aux_2;
	free(aux);

}

// ordena lista de vértices por tempo final
void ordenaTopologicamente(Lista* lista){
	No_lista* aux = lista->inicio;
	No_lista* aux_2;

	for(int i=0; i < lista->tam; i++){
		for(int j = 0; j < lista->tam-i; j++){
			int podeCaminhar = 1;
			if(aux->prox != NULL && (aux->elemento->tempo_final < aux->prox->elemento->tempo_final)){
				aux_2 = removerLista(lista, j+1);

				add(lista, j, aux_2->elemento);
				podeCaminhar = 0;

			}
			if(aux->prox != NULL && podeCaminhar == 1){
				aux = aux->prox;
			}

		}
		aux = lista->inicio;
	}
}


// ordena lista de vértices por label
void ordenaLista(Lista* lista){
	No_lista* aux = lista->inicio;
	No_lista* aux_2;

	for(int i=0; i < lista->tam; i++){
		for(int j = 0; j < lista->tam-i; j++){
			int podeCaminhar = 1;
			if(aux->prox != NULL && (aux->elemento->label > aux->prox->elemento->label)){
				aux_2 = removerLista(lista, j+1);

				add(lista, j, aux_2->elemento);
				podeCaminhar = 0;

			}
			if(aux->prox != NULL && podeCaminhar == 1){
				aux = aux->prox;
			}

		}
		aux = lista->inicio;
	}
}
