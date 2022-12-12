/* Use bubble sort algorithm to sort 
elements inside a vector*/

#include <stdio.h>
#define QTT 10
int main(){
	int vector[QTT], aux;
	for (int i=0; i<QTT; i++){
		scanf("%d", &vector[i]);
	}

	for (int j=QTT-1; j>0; j--){
		for (int i=0; i<j; i++){
			if(vector[i] > vector[i+1]){
				aux = vector[i];
				vector[i] = vector[i+1];
				vector[i+1] = aux;
			}
		}
	}

	for (int i=0; i<QTT; i++){
		printf("%d ", vector[i]);
	}


	return 0;
}