Vertice* vertice_INIT(char label){
	Vertice* novo_vertice = malloc(sizeof(Vertice));
	novo_vertice->label = label;
	novo_vertice->tempo_chegada = 0;
	novo_vertice->tempo_final = 0;
	novo_vertice->cor = 0;
	novo_vertice->vertices_adjacentes = lista_INIT();
	novo_vertice->qtd_arestas_chegam = 0;
	novo_vertice->pai = NULL;
	novo_vertice->distancia = -1;
	return novo_vertice;
}

