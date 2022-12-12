
int findLevel(Node t, int data){
    int levels = 1;
    while(t != nullptr){
        if(t.data == data){
            return levels;
        }
        if(data > t.data){
            t = t->right;
        }else{
            t = t->left;
        }
        levels++;
    }
    return -1;
}