enum color {red, black};

struct RBNode{
    int data;
    bool color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;


    RBNode(int data, RBNode* nil){
        this->data = data;
        this->color = red;
        left = right = parent = nil;

    }
};

typedef RBNode RBNode;