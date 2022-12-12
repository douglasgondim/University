#include <stdio.h>
#include <stdlib.h>



typedef struct Processo Processo;
struct Processo{
	int id;
	int* tabela_paginacao;

};

int main(){
	
	Processo* novo = malloc(sizeof(Processo)*5);

	for(int i=0;i<5;i++){
		printf("%s\n", novo[i]);
	}
}