#include <bits/stdc++.h>
 using namespace std;
#define COUNT 10

struct node {
    int data{};
    node* left = nullptr;
    node* right = nullptr;
    node* parent = nullptr;
    int height;
};

class AVL_SEARCH_TREE{


    public:
    node* root;
        AVL_SEARCH_TREE() : root(nullptr) {}

        node* GetRoot() { return root; }

        int max(int a, int b) { return (a > b ? a : b); }

        void InsertNode(int stuff) {
           if(root == nullptr){
               root = new node();
               root->data = stuff;
               cout << "Element inserted.\n";
               root->height = 0;
               root->parent = nullptr;
           }
           else {
               auto linker = GetRoot();
               node* newnode = new node();
               newnode->data = stuff;

               while(linker != nullptr){
                   if(linker->data > stuff){
                       if(linker->left == nullptr){
                           linker->left = newnode;
                           newnode->height = 0;
                           newnode->parent = linker;
                           cout << "Element inserted.\n"; break; }
                       else { linker = linker->left; }
                   } else {
                       if(linker->right == nullptr){
                           linker->right = newnode;
                           newnode->height = 0;
                           newnode->parent = linker;
                           cout << "Element inserted.\n"; break; }
                       else {  linker = linker->right; }
                   }
               }
               Rebalancer(newnode);
           }
        }

        int GetHeight(node* temp) { return ((temp == nullptr) ? -1 : temp->height); }

        int BalanceFactor(node* temp) { return (GetHeight(temp->right) - GetHeight(temp->left)); }

        void HeightBalance(node* temp) {
            int l = -1, r = -1;
            if(temp->left){ l = temp->left->height; }
            if(temp->right){ r = temp->right->height; }
            temp->height = max(l, r) + 1; }

        void TreeFix(node* temp) {
            if(BalanceFactor(temp) == 2){
                if(BalanceFactor(temp->right) < 0){ RightRotate(temp->right); }
                LeftRotate(temp);
                HeightBalance(temp);
            }
            else if(BalanceFactor(temp) == -2){
                if(BalanceFactor(temp->left) > 0){ LeftRotate(temp->left); }
                RightRotate(temp);
                HeightBalance(temp);
            }
        }

        void Rebalancer(node* temp) {
           if(temp == root){ TreeFix(root); }
           else {
            while(temp != nullptr){
                HeightBalance(temp);
                temp = temp->parent;
                if(temp) { TreeFix(temp); }
            }
           }
        }

        void LeftRotate(node* x) {
            node* nw_node = new node();
            if(x->right->left) { nw_node->right = x->right->left; }
            nw_node->left = x->left;
            nw_node->data = x->data;
            x->data = x->right->data;

            x->left = nw_node;
            if(nw_node->left){ nw_node->left->parent = nw_node; }
            if(nw_node->right){ nw_node->right->parent = nw_node; }
            nw_node->parent = x;

            if(x->right->right){ x->right = x->right->right; }
            else { x->right = nullptr; }

            if(x->right){ x->right->parent = x; }

            HeightBalance(x->left);
            if(x->right){ HeightBalance(x->right); }
            HeightBalance(x);
        }

        void RightRotate(node* x) {
            node* nw_node = new node();
            if(x->left->right){ nw_node->left = x->left->right; }
            nw_node->right = x->right;
            nw_node->data = x->data;
            x->data = x->left->data;

            x->right = nw_node;
            if(nw_node->left){ nw_node->left->parent = nw_node; }
            if(nw_node->right){ nw_node->right->parent = nw_node; }
            nw_node->parent = x;

            if(x->left->left){ x->left = x->left->left; }
            else { x->left = nullptr; }

            if(x->left){ x->left->parent = x; }

            HeightBalance(x->right);
            if(x->left){ HeightBalance(x->left); }
            HeightBalance(x);
        }

        node* TreeSearch(int stuff) {
            auto temp = GetRoot();
            if(temp == nullptr) { return nullptr; }

            while(temp) {
                if(stuff == temp->data){ return temp; }
                else if(stuff < temp->data){ temp = temp->left; }
                else { temp = temp->right; }
            }
            return nullptr;
        }

