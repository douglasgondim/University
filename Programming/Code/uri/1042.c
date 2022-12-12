#include <stdio.h>
int main(){
	int vector[3], vector2[3], aux, i, j;
	for(i=0; i<3; i++){
		scanf("%d", &vector[i]);
	}

	for(i=0; i<3; i++){
		vector2[i] = vector[i];
	}

	for(i=0; i<3; i++){
		for (j=0; j<2-i; j++){
			if(vector[j]>vector[j+1]){
				aux = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = aux;
			}
		}
	}

	for(i=0; i<3; i++){
		printf("%d\n", vector[i]);
	}
	printf("\n");
	for(i=0; i<3; i++){
		printf("%d\n", vector2[i]);
	}



	return 0;
}