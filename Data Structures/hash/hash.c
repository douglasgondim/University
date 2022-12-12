// José Douglas Gondim Soares

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#define TAM 127
int tabela[TAM];
int colisoes=0;



int gerarPosicao(int chave){
	int x;
	if(chave%2==0){
		x = sqrt(5)*chave*1/5;
		return x % TAM;	
	}
	x = sqrt(3)*chave*1/13;
	return x % TAM;
}

int addTabela(int chave){
	int posicao = gerarPosicao(chave);
	if(tabela[posicao] == -1 || tabela[posicao]==chave){
		tabela[posicao] = chave;
	}else{
		colisoes++;

	}
}

int main(){
	srand(time(NULL));

	for(int i=0;i<127;i++){
		tabela[i] = -1;
	}

	for(int i=0;i<50;i++){
		addTabela(rand()%1001);
	}

	printf("Numero de colisões: %d\n", colisoes);



	return 0;
}