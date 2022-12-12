#include <iostream>
using namespace std;
#include "RBTree.h"



int main(){
    RBTree* tree1 = new RBTree();


    tree1->RBInsert(8);
    tree1->RBInsert(10);
    tree1->RBInsert(20);
    tree1->RBInsert(9);
    tree1->RBInsert(25);
    tree1->RBInsert(1);
    tree1->RBInsert(-5);
    tree1->RBInsert(7);
    tree1->RBInsert(11);
    tree1->printInOrder(tree1->root);


    // cout << tree1->root->data << endl;

    return 0;
}