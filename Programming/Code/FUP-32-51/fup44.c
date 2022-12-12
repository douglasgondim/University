//alocacao de matriz
//USUARIO VAI DIGITAR UM N (NUMERO DE CLIENTES)
//USUARIO VAI PREENCHER DADOS DOS N CLIENTES
//OS DADOS SAO:
//ALTURA, PESO, IMC: PESO/ALTURA² (ARMAZENAR EM UMA MATRIZ)
//O USARIO VAI DIGITAR O NUMERO DO CLIENTE (0,1,2...)
//O PROGRAMA VAI INFORMAR OS DADOS DO CLIENTE
// QUANDO O USUARIO DIGITAR UM NUMERO NEGATIVO,  
//O PROGRAMA FINALIZA

#include <stdio.h>
#include <stdlib.h>

int main(){
	int N; // numero de clientes;
	int cliente; // o numero informado do cliente
	float **dados;

	printf("digite a quantidade de clientes: ");
	scanf("%d", &N);

	//alocacao de um vetor com N ponteiros de float
	dados = (float **) malloc(sizeof(float *)*N);
	for(int i = 0; i < N; i++)
		dados[i] = (float *) malloc(sizeof(float)*3);
	
	//PRENCHENDO COM DADOS
	for(int i =0; i < N; i++){
		printf("\nPreencha os dados do cliente %d: \n",i);
		printf("\nAltura: ");
		scanf("%f", &dados[i][0]);
		printf("\nPeso: ");
		scanf("%f", &dados[i][1]);
		//Calculo
		dados[i][2] = (float) dados[i][1]/(dados[i][0]*dados[i][0]);
	}	
	
	printf("Digite o número do cliente");
	scanf("%d", &cliente);

	while(cliente != -1){
		printf("\nCliente número %d", cliente);
		printf("\nAltura do Cliente: %f", dados[cliente][0]);
		printf("\nPeso do Cliente: %f", dados[cliente][1]);
		printf("\nIMC do Cliente: %f", dados[cliente][2]);
		
		printf("\n\n Digite um novo número do cliente");
		scanf("%d", &cliente);	
	}	
	
	//DESALOCANDO MATRIZ
	for(int i = 0; i < N; i++){
		free(dados[i]);
	}
	free(dados);
	return 0;
}

