#include <stdio.h>
#define QTT 10
	int main(){
	int j,values[QTT], aux;
	for (int i=0; i<QTT;i++){
		scanf("%d", &values[i]);
	}
	j=0;
	while(j!=9){
		j=0;
		for(int i=0; i< QTT-1; i++){
			if (values[i] > values[i+1]){
				aux = values[i];
				values[i] = values[i+1];
				values[i+1] = aux;
			}else{
				j++;
			}
		}	
	}
	
	for(int i=0; i< QTT; i++){
		printf("%d ", values[i]);
	}

		return 0;
	}