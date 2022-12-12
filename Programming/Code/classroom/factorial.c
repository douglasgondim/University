// find factorial interactive and recursive

#include <stdio.h>

int fact(int a){
	int aux=1;
	for(int i=1; i<=a; i++){
		aux = aux * i;
	}
	return aux;
}

int recFact(int a){
	if (a==0 || a==1){
		return 1;
	}else{
		return recFact(a-1) * a;
	}
}

int terRecFact(int a){
	return (a==0 || a==1) ? 1 : terRecFact(a-1) * a;
}

int main(){
	int num, result;
	scanf("%d", &num);
	result = terRecFact(num);
	printf("%d\n", result);


	return 0;
}