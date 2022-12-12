
#include <stdio.h>

int main(){
	int notas[5];
	//COMPORTAMENTO ANÔMALO
	//NAO EXCEDER O LIMITE DO VETOR
	notas[10000] = 100;
	printf("%d", notas[10000]);
	return 0;
}
