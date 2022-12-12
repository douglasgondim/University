#include <stdio.h>
#include <stdlib.h>
#include "no.h"
int main(){
	Node* aux = malloc(sizeof(Node));
	Node** aux2;
	aux2 = &aux;

	aux->key = 5;
	printf("%d\n", (*aux2)->key);


	return 0;
}