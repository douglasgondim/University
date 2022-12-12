#include <stdio.h>
#include <stdlib.h>
#include "node.h"


node* topB;
int lenB;

void pushB(node* newNode){

	if(lenB==0){

	}else{
		newNode->next = topB;
	}
	topB = newNode;
	lenB++;

}

int popB(){
	node* trash = topB;
	int aux = topB->weigth;
	if(lenB>0){
		if(lenB==1){
			topB = NULL;
		}else{
			topB = topB->next;
		}
		free(trash);
		lenB--;
		return aux;
	}
}


int lengthB(){
	return lenB;
}
