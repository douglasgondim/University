#include <stdio.h>
int main(){
	int g,i,j;
	i=1;
	j=2;
	while(i<10){
		j=j+5;
		g=0;
		while(g<3){
			printf("I=%d", i);
			printf(" J=%d\n", j);
			j--;
			g++;
		}
		i=i+2;
	}	

	return 0;
}