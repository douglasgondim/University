#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *head;
Node *end;
int len = 0;

void addBeggining(int data){
	Node *new = malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	if(head==NULL)
		end = new;
	else
		new->next = head;
	
	head = new;
	len++;

}

void addEnd(int data){
	Node *new = malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	if(head==NULL)
		head = new;
	else
		end->next = new;
	end = new;
	len++;
}

void addPosition(int position, int data){
	int i;
	if(position>=0 && position<=len){
		if(position==0)
			addBeggining(data);
		else if(position==len)
			addEnd(data);
		else{
			Node *aux = head;
			Node *new = malloc(sizeof(Node));
			new->data = data;
			new->next = NULL;
			for(i=0;i<position-1;i++){
				aux=aux->next;
			}
			new->next=aux->next;
			aux->next = new;
			len++;
		}
	}

}

void removeBeggining(){
	int i;
	if(len==0)
		printf("No items to remove\n");
	else if(len==1){
		free(head);
		head = NULL;
		end = NULL;
		len--;
	}else{
		Node *aux = head;
		head = head->next;
		free(aux);
		len--;	
	}
}

void removePosition(int position){
	int i;
	if(position>=0 && position<len && len>0){
		if(position==0)
			removeBeggining();
		else{
			Node *aux = head;
			for(i=0;i<position-1;i++){
				aux=aux->next;
			}
			aux->next = aux->next->next;
			len--;

		}
	}
}


void display(){
	int i;
	Node *aux = head;
	for(i=0;i<len;i++){
		printf("%d\n", aux->data);
		aux = aux->next;
	}
}



int main(){
	addPosition(0,6);
	addPosition(1,4);
	addPosition(2,7);
	removePosition(3);
	display();



	return 0;
}