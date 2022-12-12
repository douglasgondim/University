
#include <stdio.h>

//MULTIPLICACAO MATRICIAL NxN

#define N 100

int main(){
	int A[N][N];
	int B[N][N];
	int C[N][N];
	int n; //tamanho informado pelo usuario, até no maximo 100
	printf("informe a dimensão da matriz: ");
	scanf("%d", &n);
	
	if(n > N){
		printf("valor muito alto");
		return 0;
	}
	
	printf("informe a primeira matriz\n");
	for(int i =0; i < n; i++){
		for(int j=0; j < n; j++){
			printf("posicao %d %d", i,j);
			scanf("%d", &A[i][j]);
		}
	}
	printf("informe a segunda matriz\n");
	for(int i =0; i < n; i++){
		for(int j=0; j < n; j++){
			printf("posicao %d %d", i,j);
			scanf("%d", &B[i][j]);
		}
	}
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			C[i][j]= 0;
			for(int k =0;k<n;k++){
					C[i][j] += A[i][k]*B[k][j];
				}
			}
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%5d ",C[i][j]);
			}
			printf("\n");
		}
	
	
	
	
	
	
	
	
	return 0;
}