        void PreorderTraversal(node* temp) {
            if(temp == nullptr){ return; }
            cout << "->" << temp->data;
            PreorderTraversal(temp->left);
            PreorderTraversal(temp->right);
        }

        void PostorderTraversal(node *temp) {
            if(temp == nullptr){ return; }
            PostorderTraversal(temp->left);
            PostorderTraversal(temp->right);
            cout << "->" << temp->data;
        }

        void RemoveNode(node* Parent, node* curr, int stuff) {
            if(curr == nullptr) { return; }
            if(curr->data == stuff) {
                //CASE -- 1
                if(curr->left == nullptr && curr->right == nullptr){
                    if(Parent->data == curr->data){ root = nullptr; }
                    else if(Parent->right == curr){ Parent->right = nullptr;  }
                    else { Parent->left = nullptr; }
                    Rebalancer(Parent);
                }
                //CASE -- 2
                else if(curr->left != nullptr && curr->right == nullptr) {
                    int sp = curr->data;
                    curr->data = curr->left->data;
                    curr->left->data = sp;
                    RemoveNode(curr, curr->left, stuff);
                }
                else if(curr->left == nullptr && curr->right != nullptr) {
                    int sp = curr->data;
                    curr->data = curr->right->data;
                    curr->right->data = sp;
                    RemoveNode(curr, curr->right, stuff);
                }
                //CASE -- 3
                else {
                    node* temp = curr->right;
                    int flag = 0;
                    while(temp->left){ flag = 1; Parent = temp; temp = temp->left; }
                    if(!flag){ Parent = curr; }
                    int sp = curr->data;
                    curr->data = temp->data;
                    temp->data = sp;
                    RemoveNode(Parent, temp, temp->data);
                }
            }
        }

        void Remove(int stuff){
            auto temp = root;
            auto Parent = temp;
            bool flag = false;
            if(temp == nullptr){ RemoveNode(nullptr, nullptr, stuff); }

            while(temp) {
                if(stuff == temp->data){ flag = true; RemoveNode(Parent, temp, stuff); break; }
                else if(stuff < temp->data){ Parent = temp ; temp = temp->left; }
                else { Parent = temp ; temp = temp->right; }
            }

            if(!flag){ cout << "Element doesn't exist in the table\n"; }
            else { cout << "Element removed.\n"; }
        }
        void print2DUtil(node *raiz, int space)
{
    // Base case
    if (raiz == nullptr)
        return;
 
    space += COUNT;
     print2DUtil(raiz->right, space);
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<< raiz->data  
    // << "[\"" << raiz->valor << "\"]"
      << endl;
 
    // Process left child
    print2DUtil(raiz->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(node *raiz)
{
    // Pass initial space count as 0
    print2DUtil(raiz, 0);
}
};

    int main(){
    AVL_SEARCH_TREE *bst = new AVL_SEARCH_TREE();
    bst->InsertNode(5);
    bst->InsertNode(6);
    bst->InsertNode(7);
    bst->InsertNode(1);
    bst->InsertNode(2);
    bst->InsertNode(3);
    bst->Remove(7);
    bst->Remove(6);
    // for(auto i = bst.inicio(); i != bst.fim(); ++i){
    //     cout << i.pointer->valor << " ";
    // }
    // bst.remover(bst.buscar(7));
    // bst.remover(bst.buscar(6));


    // // bst.remove(23);
	// bst.remove(70);
	// // bst.remove(23);
    // bst.remove(50);
	// bst.remove(30);
	// bst.remove(6);



   	// bst.insert(30, "b");
	// bst.insert(70, "c");
	// bst.insert(23, "d");
    // bst.insert(1, "e");
	// bst.insert(5, "f");
	// bst.insert(6, "g");
    // bst.insert(6, "h");
    // bst.remove(6);

    
    bst->print2D(bst->root);
       
    return 0;
}