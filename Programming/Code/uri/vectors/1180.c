#include <stdio.h>
int main(){
	int X[1000], n, smaller, position;
	scanf("%d", &n);

	scanf("%d", &X[0]);
	
	for (int i=1; i<n; i++){
		scanf("%d", &X[i]);
		if (X[i] < X[0]){
			smaller = X[i];
			position = i;
		}else{
			smaller = X[0];
			position = 0;
		}
	}
	printf("Menor valor: %d\n", smaller);
	printf("Posicao: %d\n", position);



	return 0;
}