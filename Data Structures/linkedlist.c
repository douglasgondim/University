#include <stdio.h>
#include <stdlib.h>
#include "node.h"

node *head;
node *tail;
int len=0;

void add(int position, int data){
	int i;
	node *aux = head;
	node *new = malloc(sizeof(node));
	new->data = data;

	if(position>=0 && position<=len){
		if(len==0){
			head = new;
			tail = new;
		}
		if(position==0){
			new->next = head;
			head = new;
		}else if(position==len){
			tail->next = new;
		}else{
			for(i=0;i<position-1;i++){
				aux = aux->next;
			}
		new->next = aux->next;
		aux->next = new;
		}
		len++;
	}
}

void display(){
	node *aux;
	int i;
	aux = head;
	for(i=0;i<len;i++){
		printf("%d ", aux->data);
		aux = aux->next;
	}
}

int removeFirst(){
	int aux = head->data;
	head = head->next;
	len--;
	return aux;
}

int removeMiddle(){
	


}

int main(){

	add(0, 5);
	add(1, 6);
	add(0, 9);
	removeFirst();

	add(1, 2);
	add(2, 8);
	

	display();
	
	return 0;
}