#include <stdio.h>
int main(){
	int g;
	float j, i;
	i=0;
	j=1;
	while(i<=2){
		g=0;
		while(g<3){
			printf("I=%d", i);
			printf(" J=%.0f\n", j);
			j++;
			g++;
		}
		g=0;
		j=j+0.2;
		i=i+0.2;		
		i++;
	}	

	return 0;
}