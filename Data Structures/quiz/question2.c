#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};


typedef struct node node;



node* head;
int len=0;

void addBeginning(int data){
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next= NULL;
	if(len==0){

	}else{
		newNode->next = head;
	}
	head = newNode;
	len++;

}

void addEnd(int data){
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	if(len==0){
		head = newNode;
	}else{
		node* aux = head;
		int i;
		for(i=0;i<len-1;i++){
			aux=aux->next;
		}
		aux->next = newNode;
	}
	len++;

}

void addPosition(int position, int data){
	if(position>=0 && position<=len){
		if(position==0){
			addBeginning(data);
		}else if(position==len){
			addEnd(data);
		}
		else{
			node* newNode = malloc(sizeof(node));
			newNode->data = data;
			newNode->next = NULL;
			node* aux = head;
			int i;
			for(i=0;i<position-1;i++){
				aux = aux->next;
			}
			newNode->next = aux->next;
			aux->next = newNode;
			len++;

		}
	}
}

void rmBeginning(){
	if(len>0){
		node* trash = head;
		if(len==1){
			head = NULL;
		}else{
			head = head->next;
		}
		free(trash);
		len--;
	}
}

void rmEnd(){
	if(len>0){
		node* aux = head;
		if(len==1){
			head = NULL;
			free(aux);
		}else{
			int i;
			for(i=0;i<len-1;i++){
				aux=aux->next;
			}
			node* trash = aux->next;
			aux->next= NULL;
			free(trash);

		}
		len--;
	}

}

void rmPosition(int position){
	if(position>=0 && position<len && len>0){
		if(position==0){
			rmBeginning();
		}else if(position==len-1){
			rmEnd();
		}else{
			node* aux = head;
			int i;
			for(i=0;i<position-1;i++){
				aux=aux->next;
			}
			node* trash = aux->next;
			aux->next = aux->next->next;
			free(trash);
			len--;
		}
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


int main(){

	addBeginning(5);
	addBeginning(3);
	addBeginning(2);
	addEnd(6);
	addEnd(4);
	addEnd(3);
	addPosition(0,7);
	addPosition(7,8);
	addPosition(1,6);
	addPosition(7,5);
	rmBeginning();
	rmEnd();
	rmEnd();
	rmPosition(0);
	rmPosition(5);
	rmPosition(1);
	rmPosition(2);

	print_List();
	printf("List size: %d\n", list_size());



	return 0;
}