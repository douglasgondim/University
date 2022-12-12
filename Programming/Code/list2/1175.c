#include <stdio.h>
#define qtt 20
int main(){
	int n[qtt], aux;

	for (int i=0; i<qtt; i++){
		scanf("%d", &n[i]);
	}

	for(int i=qtt-1; i=0; i--){
		aux = n[i];
		printf("hi ");
		for (int j=0; j<qtt; j++){
			n[i] = n[j];
			n[j] = aux;
			printf("there ");
		}
	}

	// for (int i=0; i<qtt; i++){
	// 	printf("%d ", n[i]);
	// }


	return 0;
}