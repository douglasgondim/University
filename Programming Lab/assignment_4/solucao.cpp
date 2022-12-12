// Nome: José Douglas Gondim Soares
// Matrícula: 485347

using namespace std;
template <typename TC, typename TV>
class DicioAVL {
   public:
    struct Noh {
        TC chave;
        TV valor;
        int bal;
        Noh *esq, *dir, *pai;
        Noh(TC chave, TV valor) {
            this->chave = chave;
            this->valor = valor;
            this->bal = 0;
            this->esq = this->dir = this->pai = nullptr;
        }

        Noh *obter_dir() { return this->dir; }
        Noh *obter_esq() { return this->esq; }
        Noh *obter_pai() { return this->pai; }
    };

   private:
    void desacolaArvore(Noh *n) {
        if (n == nullptr) return;
        desacolaArvore(n->esq);
        desacolaArvore(n->dir);
        delete n;
    }
    void bal(Noh *n) {
        int e = -1;
        int d = -1;
        if (n->esq) e = n->esq->bal;
        if (n->dir) d = n->dir->bal;
        if(e >= d) n->bal = e + 1;
        else n->bal = d + 1;
    }

    int calcBal(Noh *n) {
        if (n == nullptr) return -1;
        return n->bal;
    }
    void concertaArvore(Noh *n) {
        if (calcBal(n->dir) - calcBal(n->esq) > 1) {
            if (calcBal(n->dir->dir) - calcBal(n->dir->esq) < 0)
                rotacionaDir(n->dir);
            rotacionaEsq(n);
            bal(n);
        } else if (calcBal(n->dir) - calcBal(n->esq) < -1) {
            if (calcBal(n->esq->dir) - calcBal(n->esq->esq) > 0)
                rotacionaEsq(n->esq);
            rotacionaDir(n);
            bal(n);
        }
    }

    void rebalanceia(Noh *n) {
        if (n == obter_raiz())
            concertaArvore(obter_raiz());
        else {
            while (n != nullptr) {
                bal(n);
                n = n->pai;
                if (n != nullptr) concertaArvore(n);
            }
        }
    }
    void rotacionaDir(Noh *n) {
        Noh *novoNo = new Noh(n->chave, n->valor);
        if (n->esq->dir != nullptr) novoNo->esq = n->esq->dir;
        novoNo->dir = n->dir;
        n->chave = n->esq->chave;
        n->valor = n->esq->valor;
        n->dir = novoNo;
        if (novoNo->esq != nullptr) novoNo->esq->pai = novoNo;
        if (novoNo->dir != nullptr) novoNo->dir->pai = novoNo;
        novoNo->pai = n;
        if (n->esq->esq != nullptr)
            n->esq = n->esq->esq;
        else
            n->esq = nullptr;
        if (n->esq != nullptr) n->esq->pai = n;
        bal(n->dir);
        if (n->esq != nullptr) bal(n->esq);
        bal(n);
    }
    void rotacionaEsq(Noh *n) {
        Noh *novoNo = new Noh(n->chave, n->valor);
        if (n->dir->esq != nullptr) novoNo->dir = n->dir->esq;
        novoNo->esq = n->esq;
        n->chave = n->dir->chave;
        n->valor = n->dir->valor;
        n->esq = novoNo;
        if (novoNo->esq != nullptr) novoNo->esq->pai = novoNo;
        if (novoNo->dir != nullptr) novoNo->dir->pai = novoNo;
        novoNo->pai = n;
        if (n->dir->dir != nullptr)
            n->dir = n->dir->dir;
        else
            n->dir = nullptr;
        if (n->dir != nullptr) n->dir->pai = n;
        bal(n->esq);
        if (n->dir != nullptr) bal(n->dir);
        bal(n);
    }

    void removerRec(Noh *ancestral, Noh *p, TC c) {
        if (p == nullptr) return;
        if (p->chave == c) {
            if (p->esq == nullptr && p->dir == nullptr) {
                if (ancestral->chave == p->chave)
                    raiz = nullptr;
                else if (ancestral->dir == p)
                    ancestral->dir = nullptr;
                else
                    ancestral->esq = nullptr;
                rebalanceia(ancestral);
            } else if (p->esq != nullptr && p->dir == nullptr) {
                TC aux = p->chave;
                p->chave = p->esq->chave;
                p->esq->chave = aux;
                removerRec(p, p->esq, c);
            } else if (p->esq == nullptr && p->dir != nullptr) {
                TC aux = p->chave;
                p->chave = p->dir->chave;
                p->dir->chave = aux;
                removerRec(p, p->dir, c);
            } else {
                Noh *y = p->dir;
                bool muda = false;
                while (y->esq != nullptr) {
                    ancestral = y;
                    y = y->esq;
                    muda = true;
                }
                if (!muda) ancestral = p;

                TC aux = p->chave;
                p->chave = y->chave;
                p->valor = y->valor;
                y->chave = aux;
                removerRec(ancestral, y, y->chave);
            }
        }
    }


