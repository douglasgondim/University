#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct stack Stack;

struct node{
	int data;
	Node* next;
};

struct stack{
	Node* top;
	int len;
};

Stack* stackA;
Stack* stackB;
Stack* stackC;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;

}

Stack* createStack(){
	Stack* newStack = (Stack*) malloc(sizeof(Stack));
	newStack->top = NULL;
	newStack->len = 0;
	return newStack;
}


void pushStack(Stack* stack, int data){
	Node* newNode = createNode(data);
	if(stack->len==0){
	}else{
		newNode->next = stack->top;
	}
	stack->top = newNode;
	stack->len++;

}
int popStack(Stack* stack){
	if(stack->len>0){
		Node* trash = stack->top;
		int aux = stack->top->data;
		if(stack->len==1){
			stack->top = NULL;
		}else{
			stack->top = stack->top->next;
		}
		free(trash);
		stack->len--;
		return aux;
	}
	return -1;
}



void pushBox(Stack* stack, int weight){
	// Node* newNode = createNode(weight);
	if(stack->top == NULL){
		pushStack(stack, weight);
	}else{
		while((stack->top != NULL) && (weight > stack->top->data)){
			if(stack->top->data == 3){
				pushStack(stackC,3); 
				popStack(stack);
			}else if(stack->top->data == 5){
				pushStack(stackB, 5);
				popStack(stack);
			}

		}

		pushStack(stack, weight);

		// while(stackB->len > 0){
		// 	pushStack(stack, popStack(stackB));
		// }
		// while(stackC->len>0){
		// 	pushStack(stack, popStack(stackC));
		// }

		
	}

}



void printStack(Stack* stack){
	Node* aux = stack->top;
	int i;
	for(i=0;i<stack->len;i++){
		printf("%d\n", aux->data);
		aux = aux->next;
	}
}

int main(){
	Stack* stackA = createStack();
	Stack* stackB = createStack();
	Stack* stackC = createStack();

	pushBox(stackA, 3);
	pushBox(stackA, 5);
	// pushBox(stackA, 7);
	// pushBox(stackA, 5);
	// pushBox(stackA, stackB, stackC, 7);
	// printStack(stackA);


	return 0;
}