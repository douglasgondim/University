#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "stackB.h"
#include "stackC.h"


node* top;
int len;

void push(int weight){
	node* newNode = malloc(sizeof(node));
	newNode->weight = weight;
	newNode->next=NULL;

	if(len==0){
	}else{
		while(top != NULL && newNode->weight > top->weight){
			if(top->weight==3){
				pushC(top);
				pop(top);
			}else if(top->weight==5){
				pushB(top);
				pop(top);
			}
		}
		newNode->next = top;
		top = newNode;
		while(lenB>0){
			push(topB->weight);
			popB();
		}
		while(lenC>0){
			push(topC->weight);
			popC();
		}



	}
	top = newNode;
	len++;

}

int pop(){
	node* trash = top;
	int aux = top->weight;
	if(len>0){
		if(len==1){
			top = NULL;
		}else{
			top = top->next;
		}
		free(trash);
		len--;
		return aux;
	}
}



void print_stack(){
	node* aux = top;
	int i;
	for(i=0;i<len;i++){
		printf("%d\n", aux->weight);
		aux = aux->next;
	}
}

int lenght(){
	return len;
}


int main(){
	

	return 0;
}