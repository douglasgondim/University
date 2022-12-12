//ORDENAR UM VETOR

#include <stdio.h>
//AUTORES: GABRIEL CANDEIA e GUILHERME NEPOMUCENO

int main(){
	int V[10],aux;
	for(int i=0;i<10;i++){
			scanf("%d",&V[i]);
			}
	for(int siz=10;siz;siz--){
		for(int i=1;i<siz;i++){
			if(V[i]<V[i-1]){
				aux=V[i-1];
				V[i-1]=	V[i];
				V[i] = aux;
			}
			}
	}
	for(int i=0;i<10;i++){
			printf("%d ",V[i]);
			}
	return 0;
}
