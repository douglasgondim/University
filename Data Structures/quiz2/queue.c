#include <stdio.h>
#include <stdlib.h>
#include "node.h"


node* front;
node* rear;
int len=0;

void enqueue(int data){
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if(len==0){
		front = newNode;
		rear = newNode;
	}else{
		rear->next = newNode;
		rear = newNode;
	}
	len++;
}

int dequeue(){
	node* trash = front;
	int aux = front->data;
	if(len>0){
		if(len==1){
			front = NULL;
			rear = NULL;
		}else{
			front = front->next;
		}
		free(trash);
		len--;
		return aux;
	}
}

void print_queue(){
	node * aux = front;
	int i;
	for(i=0;i<len;i++){
		printf("%d\n", aux->data);
		aux = aux->next;
	}
}

int main(){

	enqueue(6);
	enqueue(3);
	enqueue(4);
	dequeue();
	print_queue();
	return 0;
}