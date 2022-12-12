#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>


typedef struct Processo Processo;

struct Processo{
	int id;
	int* tabela_paginacao;

};

int tam_memoria, tam_quadro;
int* memoria;
int* quadros_livres;
int opcao, i, j, k;
char usuario = 'D';
char* string;
Processo* processos;
int num_quadros;

void inicializarProcesso(){
	string = (char*)malloc(tam_memoria*sizeof(char));

	printf("Conteúdo: ");
	scanf("%s", string);


	Processo *novo_processo = malloc(sizeof(Processo));

	if(strlen(string)%tam_quadro == 0){
		novo_processo->tabela_paginacao = malloc((int)strlen(string)/tam_quadro*sizeof(int));
	}else{
		novo_processo->tabela_paginacao = malloc((int)(strlen(string)/tam_quadro)+1*sizeof(int));
	}


	for(i=0;i<tam_memoria;i++){
		if(processos[i].tabela_paginacao==NULL){
			processos[i] = *novo_processo;
			processos[i].id = i;
			break;
		}
	}


	k=0;
	int w = 0;

				
	int inicio = tam_quadro*j;

	for(j=0;j<num_quadros;j++){
		if(quadros_livres[j]==0){
			quadros_livres[j] = 1;
			
			inicio = tam_quadro*j;


			for(i=inicio;i<inicio+tam_quadro;i++){
				

				if (w >= strlen(string))
					break;
			
				memoria[i] = string[w];
				w++;
			}
			if(w >= strlen(string))
			break;
		}
		if(w >= strlen(string))
		break;
	}

	free(string);
	free(novo_processo);


}

void exibeMemoria(){
	for(i=0;i<num_quadros;i++){
		k=0;
		for(j=0;j<tam_quadro;j++){
			printf("%c", memoria[(i*tam_quadro)+k]);
			
			k++;
		}
		printf("\n");
	}

}


int main(){

	setlocale(LC_ALL, "Portuguese");

	printf("Qual o tamanho da memória?\n");
	scanf("%d", &tam_memoria);

	memoria = (int*)malloc(tam_memoria*sizeof(int));

	processos = malloc(tam_memoria*sizeof(Processo));

	for(i=0;i<tam_memoria;i++){
		memoria[i] = '0';
		processos[i].tabela_paginacao = NULL;
	}


	printf("Qual o tamanho do quadro?\n");
	scanf("%d", &tam_quadro);

	num_quadros = (int)tam_memoria/tam_quadro;

	quadros_livres = (int*)malloc((int)(num_quadros)*sizeof(int));

	for(i=0;i<(int)(num_quadros);i++){
		quadros_livres[i] = 0;
	}

	while(usuario != 'x'){
		printf("(U)suário ou (A)dministrador?\n");
		scanf(" %c", &usuario);

		if(usuario == 'U' || usuario == 'u'){
			printf("[1] Inicializar processo\n" 
				"[2] Finalizar processo\n" 
				"[3] Alocar memória para processo\n"
				"[4] Acessar conteúdo\n");
			scanf("%d", &opcao);

			if(opcao==1){
				inicializarProcesso();

			}

		}else if(usuario == 'A' || usuario == 'a'){
			printf("[1] Exibir conteúdo de um processo\n" 
				"[2] Exibir conteúdo da memória\n" 
				"[3] Exibir tabela de páginas de um processo\n"
				"[4] Exibir lista de quadros livres\n");
			scanf("%d", &opcao);
			if(opcao==2){
				exibeMemoria();
			}

		}
	}


	return 0;
}