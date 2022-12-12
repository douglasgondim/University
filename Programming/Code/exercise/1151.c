#include <stdio.h>
int main(){
	int auxiliar, N, azinho, bezinho, i;
	scanf("%d", &N);
	azinho = bezinho= 1;
    
    printf("1 1");
	for(i = 0; i < N; i++){
		printf(" %d", azinho +bezinho );
		
		auxiliar = azinho+ bezinho;
		azinho = bezinho;
		bezinho = auxiliar;

		
	}
	

	return 0;
}



//CAN NO DO IT