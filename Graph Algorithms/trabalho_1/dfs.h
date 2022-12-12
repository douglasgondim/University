
int tempo_visita = 1;
int componentes_conexas = 0;


Vertice* maisArestas(Lista* lista){
	if(lista->tam > 0){
		No_lista* aux = lista->inicio;
		// vertice inicial é considerado o que tem mais arestas
		Vertice* vertice_mais_arestas = aux->elemento;
		// numero de arestas incidentes no vertice é o tamanho da lista de adjacência + quantidade de arestas que chegam
		int num_arestas_vertice = vertice_mais_arestas->vertices_adjacentes->tam + vertice_mais_arestas->qtd_arestas_chegam;
		for(aux; aux != NULL;aux = aux->prox){ 
			if(aux->elemento->vertices_adjacentes->tam + aux->elemento->qtd_arestas_chegam > num_arestas_vertice){
				vertice_mais_arestas = aux->elemento;
				num_arestas_vertice = vertice_mais_arestas->vertices_adjacentes->tam + vertice_mais_arestas->qtd_arestas_chegam;
			}else if(aux->elemento->vertices_adjacentes->tam + aux->elemento->qtd_arestas_chegam == num_arestas_vertice && aux->elemento->label < vertice_mais_arestas->label){
				vertice_mais_arestas = aux->elemento;
				num_arestas_vertice = vertice_mais_arestas->vertices_adjacentes->tam + vertice_mais_arestas->qtd_arestas_chegam;
			}
		}
		return vertice_mais_arestas;
	}
	return NULL;
}


Aresta* procurarAresta(Aresta* vetor, char v_origem, char v_destino){
	for(int i=0;i<num_e;i++){
		if(v_origem == vetor[i].vertice_origem->label &&
			v_destino == vetor[i].vertice_destino->label){
			return &vetor[i];
	}
}
return NULL;

}	

void dfs(Lista* lista_vertices, Aresta* vetor_arestas){

	Pilha* pilha = pilha_INIT();

	Lista* vertices_nao_visitados = lista_INIT();
	copiaListaEOrdena(vertices_nao_visitados, lista_vertices);
	Lista* vertices_passaram_pela_pilha = lista_INIT();
	

	Vertice* inicial = maisArestas(lista_vertices);
	fprintf(fp2, "Resultado do DFS a partir do vértice %c\n\n", inicial->label);
	printf("\nResultado do DFS a partir do vértice %c\n\n", inicial->label);

	push(pilha, inicial);
	inicial->cor = 1;
	inicial->tempo_chegada = tempo_visita;
	tempo_visita++;

	// retorna indice do vértice a remover, remove ele da lista de não visitados e adiciona 
	// na lista de vértices que passaram pela pilha
	int posicao_remover = acharPosicaoOrdenada(vertices_nao_visitados, inicial);
	removerLista(vertices_nao_visitados, posicao_remover);
	add(vertices_passaram_pela_pilha, vertices_passaram_pela_pilha->tam, inicial);

	int pode_remover;
	No_lista* aux;
	Vertice* topo_pilha;

	while(vertices_nao_visitados->tam > 0){ // enquanto houverem vértices não visitados
		while(pilha->tam > 0){  // enquanto houver elementos na pilha
			topo_pilha = peek(pilha);
			aux = topo_pilha->vertices_adjacentes->inicio;
			pode_remover = 1;
			// analisa todos os vertices adjacentes ao topo da pilha
			for (aux; aux != NULL; aux = aux->prox){ 
				// busca aresta no vetor de arestas
				Aresta* aresta_do_vetor = procurarAresta(vetor_arestas, topo_pilha->label, aux->elemento->label);
				if(aux->elemento->cor == 0){ // se a cor do vertice for branca
					push(pilha, aux->elemento);
					aux->elemento->cor = 1;
					aux->elemento->tempo_chegada = tempo_visita;
					tempo_visita++;
					pode_remover = 0;

					if(aresta_do_vetor != NULL){
						aresta_do_vetor->classe_aresta = 1;
					}
					break;
				}else if(aux->elemento->cor == 1){	
					if(aresta_do_vetor != NULL){
						aresta_do_vetor->classe_aresta = 2;
					}
				}else if(aux->elemento->cor == 2){

					if((procurarLista(vertices_passaram_pela_pilha, aresta_do_vetor->vertice_origem->label) == NULL) || 
						(procurarLista(vertices_passaram_pela_pilha, aresta_do_vetor->vertice_destino->label) == NULL)){
						if(aresta_do_vetor != NULL && aresta_do_vetor->classe_aresta == -1){
							aresta_do_vetor->classe_aresta = 4;
						}
					}else{
						if(aresta_do_vetor != NULL && aresta_do_vetor->classe_aresta == -1){
							aresta_do_vetor->classe_aresta = 3;
						}
					}

				}

			}
			if(pode_remover == 1){
				Vertice* vertice_removido_pilha = pop(pilha);
				vertice_removido_pilha->cor = 2;
				vertice_removido_pilha->tempo_final = tempo_visita;
				tempo_visita++;
				if(procurarLista(vertices_nao_visitados, vertice_removido_pilha->label) != NULL){
					int posicao_remover = acharPosicaoOrdenada(vertices_nao_visitados, vertice_removido_pilha);
					removerLista(vertices_nao_visitados, posicao_remover);
					add(vertices_passaram_pela_pilha, vertices_passaram_pela_pilha->tam, vertice_removido_pilha);
				}
			}

		}

		if(vertices_nao_visitados->tam > 0){
			// push(pilha, vertices_nao_visitados->inicio->elemento);
			push(pilha, maisArestas(vertices_nao_visitados));

		}

		
	}
}

