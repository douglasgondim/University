#include <stdio.h>
int main(){
	int N[20], aux;
	for (int i=0; i<20; i++){
		scanf("%d", &N[i]);
	}

	for (int i=0; i< 10; i++){
		aux = N[i];
		N[i] = N[19-i];
		N[19-i] = aux;
	}
	for (int i=0; i<20; i++){
		printf("%d ", N[i]);
	}


	return 0;
}