#include <stdio.h>
#include <stdlib.h>
#include "no.h"

Node* root = NULL;

Node* Node_INIT(int key){
	Node* new_Node = malloc(sizeof(Node));
	new_Node->key = key;
	new_Node->parent = NULL;
	new_Node->right = NULL;
	new_Node->left = NULL;
	return new_Node;
}



Node* search(Node* pt, int key){
	if(pt==NULL){
		return NULL;
	}

	if(pt->key == key){
		return pt;
	}else{
		if(key > pt->key){
			if(pt->right != NULL){
				search(pt->right, key);
			}else{
				return pt;
			}

		}else{
			if(pt->left != NULL){	
				search(pt->left, key);
			}else{
				return pt;
			}
		}
	}

}

void insert(Node** pt, int key){
	Node* new_Node = Node_INIT(key);
	Node* freeNode = search(*pt, key);
	new_Node->parent = freeNode;

	if(freeNode == NULL){
		*pt = new_Node;
	}else if(key > freeNode->key){
		freeNode->right = new_Node;
	}else{
		freeNode->left = new_Node;
	}


}

Node* delete(Node** pt, int key){
	if((*pt) == NULL){
		return NULL;
	}

	if(key < (*pt)->key){
		delete(&(*pt)->left, key);
	}else if(key > (*pt)->key){
		delete(&(*pt)->right, key);
	}else{
		Node* toRemove;
		toRemove = *pt;
		if((*pt)->right == NULL){
			*pt = (*pt)->left;
			free(toRemove);
		}else if((*pt)->left == NULL){
			*pt = (*pt)->right;
			free(toRemove);
		}else{
			Node* replace = (*pt)->left;
			Node* prev = *pt;
			while(replace->right != NULL){
				prev = replace;
				replace = replace->right;
			}
			(*pt)->key = replace->key;
			if(prev != *pt){
				prev->right = replace->left;
			}else{
				prev->left = replace->left;
			}
			free(replace);
		}
	}

	

}

void printInOrder(Node* pt){
	if(pt->left != NULL)
		printInOrder(pt->left);

	printf("%d\n", pt->key);

	if(pt->right != NULL)
		printInOrder(pt->right);
	

}


void printPostOrder(Node* pt){
	if(pt->left != NULL)
		printPostOrder(pt->left);

	if(pt->right != NULL)
		printPostOrder(pt->right);

	printf("%d\n", pt->key);
	

}

void printPreOrder(Node* pt){
	printf("%d\n", pt->key);
	if(pt->left != NULL)
		printPreOrder(pt->left);

	if(pt->right != NULL)
		printPreOrder(pt->right);
	

}

int main(){
	insert(&root, 20);
	insert(&root, 18);
	insert(&root, 15);
	// insert(&root, 23);
	// insert(&root, 21);
	// insert(&root, 22);
	// insert(&root, 29);
	// insert(&root, 32);
	// insert(&root, 25);

	delete(&root, 18);
	// delete(&root, 15);
	printInOrder(root);
	
	return 0;
}