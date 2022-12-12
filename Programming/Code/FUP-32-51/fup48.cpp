
#include <iostream>
#include <cstdio>
using namespace std;

int somaMaisUm(int &a){
	a = a + 1;
	return a;
}

int main(){
	int n,result;
	scanf("%d", &n);
	result = somaMaisUm(n);
	printf("\nresultado: %d", result);
	printf("\nvalor de n: %d", n);

	return 0;
}
