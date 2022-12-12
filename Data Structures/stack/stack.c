#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "node.h"

node* top;
node* end;
int len=0;

void push(int data){
	node* newNode = malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL; 
	if(len==0){
		end = newNode;
	}else{
		newNode->next = top;
		top->prev = newNode;
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
			end = NULL;
		}else{
			top = top->next;
			top->prev = NULL;
		}
		free(trash);
		len--;
	}
	return aux;
}

int resultPostFixed(char* input){
	int i=0,num1, num2;
	while(input[i] != '\0'){
		if(input[i]!='+' && input[i]!='-' && input[i]!='*' && input[i]!='/'){
			push(input[i]-'0');
		}else{
			num2 = pop();
			num1 = pop();
			if(input[i]=='+'){
				push(num1+num2);
			}else if(input[i]=='-'){
				push(num1-num2);
			}else if(input[i]=='*'){
				push(num1*num2);
			}else if(input[i]=='/'){
				push(num1/num2);
			}				
		}
		i++;
	}
	return pop();
}

void print_stack(){
	int i;
	node* aux = top;
	for(i=0;i<len;i++){
		printf("%d\n", aux->data);
		aux = aux->next;
	}
}


int main(){
	char input[100];

	scanf("%[^\n]s", input);

	printf("%d\n", resultPostFixed(input));



	return 0;
}