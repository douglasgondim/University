#include <stdio.h>
#include <stdlib.h>
int main(){
	int *vector, *vector_2, n, x1, v1, x2, v2;
	scanf("%d %d %d %d %d", &n, &x1, &v1, &x2, &v2);

	vector = (int*) malloc(sizeof(int)*n);
	vector_2 = (int*) malloc(sizeof(int)*n);

	for(int i=0; i<n; i++){
		vector[i] = x1 + (v1*i);
		vector_2[i] = x2 + (v2*i);
	}
	for(int i=0; i<n; i++){
		if(vector[i] == vector_2[i]){
			printf("SIM");
			return 0;
		}
	}
	printf("Não\n");
	return 0;
}