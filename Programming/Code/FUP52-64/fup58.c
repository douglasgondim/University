
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

void carregaMusica(Musica *musica_1){
	printf("\nInserir dados da musica: ");
	scanf("%[^\n]s", musica_1->titulo);
	scanf(" %[^\n]s", musica_1->autor);
	scanf(" %[^\n]s", musica_1->album);
	scanf(" %d", &musica_1->duracao);
	scanf(" %d", &musica_1->ano);
}

void imprimirMusica(Musica musica_1){
	printf("\nTITULO: %s"	, musica_1.titulo);
	printf("\nAUTOR: %s"	, musica_1.autor);
	printf("\nALBUM: %s"	, musica_1.album);
	printf("\nDURACAO: %d"	, musica_1.duracao);
	printf("\nANO: %d"		, musica_1.ano);	
}

int main(){
	Musica musica = { .titulo = "asa branca", .autor="luiz gonzaga", .duracao=100}; //declaracao de variavel
	Musica musica_2;
	
	musica_2 = musica; // copia
	
	imprimirMusica(musica);
	
	//carrega os dados da segunda musica
	carregaMusica(&musica_2);
	imprimirMusica(musica_2);
	
	
	return 0;
}
