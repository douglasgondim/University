

#include <stdio.h>

int main(){
	int n,i;
	
	scanf("%d",&n);
	
	//ISSO NAO FUNCIONA EM C ANTIGÃO!!!!
	
	int notas[n];
	//PODE ATE FUNCIONAR, MAS PODE ACONTECER 
	//COMPORTAMENTOS ANOMALOS
	for(i=0; i < n; i++){
		notas[i]=i;
	}
	for(i=0; i < n; i++){
		printf("%d\n", notas[i]);
	}
	
	printf("o valor digitado: %d\n", notas[0]); 
	
	return 0;
}
