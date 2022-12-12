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
	int N, client;
	float **data;

	printf("Enter the number of clients: \n");
	scanf("%d", &N);

	data = (float**) malloc(sizeof(float*)*N);
	for(int i=0; i<N; i++){
		data[i] = (float*) malloc(sizeof(float)*3);
	}

	for(int i=0; i<N; i++){
		printf("Enter data to client %d \n", i);
		printf("Height(M): ");
		scanf("%f", &data[i][0]);
		printf("Weight(Kg): ");
		scanf("%f", &data[i][1]);
		data[i][2] = data[i][1]/(data[i][0]*data[i][0]);

	}

	printf("Client: ");
	scanf("%d", &client);

	while(client!=-1){
		printf("Height: %f\n", data[client][0]);
		printf("Weight: %f\n", data[client][1]);
		printf("BMI: %f\n", data[client][2]);

		printf("\nClient: \n");
		scanf("%d", &client);
	}



	for(int i=0; i<N; i++){
		free(data[i]);
	}
	free(data);

	return 0;
}