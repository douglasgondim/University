#include <stdio.h>
int main(){
	int i,j;
	double M[12][12], result=0;
	char O;
	scanf("%c", &O);

	for(i=0; i<12;i++){
		for(j=0;j<12;j++){
			scanf("%lf", &M[i][j]);
		}
	}

	if(O=='S'){
		for(i=0;i<5;i++){
			for(j=i+1;j<11-i;j++){
				result+= M[j][i];
			}
		}
		printf("%.1lf\n", result);
	}

	if(O=='M'){
		for(i=0;i<5;i++){
			for(j=i+1;j<11-i;j++){
				result+= M[j][i];
			}
		}
		printf("%.1lf\n", result/30);
	}


	return 0;
}