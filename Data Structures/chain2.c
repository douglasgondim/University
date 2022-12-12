#include <stdio.h>

Node head;
Node tail;
int len=0;

struct Node{
	int data;
	struct Node* next; 
};
typedef Node Node;

void add(int position, int data){
	Node new;
	new.data = data;
	if(len==0){
		head = new;
		tail = new;
	}else{
		if(position==len){
			end.next = new;
			end = new;
		}
	}
}



int main(){




	return 0;
}