    Noh *minChave(Noh *node) {
        Noh *aux = node;
        while (aux->esq != nullptr) aux = aux->esq;
        return aux;
    }

    Noh *raiz;

   public:
    Noh *obter_raiz() { return raiz; }

    DicioAVL() { this->raiz = nullptr; }

    ~DicioAVL() { 
        desacolaArvore(obter_raiz());
        raiz = nullptr;
    }

    class Iterador {
       private:
        Noh *minChave(Noh *node) {
            Noh *aux = node;
            while (aux->esq != nullptr) aux = aux->esq;
            return aux;
        }

        Noh *successor(Noh *x) {
            if (x->dir != nullptr) return minChave(x->dir);

            Noh *y = x->pai;
            while (y != nullptr && x == y->dir) {
                x = y;
                y = y->pai;
            }
            return y;
        }

       public:
        Noh *pointer;

        Iterador(Noh *pointer) { this->pointer = pointer; }

        bool operator!=(Iterador j) {
            if (pointer == nullptr) return j.pointer != nullptr;
            if (j.pointer == nullptr) return pointer != nullptr;
            return pointer->chave != j.pointer->chave;
        }

        bool operator==(Iterador j) {
            if (pointer == nullptr) return j.pointer == nullptr;
            if (j.pointer == nullptr) return pointer == nullptr;
            return pointer->chave == j.pointer->chave;
        }

        TC chave() { return pointer->chave; }

        TV valor() { return pointer->valor; }

        void operator++() { this->pointer = successor(this->pointer); }
    };

    Iterador inicio() {
        Noh *aux = minChave(obter_raiz());
        Iterador it(aux);
        return it;
    }

    Iterador fim() {
        Iterador it(nullptr);
        return it;
    }

    Iterador inserir(TC c, TV v) {
        Noh *novoNo = new Noh(c, v);
        if (novoNo == nullptr) {
            Iterador it(nullptr);
            return it;
        }
        if (obter_raiz() == nullptr)
            raiz = novoNo;
        else {
            Noh *aux = obter_raiz();

            while (aux != nullptr) {
                if (aux->chave > c) {
                    if (aux->esq != nullptr)
                        aux = aux->esq;
                    else {
                        aux->esq = novoNo;
                        novoNo->pai = aux;
                        break;
                    }
                } else {
                    if (aux->dir != nullptr)
                        aux = aux->dir;
                    else {
                        aux->dir = novoNo;
                        novoNo->pai = aux;
                        break;
                    }
                }
            }
            rebalanceia(novoNo);
        }
        Iterador it(novoNo);
        return it;
    }

    Iterador buscar(TC c) {
        Noh *aux = obter_raiz();
        while (true) {
            if (aux == nullptr) {
                Iterador it(nullptr);
                return it;
            }
            if (aux->chave == c) {
                Iterador it(aux);
                return it;
            } else if (c < aux->chave) {
                aux = aux->esq;
            } else {
                aux = aux->dir;
            }
        }
    }

    void remover(Iterador i) {
        if (i.pointer == nullptr) return;
        if (i.pointer->pai == nullptr){
            return removerRec(nullptr, nullptr, i.pointer->chave);
        }
        removerRec(i.pointer->pai, i.pointer, i.pointer->chave);
    }
};

// int main() {
//     DicioAVL<int, char> D;
//     int i;
//     for (i = 48; i < 58; ++i)
//         if (D.inserir(i, (char)i) == D.fim()) return 1;

//     for (auto it = D.inicio(); it != D.fim(); ++it) {
//         // cout << "O código de ’" << it.valor() << "’ é " << it.chave() << '\n';
//     }

//     for (i = 48; i < 58; ++i) {
//         auto it = D.buscar(i);
//         if (it == D.fim()) {
//             return 1;
//         } else {
//             D.remover(it);
//         }
//     }

// }
