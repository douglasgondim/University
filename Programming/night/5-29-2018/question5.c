#include <stdio.h>
int main(){
	int vector[6], aux;
	for(int i=0; i<6; i++){
		scanf("%d", &vector[i]);
	}
	for(int i=0; i<6/2; i++){
		aux = vector[i];
		vector[i] = vector[5-i];
		vector[5-i] = aux;
	}
	for(int i=0; i<6; i++){
		printf("%d ", vector[i]);
	}

	return 0;
}