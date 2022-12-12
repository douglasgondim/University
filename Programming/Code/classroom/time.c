#include <stdio.h>

struct Times{
	char selecao[100];
	char tecnico[100];
	int jogadores;
};

typedef struct Times Times;

int main(){
	Times v[2];
	for(int i=0; i<2; i++){
		scanf(" %[^\n]s", v[i].selecao);
		scanf(" %[^\n]s", v[i].tecnico);
		scanf(" %d", &v[i].jogadores);
	}
	for(int i=0; i<2; i++){
		printf("Selecao: %s\n", v[i].selecao);
		printf("Tecnico: %s\n", v[i].tecnico);
		printf("Numero de jogadores: %d\n", v[i].jogadores);
	}

	return 0;
}