Lista* componentesConexas(Lista* lista_vertices){
	Pilha* pilha = pilha_INIT();
	
	Lista* vetor_componentes_conexas = (Lista*) malloc(sizeof(Lista)*lista_vertices->tam);

	Lista* vertices_nao_visitados = lista_INIT();
	copiaLista(vertices_nao_visitados, lista_vertices);


	int pode_remover;
	No_lista* aux;
	Vertice* topo_pilha;

	while(vertices_nao_visitados->tam > 0){ // enquanto houverem vértices não visitados
		Lista* componente_conexa = lista_INIT();
		while(pilha->tam > 0){  // enquanto houver elementos na pilha
			topo_pilha = peek(pilha);
			aux = topo_pilha->vertices_adjacentes->inicio;
			pode_remover = 1;
			for (aux; aux != NULL; aux = aux->prox){ 
				if(aux->elemento->cor == 0){
					push(pilha, aux->elemento);
					aux->elemento->cor = 1;
					pode_remover = 0;
					break;
				}

			}
			if(pode_remover == 1){
				Vertice* vertice_removido_pilha = pop(pilha);
				if(procurarLista(vertices_nao_visitados, vertice_removido_pilha->label) != NULL){
					int posicao_remover = acharPosicaoOrdenada(vertices_nao_visitados, vertice_removido_pilha);
					No_lista* remover = removerLista(vertices_nao_visitados, posicao_remover);
					// printf("%c ", vertice_removido_pilha->label );
					add(componente_conexa, componente_conexa->tam, vertice_removido_pilha);
				}
			}

		}

		
		for(int i=0;i<lista_vertices->tam;i++){
			if(vetor_componentes_conexas[i].inicio == NULL){
				vetor_componentes_conexas[i].inicio = componente_conexa->inicio;
				break;
			}
		}
		
		// printf("\n");

		


		if(vertices_nao_visitados->tam > 0){
			push(pilha, vertices_nao_visitados->inicio->elemento);
			vertices_nao_visitados->inicio->elemento->cor = 1;

		}
		componentes_conexas++;

		
	}
	return vetor_componentes_conexas;
}

Aresta* vetor_arestas_INIT(){
	int i;
	Aresta* vetor_arestas = (Aresta*) malloc(sizeof(Aresta)*num_e);
	for(i=0;i<num_e;i++){
		vetor_arestas[i].vertice_origem = NULL;
		vetor_arestas[i].vertice_destino = NULL;
		vetor_arestas[i].classe_aresta = -1;
	}
	return vetor_arestas;

}


void listaAdjacenciaINIT(Lista* lista_vertices, char v_partida, char v_chegada){
	// procura na lista de adjacência pelo vertice de partida
	Vertice* vertice_partida = procurarLista(lista_vertices, v_partida);

		
	if(vertice_partida == NULL){ // se o vertice não estiver na lista
		vertice_partida = vertice_INIT(v_partida); // cria novo vertice
		add(lista_vertices, lista_vertices->tam, vertice_partida); // adiciona na lista	
	}

	// procura por vértice de chegada
	Vertice* vertice_chegada = procurarLista(lista_vertices, v_chegada);
	if(vertice_chegada == NULL){ // se não existe na lista, criar e adicionar
		vertice_chegada = vertice_INIT(v_chegada);
		add(lista_vertices, lista_vertices->tam, vertice_chegada);
	}
	// incrementa quantida de vertices que chegam no vértice
	vertice_chegada->qtd_arestas_chegam++;
	// adiciona o vértice de chegada na lista, em ordem
	addEmOrdem(vertice_partida->vertices_adjacentes, vertice_partida->vertices_adjacentes->tam, vertice_chegada);
	

}

void listaAdjacenciaComplementarINIT(Lista* lista_vertices_complementar, char v_partida, char v_chegada){
	Vertice* vertice_partida_complementar = procurarLista(lista_vertices_complementar, v_partida);
	if(vertice_partida_complementar == NULL){
		vertice_partida_complementar = vertice_INIT(v_partida);
		add(lista_vertices_complementar, lista_vertices_complementar->tam, vertice_partida_complementar);
	}
	Vertice* vertice_chegada_complementar = procurarLista(lista_vertices_complementar, v_chegada);
	if(vertice_chegada_complementar == NULL){
			vertice_chegada_complementar = vertice_INIT(v_chegada);
			add(lista_vertices_complementar, lista_vertices_complementar->tam, vertice_chegada_complementar);
		}
	addEmOrdem(vertice_chegada_complementar->vertices_adjacentes, vertice_partida_complementar->vertices_adjacentes->tam, vertice_partida_complementar);
}















