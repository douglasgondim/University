#include <stdio.h>
int main(){
	int aux, j, a[5];
	for(int i=0; i<5; i++){
		scanf("%d", &a[i]);
	}

    for (int i = 1; i < 5; i++){
    	aux = a[i];
    	j = i-1;
 
    while (j >= 0 && a[j] > aux){
    	a[j+1] = a[j];
    	j = j-1;
    	}
    a[j+1] = aux;
   }


	for(int i=0; i<5; i++){
		printf("%d ", a[i]);
	}


	return 0;
}