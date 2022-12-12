#include <stdio.h>
#include <stdlib.h>
int main(){
	int *v, aux, n;
	scanf("%d", &n);

	v = (int*) malloc(n*sizeof(int));

	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(v[j]>v[j+1]){
				aux=v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
		}
	}

	for(int i=0; i<n; i++){
		printf("%d ", v[i]);
	}

	free(v);


	return 0;
}