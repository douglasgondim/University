#include <stdio.h>

typedef struct{
	int data;
	node* next;

}node;


typedef struct{
	node* top;
}stack;


node* nodeInit(int data){
	node* newNode;
	newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;

}

stack* stackInit(){
	stack* newStack;
	newStack = malloc(sizeof(stack));
	newStack->top = NULL;
	return newStack;
}



int main(){

	return 0;
}