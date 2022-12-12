#include <stdio.h>
int main(){
	int s, e;
	scanf("%d %d", &s, &e);
	if(s>=e)
		printf("O JOGO DUROU %d HORA(S)\n", 24-s+e);
	else
		printf("O JOGO DUROU %d HORA(S)\n", (24-s)-(24-e));

	return 0;
}