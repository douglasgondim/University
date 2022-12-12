typedef struct No_pilha No_pilha;
typedef struct Aresta Aresta;
typedef struct No_lista No_lista;
typedef struct No_fila No_fila;
typedef struct Vertice Vertice;
typedef struct Lista Lista;
typedef struct Pilha Pilha;
typedef struct Fila Fila;

struct No_lista{
	Vertice* elemento;
	struct No_lista *prox;
};

struct Lista{
	No_lista *inicio;
	No_lista* fim;
	int tam;
};

struct No_fila{
	Vertice* elemento;
	struct No_fila *prox;
};

struct Fila{
	No_fila* inicio;
	No_fila* fim;
	int tam;
};

struct Vertice{
	char label;
	int tempo_chegada; // tempo fica cinza
	int tempo_final; // tempo fica preto
	int cor; // 0 == branco, 1 == cinza, 2 == preto
	Lista* vertices_adjacentes;
	int qtd_arestas_chegam;
	Vertice* pai;
	int distancia;

};

struct No_pilha{
	Vertice* elemento;
	struct No_pilha* prox;

};

struct Pilha{
	No_pilha* topo;
	int tam;
};

