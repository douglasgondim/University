#include<iostream>
using namespace std;
#define COUNT 10

template <typename TC, typename TV>
class AVL{
    public:
        struct Noh{
          TC chave;
          TV valor;
          int bal;
          Noh *esq, *dir, *pai;
          Noh(TC chave, TV valor){
              this->chave = chave;
              this->valor = valor;
              this->bal = 1;
              this->esq = this->dir = this->pai = nullptr;
              
          }
        };
        AVL(){
          this->raiz = nullptr;
        }
        Noh *raiz;
        void inserir(TC chave, TV valor){
            Noh *toInsert = new Noh(chave, valor);
            raiz = inserirRec(raiz, toInsert, chave, valor);
            // cout << "No inserido: " << toInsert->chave << " Valor: " << toInsert->valor << endl;
        }
        void remove(TC chave){
            raiz = removeRec(raiz, chave);
        }
        Noh *buscar(TC chave){
            return buscarRec(raiz, chave);
        }
        void imprimeInOrder(){
            imprimeInOrderRec(raiz);
            cout << '\n';
        }
    private:
        int bal(Noh *n){ return (n == nullptr ? 0 : n->bal); }

        Noh *rotacionaDir(Noh *x){
            Noh *y = x->esq;
            x->esq = y->dir;
            if(y->dir != nullptr) y->dir->pai = x->esq;
            y->dir = x;
            if(x != nullptr) x->pai = y;
            x->bal = max(bal(x->esq), bal(x->dir)) + 1;
            y->bal = max(bal(y->esq), bal(y->dir)) + 1;
            return y;
        }

        Noh *rotacionaEsq(Noh *x){
            Noh *y = x->dir;
            x->dir = y->esq;
            if(y->esq != nullptr) y->esq->pai = x->dir;
            y->esq = x;
            if(x != nullptr) x->pai = y;
            x->bal = max(bal(x->esq), bal(x->dir)) + 1;
            y->bal = max(bal(y->esq), bal(y->dir)) + 1;
            return y;
        }

        void imprimeInOrderRec(Noh *p){
            if(p==nullptr) return ;
            imprimeInOrderRec(p->esq);
            TC parentKey = -1;
            if(p->pai != nullptr) parentKey = p->pai->chave;
            cout << p->chave << " "  << parentKey << endl ;
            imprimeInOrderRec(p->dir);
        }

        Noh *inserirRec(Noh *p, Noh* toInsert, TC chave, TV valor){
            if(p==nullptr){
                return toInsert;
            }else{

            if(chave > p->chave){
              p->dir = inserirRec(p->dir, toInsert, chave, valor);
              p->dir->pai = p;
            } 
            else if(chave < p->chave){
              p->esq = inserirRec(p->esq, toInsert, chave, valor);
              p->esq->pai = p;
            } 
            p->bal = max(bal(p->esq), bal(p->dir)) + 1;

            int nodeBal = bal(p->esq) - bal(p->dir);
            if(nodeBal<-1){
                if(chave > p->dir->chave){
                    return rotacionaEsq(p);
                }else{
                    p->dir = rotacionaDir(p->dir);
                    p->dir->pai = p;
                    return rotacionaEsq(p);
                }
            }else if(nodeBal > 1){
                if(chave < p->esq->chave){
                    return rotacionaDir(p);
                }else{
                    p->esq = rotacionaEsq(p->esq);
                    p->esq->pai = p;
                    return rotacionaDir(p);
                }
            }
            p->pai = nullptr;
            return p;


            }
        }
        Noh *removeRec(Noh *p, TC chave){
            if(p==nullptr) return p;
            if(chave < p->chave){
                p->esq = removeRec(p->esq, chave);
                // p->esq->pai = p;
            }else if(chave > p->chave){
                p->dir = removeRec(p->dir, chave);
                // p->dir->pai = p;
            }else{
                Noh *y = p->dir;
                if(p->esq == nullptr){
                    delete(p);
                    p = y;
                    if(y != nullptr) y->pai = p;
                }else if(p->dir == nullptr){
                    Noh *ln = p->esq;
                    delete(p);
                    p = ln;
                    if(ln != nullptr) ln->pai = p;
                }else{
                    while(y->esq!=nullptr) y = y->esq;
                    p->chave = y->chave;
                    p->dir = removeRec(p->dir, y->chave);
                }
            }
            if(p==nullptr) return p;
            p->bal = max(bal(p->esq), bal(p->dir))+ 1;
            int nodeBal = bal(p->esq) - bal(p->dir);
            if(nodeBal < -1){
                if(bal(p->dir) >= bal(p->esq)){
                    return rotacionaEsq(p);
                }else{
                    p->dir = rotacionaDir(p->dir);
                    // p->dir->pai = p;
                    return rotacionaEsq(p);
                }
            }else if(nodeBal > 1){
                if(bal(p->esq) >= bal(p->dir)){
                    return rotacionaDir(p);
                }else{
                    p->esq = rotacionaEsq(p->esq);
                    // p->esq->pai = p;
                    return rotacionaDir(p);
                }
            }
            return p;
        }
        Noh *buscarRec(Noh *p, TC chave){
            if(p == nullptr) return p;
            if(p->chave == chave) return p;
            if(p->chave) return buscarRec(p->esq, chave);
            if(p->chave) return buscarRec(p->dir, chave);
        }

public:
    void print2DUtil(Noh *raiz, int space)
{
    // Base case
    if (raiz == nullptr)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process dir child first
    print2DUtil(raiz->dir, space);
 
    // Print current node after space
    // count
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<< raiz->chave  << "[\"" << raiz->valor << "\"]"  << endl;
 
    // Process esq child
    print2DUtil(raiz->esq, space);
}
 
// Wrapper over print2DUtil()
void print2D(Noh *raiz)
{
    // Pass initial space count as 0
    print2DUtil(raiz, 0);
}
};

int main(){
    AVL<int, string> t;
    t.inserir(5, "a");
    t.inserir(6, "b");
    t.inserir(7, "c");
    t.inserir(1, "d");
    t.inserir(2, "e");
    t.inserir(3, "f");
    // t.remove(2);
    // t.remove(7);
    // t.imprimeInOrder();
    // t.remove(7);
    // t.remove(2);
    t.imprimeInOrder();
    // t.remove();
    // t.remove(7.9);
    // t.imprimeInOrder();
    t.print2D(t.raiz);
}

