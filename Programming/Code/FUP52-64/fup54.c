
#include <stdio.h>

//tipo_de_retorno nome_funcao( tipo pam1, ..., tipo pamn);

int mensagem_1 (){
	printf("\nHello World");
	return 0;
}

int mensagem_2 (){
	printf("\nFora Temer");
	return 0;
}

int mensagem_3 (){
	printf("\nPower Life");
	return 0;
}

int mensagem_4(int n){
	printf("\nA mensalidade é: %d", n);
	return 0;
}


int main(){
	int (*funct[3])();
	mensagem_1();
	mensagem_2();
	mensagem_3();		
	mensagem_4(50);
	
	funct[0] = &mensagem_1;
	funct[1] = &mensagem_2;
	funct[2] = &mensagem_3;
	
	for(int i =0; i < 3; i++){
		funct[i]();
	}


	return 0;
}
