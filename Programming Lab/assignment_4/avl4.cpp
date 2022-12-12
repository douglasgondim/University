#include <iostream>
#include <algorithm>

using namespace std;
#define COUNT 10

// chave structure that represents a node in the tree


typedef struct Node Node;

// class AVLTree implements the operations in AVL tree
template <typename TC, typename TV>
class AVLTree {
public:

struct Node {
	TC chave;
    TV valor;
	Node *esq, *dir, *pai;
	int bal;

    Node(TC chave, TV valor){
        this->chave = chave;
        this->valor = valor;
        esq = dir = pai = nullptr;
        bal = 0;
    } 

};
	Node* root;

	void printInOrderRec(Node* node) {
		if (node != nullptr) {
			printInOrderRec(node->esq);
			cout<<node->chave<<" ";
			printInOrderRec(node->dir);
		} 
	}

	Node* buscarRec(Node* node, TC c) {
		if (node == nullptr || c == node->chave) {
			return node;
		}

		if (c < node->chave) {
			return buscarRec(node->esq, c);
		} 
		return buscarRec(node->dir, c);
	}

	Node* removeRec(Node* node, TC c) {
		// search the c
		if (node == nullptr) return node;
		else if (c < node->chave) node->esq = removeRec(node->esq, c);
		else if (c > node->chave) node->dir = removeRec(node->dir, c);
		else {
			// the c has been found, now delete it

			// case 1: node is a leaf node
			if (node->esq == nullptr && node->dir == nullptr) {
				delete node;
				node = nullptr;
			}

			// case 2: node has only one child
			else if (node->esq == nullptr) {
				Node* temp = node;
				node = node->dir;
				delete temp;
			}

			else if (node->dir == nullptr) {
				Node* temp = node;
				node = node->esq;
				delete temp;
			}

			// case 3: has both children
			else {
				Node* temp = minimo(node->dir);
				node->chave = temp->chave;
                node->valor = temp->valor;
				node->dir = removeRec(node->dir, temp->chave);
			}

		} 

		// Write the update balance logic here 
		// YOUR CODE HERE

		return node;
	}

	


	// update the balance factor the node
	void atualizaBal(Node* node) {
		if (node->bal < -1 || node->bal > 1) {
			rebalance(node);
			return;
		}

		if (node->pai != nullptr) {
			if (node == node->pai->esq) {
				node->pai->bal -= 1;
			} 

			if (node == node->pai->dir) {
				node->pai->bal += 1;
			}

			if (node->pai->bal != 0) {
				atualizaBal(node->pai);
			}
		}
	}

	// rebalance the tree
	void rebalance(Node* node) {
		if (node->bal > 0) {
			if (node->dir->bal < 0) {
				rotacionaDir(node->dir);
				rotacionaEsq(node);
			} else {
				rotacionaEsq(node);
			}
		} else if (node->bal < 0) {
			if (node->esq->bal > 0) {
				rotacionaEsq(node->esq);
				rotacionaDir(node);
			} else {
				rotacionaDir(node);
			}
		}
	}


public:
	AVLTree() {
		root = nullptr;
	}

	// In-Order traversal
	// esq Subtree -> Node -> dir Subtree
	void inorder() {
		printInOrderRec(this->root);
	}

	// search the tree for the c k
	// and return the corresponding node
	Node* buscar(int k) {
		return buscarRec(this->root, k);
	}

	// find the node with the minimo c
	Node* minimo(Node* node) {
		while (node->esq != nullptr) {
			node = node->esq;
		}
		return node;
	}

	// find the node with the maximum c
	Node* maximum(Node* node) {
		while (node->dir != nullptr) {
			node = node->dir;
		}
		return node;
	}

	// find the successor of a given node
	Node* successor(Node* x) {
		// if the dir subtree is not null,
		// the successor is the esqmost node in the
		// dir subtree
		if (x->dir != nullptr) {
			return minimo(x->dir);
		}

		// else it is the lowest ancestor of x whose
		// esq child is also an ancestor of x.
		Node* y = x->pai;
		while (y != nullptr && x == y->dir) {
			x = y;
			y = y->pai;
		}
		return y;
	}


	// rotate esq at node x
	void rotacionaEsq(Node* x) {
		Node* y = x->dir;
		x->dir = y->esq;
		if (y->esq != nullptr) {
			y->esq->pai = x;
		}
		y->pai = x->pai;
		if (x->pai == nullptr) {
			this->root = y;
		} else if (x == x->pai->esq) {
			x->pai->esq = y;
		} else {
			x->pai->dir = y;
		}
		y->esq = x;
		x->pai = y;

		// update the balance factor
		x->bal = x->bal - 1 - max(0, y->bal);
		y->bal = y->bal - 1 + min(0, x->bal);
	}

	// rotate dir at node x
	void rotacionaDir(Node* x) {
		Node* y = x->esq;
		x->esq = y->dir;
		if (y->dir != nullptr) {
			y->dir->pai = x;
		}
		y->pai = x->pai;
		if (x->pai == nullptr) {
			this->root = y;
		} else if (x == x->pai->dir) {
			x->pai->dir = y;
		} else {
			x->pai->esq = y;
		}
		y->dir = x;
		x->pai = y;

		// update the balance factor
		x->bal = x->bal + 1 - min(0, y->bal);
		y->bal = y->bal + 1 + max(0, x->bal);
	}

	// insert the c to the tree in its appropriate position
	void insert(TC c, TV v) {
		// PART 1: Ordinary BST insert
		Node* node = new Node(c, v);
		
		Node* y = nullptr;
		Node* x = this->root;

		while (x != nullptr) {
			y = x;
			if (node->chave < x->chave) {
				x = x->esq;
			} else {
				x = x->dir;
			}
		}

		// y is pai of x
		node->pai = y;
		if (y == nullptr) {
			root = node;
		} else if (node->chave < y->chave) {
			y->esq = node;
		} else {
			y->dir = node;
		}

		// PART 2: re-balance the node if necessary
		atualizaBal(node);

	}


	// delete the node from the tree
	Node* remove(TC chave) {
		Node* deletedNode =  removeRec(this->root, chave);
		return deletedNode;
	}

	// print the tree structure on the screen
	void prettyPrint() {
		printHelper(this->root, "", true);
	}
       void print2DUtil(Node *raiz, int space)
{
    // Base case
    if (raiz == nullptr)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process dir child first
    print2DUtil(raiz->dir, space);
 
    // PrTC current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<< raiz->chave  << "[\"" << raiz->valor << "\"]"  << endl;

 
    // Process esq child
    print2DUtil(raiz->esq, space);
}
 
// Wrapper over print2DUtil()
void print2D(Node *raiz)
{
    // Pass initial space count as 0
    print2DUtil(raiz, 0);
}

};

int main() {
	AVLTree<int, string> bst;
	// bst.createSampleTree1();
	bst.insert(50, "a");
	bst.insert(30, "b");
	bst.insert(70, "c");
	bst.insert(23, "d");
    bst.insert(1, "e");
	bst.insert(5, "f");
	bst.insert(6, "g");


    // bst.remove(23);
	bst.remove(70);
	// bst.remove(23);
    bst.remove(50);
	bst.remove(30);
	bst.remove(6);



   	// bst.insert(30, "b");
	// bst.insert(70, "c");
	// bst.insert(23, "d");
    // bst.insert(1, "e");
	// bst.insert(5, "f");
	// bst.insert(6, "g");
    // bst.insert(6, "h");
    // bst.remove(6);

    
    bst.print2D(bst.root);
	// bst.prettyPrint();
	return 0;
}