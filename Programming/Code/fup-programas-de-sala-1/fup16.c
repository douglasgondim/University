
//FACA UM PROGRAMA QUE CALCULE O PRODUTO ESCALAR
//DE DOIS VETORES DE 100 POSICOES

//PRODUTO ESCALAR DE A e B: 
//O USUARIO INFORMA OS VALORES DE A E B.
//A[0]*B[0] + A[1]*B[1] + ... +A[99]*B[99];
#include <stdio.h>
#define QTD 4
int main(){
	int a[QTD],b[QTD],soma=0;
	for(int i=0;i<QTD;i++){
		scanf("%d %d",&a[i], &b[i]);
		soma+=a[i]*b[i];
	}
	printf("%d", soma);
	return 0;
	}
