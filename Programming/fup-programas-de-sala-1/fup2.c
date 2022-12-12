#include <stdio.h>
#include <math.h>

int main(){
	int a,b,c;
	float delta, x1, x2;
	
	scanf("%d %d %d",&a,&b,&c);
	delta = b*b - 4*a*c; // calculo do delta
	if(delta >=0){ //caso possua raízes
		x1 = (-b + sqrt(delta))/(2*a);
		x2 = (-b - sqrt(delta))/(2*a);
		printf("As raízes são: %f e %f\n",x1,x2);
		//especificando duas casas decimais depois do ponto
		printf("As raízes são: %.2f e %.2f\n",x1,x2);
		
	}
	else{
		printf("Não possui raízes reais\n");
	}
	return 0;
}
