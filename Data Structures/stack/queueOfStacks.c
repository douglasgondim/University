#include <stdio.h>
#include <stdlib.h>

typedef struct node node;
typedef struct stack stack;
typedef struct queueNode queueNode;
typedef struct queue queue;

struct node{
	int data;
	node* next;
};

struct stack{
	node* top;
	int len;
};

struct queueNode{
	stack* element;
	queueNode* next;
};

struct queue{
	queueNode* head;
	queueNode* end;
	int len;
};

stack* createStack(){
	stack* newStack = (stack*) malloc(sizeof(stack));
	newStack->top = NULL;
	newStack->len = 0;
	return newStack;
}

void pushStack(stack* Stack, int data){
	node* newNode = (node*) malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	
	if(Stack->len==0){
	}else{
		newNode->next = Stack->top;
	}
	Stack->top = newNode;
	Stack->len++;
}

int popStack(stack* stack){
	if(stack->len>0){
		node* trash = stack->top;
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

queue* createQueue(){
	queue* newQueue = (queue*) malloc(sizeof(queue));
	newQueue->head = NULL;
	newQueue->end = NULL;
	newQueue->len =0;
	return newQueue;
}
void addQueue(queue* Queue, stack* Stack){
	queueNode* newQueueNode = (queueNode*) malloc(sizeof(queueNode));
	newQueueNode->element = Stack;
	newQueueNode->next = NULL;

	if(Queue->len==0){
		Queue->head = newQueueNode;
		Queue->end = newQueueNode;
	}else{
		Queue->end->next = newQueueNode;
		Queue->end = newQueueNode;
	}
	Queue->len++;
}

stack* removeQueue(queue* Queue){
	if(Queue->len>0){
		queueNode* trash = Queue->head;
		stack* removedStack = Queue->head->element;
		if(Queue->len==1){
			Queue->head = NULL;
			Queue->end = NULL;
		}else{
			Queue->head = Queue->head->next;
		}
		Queue->len--;
		free(trash);
		return removedStack;
	}
	return NULL;


}

void printStack(stack* Stack){
	node* aux = Stack->top;
	while(aux != NULL){
		printf("%d ", aux->data);
		aux = aux->next;
	}
}

void printQueue(queue* Queue){
	queueNode* aux = Queue->head;
	for(int i=0;i<Queue->len;i++){
		printStack(aux->element);
		aux = aux->next;
		printf("\n");		
	}

}


int main(){
	stack* stack1 = createStack();
	stack* stack2 = createStack();
	stack* stack3 = createStack();
	stack* stack4 = createStack();

	

	pushStack(stack1, 7);
	pushStack(stack1, 4);
	pushStack(stack1, 3);

	pushStack(stack2, 7);
	pushStack(stack2, 8);

	pushStack(stack4, 7);
	pushStack(stack4, 60);

	queue* queue = createQueue();

	addQueue(queue, stack1);
	addQueue(queue, stack2);
	// addQueue(queue, stack3);
	addQueue(queue, stack4);
	
	printQueue(queue);
	return 0;
}