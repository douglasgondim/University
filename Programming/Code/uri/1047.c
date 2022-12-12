#include <stdio.h>
int main(){
	int startH, startM, endH, endM, totalM;
	scanf("%d %d %d %d", &startH, &startM, &endH, &endM);
	totalM = (endH-startH)*60 + (endM-startM);
	
	if(totalM>0)
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", totalM/60, totalM%60);
	else if(totalM<=0 && endM>=startM)
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", 24+totalM/60, totalM%60);
	else
		printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", 23+totalM/60, 60+totalM%60);
	return 0;
}