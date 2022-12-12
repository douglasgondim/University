#include <stdio.h>
#include <stdlib.h>
#include "no.h"

no* inicio;
no* fim;
int tam=0;

void empilhar(int elemento){
	no* novo = malloc(sizeof(no));
	novo->elemento = elemento;
	novo->prox = NULL;
	novo->ant = NULL; 
	if(tam==0){
		fim = novo;
	}else{
		novo->prox = inicio;
		inicio->ant = novo;
	}
	inicio = novo;
	tam++;
}

int desempilhar(){
	no* lixo = inicio;
	int aux = inicio->elemento;
	if(tam>0){
		if(tam==1){
			inicio = NULL;
			fim = NULL;
		}else{
			inicio = inicio->prox;
			inicio->ant = NULL;
		}
		free(lixo);
		tam--;
	}
	return aux;
}

int resultadoPosFixado(char* entrada){
	int i=0,num1, num2;
	while(entrada[i] != '\0'){
		if(entrada[i]!='+' && entrada[i]!='-' && entrada[i]!='*' && entrada[i]!='/'){
			empilhar(entrada[i]-'0');
		}else{
			num2 = desempilhar();
			num1 = desempilhar();
			if(entrada[i]=='+'){
				empilhar(num1+num2);
			}else if(entrada[i]=='-'){
				empilhar(num1-num2);
			}else if(entrada[i]=='*'){
				empilhar(num1*num2);
			}else if(entrada[i]=='/'){
				empilhar(num1/num2);
			}				
		}
		i++;
	}
	return desempilhar();
}


int main(){
	char entrada[100];

	scanf("%[^\n]s", entrada);

	printf("%d\n", resultadoPosFixado(entrada));



	return 0;
}