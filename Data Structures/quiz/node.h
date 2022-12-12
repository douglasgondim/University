#include <stdio.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
};

typedef struct node node;