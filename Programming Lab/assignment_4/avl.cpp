#include <iostream>

using namespace std;
#define COUNT 10
template <typename TK, typename TV>
class AVLTree{
public:
    struct Node;
    Node *root;

    int height(Node * n){
        if(n==nullptr) return 0;
        return n->b;
    }
    int bal(Node* n){
        return height(n->left) - height(n->right);
    }

    void printInOrder(Node *p){
        if(p->left != nullptr) printInOrder(p->left);
        string left = "null", right = "null", parent = "null";
        if(p-> left != nullptr) left = to_string(p->left->key);
        if(p-> right != nullptr) right = to_string(p->right->key);
        if(p-> parent != nullptr) parent = to_string(p->parent->key);

        cout << "KEY: " << p->key << ", VALUE: " << p->value 
        // << ", LEFT: " << left << ", RIGHT: " << right <<  ", PARENT: " << parent 
        
        << endl;
        if(p->right != nullptr) printInOrder(p->right);
    }

    struct Node{
        Node *right, *left, *parent;
        int b;
        TK key;
        TV value;
        Node(TK key, TV value){
            this->key = key;
            this->value = value;
            this->right = this->left = this->parent = nullptr;
            this->b = 0;
        }
    };

    AVLTree(){
        this->root = nullptr;
    }

    void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == nullptr)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->key  << "[\"" << root->value << "\"]"  << endl;
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}


void rotateRight(Node *x){
    Node* y = x->left;
    x->left = y->right;
    y->right->parent = x->left;
    y->right = x;
    x->parent = y->right;
    x->b = max(height(x->left), height(x->right)) + 1;
    y->b = max(height(y->left), height(x->right)) + 1;

}

void rotateLeft(Node* x){
    Node* y = x->right;
    x->right = y->left;
    y->left->parent = x->right;
    y->left = x;
    x->parent = y->left;
    x->b = max(height(x->left), height(x->right)) + 1;
    y->b = max(height(y->left), height(x->right)) + 1;
}


    void insert(TK key, TV data){
        Node *newNode = new Node(key, data);
        if(root == nullptr) root = newNode;
        else{
            Node* aux = root;
            while(true){
                if(aux->right != nullptr && newNode->key >= aux->right->key){
                    aux = aux->right;
                }else if(aux->left != nullptr && newNode->key < aux->left->key){
                    aux = aux->left;
                }else if(aux->right == nullptr && newNode->key >= aux->key){
                    aux->right = newNode;
                    newNode->parent = aux;
                    break;
                }else if(aux->left == nullptr && newNode->key < aux->key){
                    aux->left = newNode;
                    newNode->parent = aux;
                    break;
                }
            }

            while(aux != nullptr){
                int bal = height(aux->left) - height(aux->right);
                if(bal>1){
                if(aux->key < aux->left->key){
                    rotateRight(aux);
                }else{
                    rotateLeft(aux->left);
                    rotateRight(aux);
                }
            }else if(bal<-1){
                if(aux->key > aux->right->key){
                    rotateLeft(aux);
                }else{
                    rotateRight(aux->right);
                    rotateLeft(aux);
                }
            }



                aux = aux->parent;
            }
        } 
    }
};



    // }
int main(){
    AVLTree<int, string> *av1 = new AVLTree<int, string>();
    av1->insert(5, "a");
    av1->insert(6, "b");    
    av1->insert(7, "c");
    av1->insert(10, "d");
    // av1->insert(4, "e");
    // av1->insert(3, "f");
    // av1->insert(11, "g");
    // av1->insert(12, "h");
    av1->print2D(av1->root);
    cout << "AVL Tree" << endl;
    return 0;
}