#include <stdio.h>
#include <string.h>
 
struct Musica_struct {
	char titulo[100];
	char autor[100];
	char album[100];
	int duracao;
	int ano;	
}; 

typedef struct Musica_struct Musica;

int main(){
	
	Musica musica_1 = { .titulo = "asa branca", .autor="luiz gonzaga", .duracao=100}; //declaracao de variavel
	Musica *musica_ptr;

	printf("\nTITULO: %s", musica_1.titulo);
	printf("\nAUTOR: %s", musica_1.autor);
	printf("\nALBUM: %s", musica_1.album);
	printf("\nDURACAO: %d", musica_1.duracao);
	printf("\nANO: %d", musica_1.ano);
	
	musica_ptr = &musica_1; // aponta para a mesma regiao de memoria
	
	printf("\nImpressao usando ponteiro");
	printf("\nTITULO: %s", (*musica_ptr).titulo);
	printf("\nAUTOR: %s", (*musica_ptr).autor);
	printf("\nALBUM: %s", (*musica_ptr).album);
	printf("\nDURACAO: %d", (*musica_ptr).duracao);
	printf("\nANO: %d", (*musica_ptr).ano);

	printf("\nImpressao usando ponteiro usando flecha");
	printf("\nTITULO: %s", musica_ptr->titulo);
	printf("\nAUTOR: %s", musica_ptr->autor);
	printf("\nALBUM: %s", musica_ptr->album);
	printf("\nDURACAO: %d", musica_ptr->duracao);
	printf("\nANO: %d", musica_ptr->ano);	
	
	
	return 0;
}
