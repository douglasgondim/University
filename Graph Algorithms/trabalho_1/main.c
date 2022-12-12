#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// variáveis globais
int num_v, num_e;
FILE* fp;
FILE* fp2;

#include "tipos.h"
#include "pilha.h"
#include "lista.h"
#include "fila.h"
#include "vertice.h"
#include "aresta.h"
#include "dfs.h"
#include "bfs.h"


int main(){
	int i, j;
	char v_partida, v_chegada;
	// abre arquivo do grafo e resultado
	fp = fopen("grafo.txt", "r");
	fp2 = fopen("resultado.txt", "w");

	if (fp == NULL){
      perror("Erro ao abrir arquivo.\n");
      exit(EXIT_FAILURE);
  	}

	
	if (fp2 == NULL){
      perror("Erro ao abrir arquivo.\n");
      exit(EXIT_FAILURE);
   }


	// Lê número de vértices e arestas
	fscanf(fp, "%d %d", &num_v, &num_e);
	if (num_v == 0){
		exit(EXIT_FAILURE);
	}


	// inicializa listas de adjacência
	Lista* lista_vertices = lista_INIT();
	Lista* lista_vertices_complementar = lista_INIT();


	Aresta* vetor_arestas;
	No_lista* aux;

	// lista das componentes conexas
	Lista* componentes_conexas = lista_INIT();
	

	setlocale(LC_ALL, "Portuguese");

	

	vetor_arestas = vetor_arestas_INIT();	

	// Cria listas de adjacência ----------------------------------------- Inicio
	for(i=0;i<num_e;i++){
		fscanf(fp, " %c %c", &v_partida, &v_chegada);

		listaAdjacenciaINIT(lista_vertices, v_partida, v_chegada);
		listaAdjacenciaComplementarINIT(lista_vertices_complementar, v_partida, v_chegada);

		// preencher vetor arestas
		vetor_arestas[i].vertice_origem = procurarLista(lista_vertices, v_partida);
		vetor_arestas[i].vertice_destino = procurarLista(lista_vertices, v_chegada);
		
	}
	

	// roda dfs na lista
	dfs(lista_vertices, vetor_arestas);

	// imprime arestas
	for(i=0;i<num_e;i++){
		imprimeAresta(&vetor_arestas[i]);
	}

	Lista* lista_vertices_topologica = lista_INIT();

	// faz cópia da lista de adjacência e ordena em ordem topológica
	copiaLista(lista_vertices_topologica, lista_vertices);
	ordenaTopologicamente(lista_vertices_topologica);

	fprintf(fp2, "Ordenação Topológica:");
	printf("Ordenação Topológica:");

	// imprime a lista de vértices em ordem topológica
	aux = lista_vertices_topologica->inicio;
	for(aux;aux != NULL;aux= aux->prox){
		fprintf(fp2, " %c", aux->elemento->label);
		printf(" %c", aux->elemento->label);
	}
	fprintf(fp2, "\n");
	printf("\n");

	// ordena grafo complementar na ordem topológica
	copiaOrdenacaoLista(lista_vertices_topologica, &lista_vertices_complementar);

	// obtem lista de componentes conexas 
	componentes_conexas = componentesConexas(lista_vertices_complementar);

	// Conta e imprime número de componentes conexas
	int num_componentes_conexas = 0;
	for(i=0;i<lista_vertices->tam;i++){
		if(componentes_conexas[i].inicio != NULL){
			num_componentes_conexas++;
		}
	}
	fprintf(fp2, "Componentes Conexas: %d componentes. ", num_componentes_conexas);
	printf("Componentes Conexas: %d componentes. ", num_componentes_conexas);
	
	// imprime a lista de componentes conexas
	for(i=0;i<lista_vertices->tam;i++){
		if(componentes_conexas[i].inicio != NULL){
			No_lista* aux;
			fprintf(fp2, "[");
			printf("[");
			aux = componentes_conexas[i].inicio;
			for(aux; aux != NULL; aux = aux->prox){
				if(aux->prox == NULL){
					fprintf(fp2, "%c", aux->elemento->label);
					printf("%c", aux->elemento->label);
				}else{
					fprintf(fp2, "%c ", aux->elemento->label);
					printf("%c ", aux->elemento->label);
				}
				
			}
			fprintf(fp2, "];");
			printf("]; ");
		}
	}
	fprintf(fp2, "\n");
	printf("\n");

//---------------------------------------------------------
//BFS
	// reseta as cores dos vertices da lista de adjacência para branco e ordena por label
	resetarCoresVertices(lista_vertices);
	ordenaLista(lista_vertices);

	// roda BFS
	bfs(lista_vertices, vertice_inicial_bfs(lista_vertices_topologica));

	// fecha arquivos
	fclose(fp);
	fclose(fp2);
	return 0;

}