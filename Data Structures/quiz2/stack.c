#include <stdio.h>
#include <stdlib.h>
#include "node.h"


node* top;
node* end;
int len;

void push(int data){
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next=NULL;

	if(len==0){
	}else{
		newNode->next = top;
	}
	top = newNode;
	len++;

}

int pop(){
	node* trash = top;
	int aux = top->data;
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
		printf("%d\n", aux->data);
		aux = aux->next;
	}
}

int lenght(){
	return len;
}


int main(){
	push(4);
	push(3);
	push(2);
	print_stack();
	pop();
	print_stack();
	printf("%d\n", lenght());


	return 0;
}