#include "RBNode.h"

class RBTree{
    public:
        RBNode* root;
        RBNode* nil;
        RBTree(){
            nil = new RBNode(-1, NULL);
            nil->color = black;
            root = nil;
            nil->left = nil->right = nil->parent = nil;
        }
        void RBLeftRotate(RBTree* &T, RBNode* &x);
        void RBRightRotate(RBTree* &T, RBNode* &x);
        void RBInsert(int data);
        void RBInsertFixUp(RBTree* &T, RBNode* &z);
        void printInOrder(RBNode* p);




};

void RBTree::printInOrder(RBNode* p){
    if(p == this->nil) return;
    printInOrder(p->left);
    cout << p->data << endl;
    printInOrder(p->right);

}

void RBTree::RBLeftRotate(RBTree* &T, RBNode* &x){
    cout << "rotating left " << x->data<< endl;
    RBNode* y = x->right;
    x->right = y->left;
    if(y->left != T->nil){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == T->nil){
        T->root = y;
    }else if(x == x->parent->left){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
    
    y->left = x;
    cout << "y-.left = " << x->data << endl;
    x->parent = y;
    
}

void RBTree::RBRightRotate(RBTree* &T, RBNode* &x){
    cout << "rotating right" << endl;
    RBNode* y = x->left;
    x->left = y->right;
    if(y->right != T->nil){
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == T->nil){
        T->root = y;
    }else if(x == x->parent->right){
        x->parent->right = y;
    }else{
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}


void RBTree::RBInsert(int data){
    RBTree* T = this;
    RBNode* z = new RBNode(data, T->nil);
    RBNode* y = T->nil;
    RBNode* x = T->root;

    while(x != T->nil){
        y = x;
        if(z->data < x->data){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if(y == T->nil){
        T->root = z;
    }else if(z->data < y->data){
        y->left = z;
    }else{
        y->right = z;
    }

    z->left = T->nil;
    z->right = T->nil;
    z->color = red;
    RBInsertFixUp(T, z);
}

void RBTree::RBInsertFixUp(RBTree* &T, RBNode* &z){
    while(z->parent->color == red){
        if(z->parent == z->parent->parent->left){
            RBNode* y = z->parent->parent->right;
            if(y->color == red){
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }else if(z == z->parent->right){
                z = z->parent;
                RBLeftRotate(T, z);
            }
            z->parent->color = black;
            z->parent->parent->color = red;
            RBRightRotate(T, z->parent->parent);
        }else{
            RBNode* y = z->parent->parent->left;
            if(y->color == red){
                z->parent->color = black;
                y->color = black;
                z->parent->parent->color = red;
                z = z->parent->parent;
            }else if(z == z->parent->left){
                z = z->parent;
                RBRightRotate(T, z);
            }
            z->parent->color = black;
            z->parent->parent->color = red;
            RBLeftRotate(T, z->parent->parent);
        }
    }
    T->root->color = black;
}

