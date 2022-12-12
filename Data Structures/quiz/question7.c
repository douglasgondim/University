#include <stdio.h>
#include <stdlib.h>

struct node{
	char name[200];
	int accountNumber;
	int password;
	double balance;
	struct node* next;
	struct node* prev;

};

typedef struct node node;

node* head;
node* end;
int len=0;


void addBeggining(char name[200], int accountNumber, int password, double balance){
	node* newNode = malloc(sizeof(node));
	newNode->name = name;
	newNode->accountNumber = accountNumber;
	newNode->password = password;
	newNode->balance = balance;
	newNode->next = NULL;
	newNode->prev = NULL;

	if(len==0){
		head = newNode;
		end = newNode;
		len++;
	}else{
		
	}



}

int main(){


	return 0;
}