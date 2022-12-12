#include <stdio.h>
int main(){
	int num[5],i, even, positive, negative;
	even=0;
	positive=0;
	negative=0;
	for(i=0;i<5;i++){
		scanf("%d", &num[i]);
		if(num[i]>0)
			positive++;
		else if(num[i]<0)
			negative++;
		if(num[i]%2==0)
			even++;
	}
	printf("%d valor(es) par(es)\n", even);
	printf("%d valor(es) impar(es)\n", 5-even);
	printf("%d valor(es) positivo(s)\n", positive);
	printf("%d valor(es) negativo(s)\n", negative);

	return 0;
}