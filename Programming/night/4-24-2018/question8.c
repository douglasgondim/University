/*8. Faça um programa que leia 2 notas de um aluno, 
veriﬁque se as notas são válidas e exiba na tela a média destas notas. 
Uma nota válida deve ser, obrigatoriamente, um valor entre 0.0 e 10.0, 
onde caso a nota não possua um valor válido, 
este fato deve ser informado ao usuário e o programa termina.*/

#include <stdio.h>
int main(){
	float grade1, grade2, average;
	scanf("%f %f", &grade1, &grade2);
	if ((grade1 > 0 && grade1<10) && (grade2 > 0 &&grade2 < 10)){
		printf("%.2f", (grade1 + grade2 )/ 2 );
	}else{
		printf("Invalid Value");
	}


	return 0;
}