#include <stdio.h>
#include <stdlib.h>
#include "node.h"


node* topC;
int lenC;

void pushC(node* newNode){
	if(lenC==0){
	}else{
		newNode->next = topC;
	}
	topC = newNode;
	lenC++;

}

int popC(){
	node* trash = topC;
	int aux = topC->weight;
	if(lenC>0){
		if(lenC==1){
			topC = NULL;
		}else{
			topC = topC->next;
		}
		free(trash);
		lenC--;
		return aux;
	}
}


int lenghtC(){
	return lenC;
}
