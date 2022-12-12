#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

struct node{
	int data;
	struct node* next;
};


typedef struct node node;



node* head;
node* end;
int len=0;

void addOrdered(int data){
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if(len==0){
		head = newNode;
	}else{
		if(newNode->data < head->data){
			newNode->next = head;
			head = newNode;
		}else{	
		node* aux = head;
		while(aux->next!=NULL && (newNode->data > aux->next->data)){
			aux = aux->next;
		}
		newNode->next = aux->next;
		aux->next = newNode;
		if(aux->next==NULL){
			end = newNode;
		}
		}

	}
	len++;
	

}


void remove_(){
	if(len>0){
		node* aux = head;
		int i;
		for(i=0;i<len-1;i++){
			aux = aux->next;
		}
		node* trash = aux->next;
		aux->next = NULL;
		free(trash);
		len--;

	}
}

void print_List(){
	node* aux = head;
	int i;
	for(i=0;i<len;i++){
		printf("%d\n", aux->data);
		aux = aux->next;
	}
}


int list_size(){
	return len;
}



void print_backwards(){
	int i,j;
	for(i=0;i<len;i++){
		node* aux = head;

		for(j=0;j<len-1-i;j++){
			aux = aux->next;
		}

		printf("%d\n", aux->data);

	}
}

void print_backwardsR(node* aux){
	if(aux->next!=NULL){
		print_backwardsR(aux->next);
		printf("%d\n", aux->data);
	}
}

void printR(node* aux){
	if(aux->next!=NULL){
		printf("%d\n", aux->data);
		printR(aux->next);
	}
}

int main(){
	addOrdered(5);
	addOrdered(2);
	addOrdered(4);
	addOrdered(1);
	addOrdered(2);
	addOrdered(8);
	addOrdered(5);
	remove_();
	remove_();
	remove_();
	print_List();



	return 0;
}