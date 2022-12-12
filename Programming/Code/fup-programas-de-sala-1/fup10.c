//FAÇA UM PROGRAMA QUE CALCULA OS 20 PRIMEIROS
//NUMEROS DA SERIE DE FIBONACCI
//1 1 2 3 5 8 13 21 ...

#include <stdio.h>

int main(){
	int t1, t2, aux, cont;	
	t1=1;
	t2=1;
	for (cont=1;cont<=20;cont++){
		printf("%d ", t1);
		aux=t1+t2;
		t1=t2;
		t2=aux;
	}
	return 0;
}
