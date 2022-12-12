struct Aresta{
	Vertice* vertice_origem;
	Vertice* vertice_destino;
	int classe_aresta; // 1 == arvore, 2 == retorno, 3 == avanço, 4 == cruzamento
};

// inicializa uma aresta
Aresta* aresta_INIT(){
	Aresta* nova_aresta = (Aresta*) malloc(sizeof(Aresta));
	nova_aresta->vertice_origem = NULL;
	nova_aresta->vertice_destino = NULL;
	nova_aresta->classe_aresta = 0;
}


// imprime aresta (v_partida v_destino classe)
void imprimeAresta(Aresta* aresta){
	char classe[20];
	switch(aresta->classe_aresta){
		case 1 : strcpy(classe, "Árvore");
		break;
		case 2 : strcpy(classe, "Retorno");
		break;
		case 3 : strcpy(classe, "Avanço");
		break;
		case 4 : strcpy(classe, "Cruzamento");
		break;	
	}
	fprintf(fp2, "%c %c: %s\n", aresta->vertice_origem->label, aresta->vertice_destino->label, classe);
	printf("%c %c: %s\n", aresta->vertice_origem->label, aresta->vertice_destino->label, classe);
}

