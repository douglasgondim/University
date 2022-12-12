// escolhe o vértice para iniciar
Vertice* vertice_inicial_bfs(Lista* ordem_topologica){
	No_lista* aux = ordem_topologica->inicio;
	int posicao;
	if(ordem_topologica->tam % 2 == 0){
		posicao = ordem_topologica->tam/2;
	}else{
		posicao = (ordem_topologica->tam/2) + 1;
	}
	for(int i = 0; i < posicao-1; i++){
		aux = aux->prox;
	}
	return aux->elemento;

}

void bfs(Lista* lista_vertices, Vertice* inicial){
	Fila* fila_vertices = fila_INIT();

	fprintf(fp2, "\nResultado do BFS a partir do vértice central %c = ⌈%d/2⌉ = %d.\n", inicial->label, num_v, num_v/2);
	printf("\nResultado do BFS a partir do vértice central %c = ⌈%d/2⌉ = %d.\n", inicial->label, num_v, num_v/2);

	// seta cor do vértice inicial para cinza e distância 0
	inicial->cor = 1;
	inicial->distancia = 0;

	inserir_fila(fila_vertices, inicial);

	No_lista* aux;
	while(fila_vertices->tam > 0){  // enquanto houver elementos na fila
		aux = fila_vertices->inicio->elemento->vertices_adjacentes->inicio;
		for (aux; aux != NULL; aux = aux->prox){ // percorre fila de vertices adjacentes ao inicial
			if(aux->elemento->cor == 0){ // se encontrar vértice não visitado, visita e insere na fila
				inserir_fila(fila_vertices, aux->elemento);
				aux->elemento->cor = 1;
				aux->elemento->pai = fila_vertices->inicio->elemento;
				aux->elemento->distancia = fila_vertices->inicio->elemento->distancia + 1;
			}

		}
		// após visitar todos os vértices adjacente, remover vértice pai da fila
		remover_fila(fila_vertices);

	}

	// imprime resultado da BFS
	imprimeListaBFS(lista_vertices);
}