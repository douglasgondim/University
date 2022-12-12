#include <iostream>
using namespace std;
#define COUNT 10

template <typename TC, typename TV>
class AVL {
   public:
    struct Noh {
        TC chave;
        TV valor;
        Noh *esq, *dir, *pai;
        int bal;

        Noh(TC chave, TV valor) {
            this->chave = chave;
            this->valor = valor;
            esq = dir = pai = nullptr;
            bal = 0;
        }
    };
    Noh *raiz;

    AVL() { raiz = nullptr; }

    void inserir(TC c, TV v) {
        Noh *novoNo = new Noh(c, v);
        if (raiz == nullptr) raiz = novoNo;
        else {
            Noh *aux = raiz;

            while (aux != nullptr) {
                if (aux->chave > c) {
                    if (aux->esq != nullptr) aux = aux->esq;
                    else {
                        aux->esq = novoNo;
                        novoNo->pai = aux;
                        break;    
                    }
                } else {
                    if (aux->dir != nullptr) aux = aux->dir;
                    else {
                        aux->dir = novoNo;
                        novoNo->pai = aux;
                        break;
                    }
                }
            }
            rebalanceia(novoNo);
        }
    }

    void bal(Noh *n) {
        int e = -1;
        int d = -1;
        if (n->esq) e = n->esq->bal;
        if (n->dir) d = n->dir->bal;
        n->bal = max(e, d) + 1;
    }

    int calcBal(Noh *n) { 
        if(n == nullptr) return -1;
        return n->bal;
    }
    void concertaArvore(Noh *n) {
        if (calcBal(n->dir) - calcBal(n->esq) == 2) {
            if (calcBal(n->dir->dir) - calcBal(n->dir->esq) < 0) rotacionaDir(n->dir);
            rotacionaEsq(n);
            bal(n);
        } else if (calcBal(n->dir) - calcBal(n->esq) ==-2) {
            if (calcBal(n->esq->dir) - calcBal(n->esq->esq) > 0) rotacionaEsq(n->esq);
            rotacionaDir(n);
            bal(n);
        }
    }

    void rebalanceia(Noh *n) {
        if (n == raiz) concertaArvore(raiz);
        else {
            while (n != nullptr) {
                bal(n);
                n = n->pai;
                if (n != nullptr) concertaArvore(n);
                
            }
        }
    }
    // void rotacionaDir(Noh *n) {
    //     Noh *m = n->esq;
    //     n->esq = m->dir;
    //     if (m->dir != nullptr) m->dir->pai = n;
    //     m->pai = n->pai;
    //     if (n->pai == nullptr) this->raiz = m;
    //     else if (n == n->pai->dir) n->pai->dir = m;
    //     else n->pai->esq = m;
    //     m->dir = n; n->pai = m;
    //     n->bal = n->bal - min(0, m->bal) + 1;
    //     m->bal = m->bal + max(0, n->bal) + 1;
    // }

    // void rotacionaEsq(Noh *n) {
    //     Noh *m = n->dir;
    //     n->dir = m->esq;
    //     if (m->esq != nullptr) m->esq->pai = n;
    //     m->pai = n->pai;
    //     if (n->pai == nullptr) this->raiz = m;
    //     else if (n == n->pai->esq)  n->pai->esq = m;
    //     else n->pai->dir = m;
    //     m->esq = n; n->pai = m;
    //     n->bal = n->bal - max(0, m->bal) - 1;
    //     m->bal = m->bal + min(0, n->bal) - 1;
    // }

 void rotacionaEsq(Noh* n) {
            Noh* newNode = new Noh(0, "");
            if(n->dir->esq) { newNode->dir = n->dir->esq; }
            newNode->esq = n->esq;
            newNode->chave = n->chave;
            n->chave = n->dir->chave;

            n->esq = newNode;
            if(newNode->esq){ newNode->esq->pai = newNode; }
            if(newNode->dir){ newNode->dir->pai = newNode; }
            newNode->pai = n;

            if(n->dir->dir){ n->dir = n->dir->dir; }
            else { n->dir = nullptr; }

            if(n->dir){ n->dir->pai = n; }

            bal(n->esq);
            if(n->dir){ bal(n->dir); }
            bal(n);
        }

