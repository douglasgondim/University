#include <stdio.h>
int main(){
	int vector[10], aux, count;
	for (int i=0; i<10; i++){
		scanf("%d", &vector[i]);	
	}

	count=0;
	for (int i=0; i<9; i++){
		for (int j=0; j<9-count; j++){
			if (vector[j]<vector[j+1]){
				aux = vector[j];
				vector[j] = vector[j+1];
				vector[j+1]=aux;
			}
		}
		count++;
	}

	for (int i=0; i<10; i++){
		printf("%d ", vector[i]);
	}

	return 0;
}