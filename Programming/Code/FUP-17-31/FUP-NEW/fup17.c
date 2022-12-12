
//DADO UM VETOR, COLOCA O MAIOR NUMERO NA ULTIMA POSICAOx
//O VETOR CONTINUA POSSUINDO OS MESMOS NUMEROS
//AUTORIA: GABRIEL CANDEIA
#include <stdio.h>

int main(){
	int V[10], maior, posicao;
	maior=-2147483648;
	for(int i=0;i<10;i++){
			scanf("%d",&V[i]);
			if(V[i]>maior){
					maior=V[i];
					posicao=i;
			}
	}
	for(int cont=posicao;cont<9;cont++){
			V[cont]=V[cont+1];
	}
	V[9]=maior;
	for(int i=0;i<10;i++){
			printf("%d\n",V[i]);
	}
	return 0;
}