        void rotacionaDir(Noh* n) {
            Noh* newNode = new Noh(0, "");
            if(n->esq->dir){ newNode->esq = n->esq->dir; }
            newNode->dir = n->dir;
            newNode->chave = n->chave;
            n->chave = n->esq->chave;

            n->dir = newNode;
            if(newNode->esq){ newNode->esq->pai = newNode; }
            if(newNode->dir){ newNode->dir->pai = newNode; }
            newNode->pai = n;

            if(n->esq->esq){ n->esq = n->esq->esq; }
            else { n->esq = nullptr; }

            if(n->esq){ n->esq->pai = n; }

            bal(n->dir);
            if(n->esq){ bal(n->esq); }
            bal(n);
        }


    void removerRec(Noh *ancestral, Noh *p, TC c) {
        if (p == nullptr) return;
        
        if (p->chave == c) {
            if (p->esq == nullptr && p->dir == nullptr) {
                if (ancestral->chave == p->chave) raiz = nullptr;
                else if (ancestral->dir == p) ancestral->dir = nullptr;
                else ancestral->esq = nullptr;
                rebalanceia(ancestral);
            }
            else if (p->esq != nullptr && p->dir == nullptr) {
                TC aux = p->chave;
                p->chave = p->esq->chave;
                p->esq->chave = aux;
                removerRec(p, p->esq, c);
            } else if (p->esq == nullptr && p->dir != nullptr) {
                TC aux = p->chave;
                p->chave = p->dir->chave;
                p->dir->chave = aux;
                removerRec(p, p->dir, c);
            }
            else {
                Noh *y = p->dir;
                bool muda = false;
                while (y->esq != nullptr) {
                    ancestral = y;
                    y = y->esq;
                    muda = true;
                }
                if (!muda)  ancestral = p;
                
                TC aux = p->chave;
                p->chave = y->chave;
                p->valor = y->valor;
                y->chave = aux;
                removerRec(ancestral, y, y->chave);
            }
        }
    }

    void remover(TC c) {
        Noh *aux = raiz;
        Noh *pai = aux;
        if (aux == nullptr) removerRec(aux, aux, c);
        
        while (aux != nullptr) {
            if (c == aux->chave) {
                removerRec(pai, aux, c);
                break;
            } else if (c < aux->chave) {
                pai = aux;
                aux = aux->esq;
            } else {
                pai = aux;
                aux = aux->dir;
            }
        }
    }

    Noh *buscar(TC c) {
        Noh *aux = raiz;
        if (aux == nullptr) return nullptr;
        
        while (aux != nullptr) {
            if (c == aux->chave) return aux;
            else if (c < aux->chave) aux = aux->esq;
            else aux = aux->dir;
        }

        return nullptr;
    }
    void print2DUtil(Noh *raiz, int space) {
        // Base case
        if (raiz == nullptr) return;

        // Increase distance between levels
        space += COUNT;

        // Process dir child first
        print2DUtil(raiz->dir, space);

        // PrTC pent Noh after space
        // count
        cout << endl;
        for (int i = COUNT; i < space; i++) cout << " ";
        cout << raiz->chave << "[\"" << raiz->valor << "\"]" << endl;

        // Process esq child
        print2DUtil(raiz->esq, space);
    }

    // Wrapper over print2DUtil()
    void print2D(Noh *raiz) {
        // Pass initial space count as 0
        print2DUtil(raiz, 0);
    }
    void imprimeInOrderRec(Noh *p) {
        if (p == nullptr) return;
        imprimeInOrderRec(p->esq);
        int parentKey = -1;
        if (p->pai != nullptr) parentKey = p->pai->chave;
        cout << p->chave << " " << parentKey << endl;
        imprimeInOrderRec(p->dir);
    }
};

int main() {
    AVL<int, string> *bst = new AVL<int, string>();
    bst->inserir(5, "a");
    bst->inserir(6, "b");
    bst->inserir(7, "c");
    bst->inserir(1, "d");
    bst->inserir(2, "e");
    bst->inserir(3, "f");

    bst->remover(7);
    bst->remover(6);
    // bst->remover(1);
    // bst->remover(5);
    // bst->remover(6);

    // bst->inserir(70, "c");
    // bst->inserir(23, "d");
    // bst->inserir(1, "e");
    // bst->inserir(5, "f");
    // bst->inserir(6, "g");

    // bst->inserir(30);
    // // bst->inserir(70);
    // bst->inserir(23);
    // bst->inserir(1);
    // bst->inserir(5);

    // bst->remover(6);

    bst->print2D(bst->raiz);
    bst->imprimeInOrderRec(bst->raiz);

    return 0;
}