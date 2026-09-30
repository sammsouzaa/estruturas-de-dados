#ifndef NOREDBLACK_HPP_
#define NOREDBLACK_HPP_

#include "Arvore.hpp"
#include <iostream>
#include <vector>

template <typename T>
class NoRedBlack : public NoBinario<T> {
 private:
    T* info;
    NoRedBlack<T>* esquerda;
    NoRedBlack<T>* direita;
    NoRedBlack<T>* pai;
    bool cor; // true = rubro, false = negro

    bool ehRubro(NoRedBlack<T>* n) {
        return (n != nullptr && n->cor);
    }

    bool ehNegro(NoRedBlack<T>* n) {
        return (n == nullptr || !n->cor);
    }

 public:
    NoRedBlack<T>(const T& dado) :
        NoBinario<T>(dado),
        info(new T(dado)),
        esquerda(nullptr),
        direita(nullptr),
        pai(nullptr),
        cor(true) {}

    virtual ~NoRedBlack<T>() {
        delete info;
    }

    bool getCor() const { return cor; }
    void setCor(bool c) { cor = c; }

    NoRedBlack<T>* getPai() { return pai; }
    void setPai(NoRedBlack<T>* p) { pai = p; }

    NoRedBlack<T>* getEsquerda() { return esquerda; }
    void setEsquerda(NoRedBlack<T>* e) {
        esquerda = e;
        if (e != nullptr) e->pai = this;
    }

    NoRedBlack<T>* getDireita() { return direita; }
    void setDireita(NoRedBlack<T>* d) {
        direita = d;
        if (d != nullptr) d->pai = this;
    }

    T* getDado() { return info; }

    // Rotacao a esquerda
    NoRedBlack<T>* roda_esq(NoRedBlack<T>*& raiz, NoRedBlack<T>* x) {
        NoRedBlack<T>* y = x->direita;
        x->direita = y->esquerda;
        if (y->esquerda != nullptr) {
            y->esquerda->pai = x;
        }
        y->pai = x->pai;
        if (x->pai == nullptr) {
            raiz = y;
        } else if (x == x->pai->esquerda) {
            x->pai->esquerda = y;
        } else {
            x->pai->direita = y;
        }
        y->esquerda = x;
        x->pai = y;
        return y;
    }

    // Rotacao a direita
    NoRedBlack<T>* roda_dir(NoRedBlack<T>*& raiz, NoRedBlack<T>* y) {
        NoRedBlack<T>* x = y->esquerda;
        y->esquerda = x->direita;
        if (x->direita != nullptr) {
            x->direita->pai = y;
        }
        x->pai = y->pai;
        if (y->pai == nullptr) {
            raiz = x;
        } else if (y == y->pai->esquerda) {
            y->pai->esquerda = x;
        } else {
            y->pai->direita = x;
        }
        x->direita = y;
        y->pai = x;
        return x;
    }

    // Insercao balanceada
    static NoRedBlack<T>* insereRB(NoRedBlack<T>*& raiz, const T& dado) {
        NoRedBlack<T>* novo = new NoRedBlack<T>(dado);
        if (raiz == nullptr) {
            novo->cor = false;
            raiz = novo;
            return raiz;
        }

        NoRedBlack<T>* atual = raiz;
        NoRedBlack<T>* pai = nullptr;
        while (atual != nullptr) {
            pai = atual;
            if (dado < *(atual->info)) {
                atual = atual->esquerda;
            } else if (dado > *(atual->info)) {
                atual = atual->direita;
            } else {
                delete novo;
                return raiz;
            }
        }

        novo->pai = pai;
        if (dado < *(pai->info)) {
            pai->esquerda = novo;
        } else {
            pai->direita = novo;
        }

        // Correcao apos insercao
        NoRedBlack<T>* z = novo;
        while (z != raiz && z->pai != nullptr && z->pai->cor == true) {
            NoRedBlack<T>* pai_z = z->pai;
            NoRedBlack<T>* avo = pai_z->pai;
            if (avo == nullptr) break;

            if (pai_z == avo->esquerda) {
                NoRedBlack<T>* tio = avo->direita;
                if (tio != nullptr && tio->cor == true) {
                    pai_z->cor = false;
                    tio->cor = false;
                    avo->cor = true;
                    z = avo;
                } else {
                    if (z == pai_z->direita) {
                        z = pai_z;
                        z->roda_esq(raiz, z);
                        pai_z = z->pai;
                        avo = pai_z->pai;
                    }
                    if (pai_z != nullptr) pai_z->cor = false;
                    if (avo != nullptr) {
                        avo->cor = true;
                        avo->roda_dir(raiz, avo);
                    }
                }
            } else {
                NoRedBlack<T>* tio = avo->esquerda;
                if (tio != nullptr && tio->cor == true) {
                    pai_z->cor = false;
                    tio->cor = false;
                    avo->cor = true;
                    z = avo;
                } else {
                    if (z == pai_z->esquerda) {
                        z = pai_z;
                        z->roda_dir(raiz, z);
                        pai_z = z->pai;
                        avo = pai_z->pai;
                    }
                    if (pai_z != nullptr) pai_z->cor = false;
                    if (avo != nullptr) {
                        avo->cor = true;
                        avo->roda_esq(raiz, avo);
                    }
                }
            }
        }

        raiz->cor = false;
        return raiz;
    }

    static NoRedBlack<T>* busca(NoRedBlack<T>* raiz, const T& dado) {
        NoRedBlack<T>* atual = raiz;
        while (atual != nullptr) {
            if (dado == *(atual->info)) return atual;
            if (dado < *(atual->info)) atual = atual->esquerda;
            else atual = atual->direita;
        }
        return nullptr;
    }

    static NoRedBlack<T>* minimo(NoRedBlack<T>* n) {
        if (n == nullptr) return nullptr;
        while (n->esquerda != nullptr) {
            n = n->esquerda;
        }
        return n;
    }

    // Passo de Correcao e Elevacao da Delecao (Passo-CED)
    static void passoCED(NoRedBlack<T>*& raiz, NoRedBlack<T>* x, NoRedBlack<T>* x_pai) {
        while ((x == nullptr || !x->cor) && x != raiz) {
            if (x == (x_pai ? x_pai->esquerda : nullptr)) {
                NoRedBlack<T>* irmao = x_pai->direita;
                // Caso 1
                if (irmao != nullptr && irmao->cor) {
                    irmao->cor = false;
                    x_pai->cor = true;
                    x_pai->roda_esq(raiz, x_pai);
                    irmao = x_pai->direita;
                }
                // Caso 2
                if ((irmao == nullptr || !irmao->cor) &&
                    (irmao == nullptr || ((irmao->esquerda == nullptr || !irmao->esquerda->cor) &&
                                          (irmao->direita == nullptr || !irmao->direita->cor)))) {
                    if (irmao != nullptr) irmao->cor = true;
                    x = x_pai;
                    x_pai = x->pai;
                } else {
                    // Caso 3
                    if (irmao != nullptr && (irmao->direita == nullptr || !irmao->direita->cor)) {
                        if (irmao->esquerda != nullptr) irmao->esquerda->cor = false;
                        irmao->cor = true;
                        irmao->roda_dir(raiz, irmao);
                        irmao = x_pai->direita;
                    }
                    // Caso 4
                    if (irmao != nullptr) {
                        irmao->cor = x_pai->cor;
                        if (irmao->direita != nullptr) irmao->direita->cor = false;
                    }
                    x_pai->cor = false;
                    x_pai->roda_esq(raiz, x_pai);
                    x = raiz;
                    break;
                }
            } else {
                NoRedBlack<T>* irmao = x_pai ? x_pai->esquerda : nullptr;
                // Caso 1 simetrico
                if (irmao != nullptr && irmao->cor) {
                    irmao->cor = false;
                    x_pai->cor = true;
                    x_pai->roda_dir(raiz, x_pai);
                    irmao = x_pai->esquerda;
                }
                // Caso 2 simetrico
                if ((irmao == nullptr || !irmao->cor) &&
                    (irmao == nullptr || ((irmao->esquerda == nullptr || !irmao->esquerda->cor) &&
                                          (irmao->direita == nullptr || !irmao->direita->cor)))) {
                    if (irmao != nullptr) irmao->cor = true;
                    x = x_pai;
                    x_pai = x->pai;
                } else {
                    // Caso 3 simetrico
                    if (irmao != nullptr && (irmao->esquerda == nullptr || !irmao->esquerda->cor)) {
                        if (irmao->direita != nullptr) irmao->direita->cor = false;
                        irmao->cor = true;
                        irmao->roda_esq(raiz, irmao);
                        irmao = x_pai->esquerda;
                    }
                    // Caso 4 simetrico
                    if (irmao != nullptr) {
                        irmao->cor = x_pai->cor;
                        if (irmao->esquerda != nullptr) irmao->esquerda->cor = false;
                    }
                    x_pai->cor = false;
                    x_pai->roda_dir(raiz, x_pai);
                    x = raiz;
                    break;
                }
            }
        }
        if (x != nullptr) x->cor = false;
        if (raiz != nullptr) raiz->cor = false;
    }

    static NoRedBlack<T>* remover(NoRedBlack<T>*& raiz, const T& dado) {
        NoRedBlack<T>* z = busca(raiz, dado);
        if (z == nullptr) return raiz;

        NoRedBlack<T>* y = z;
        NoRedBlack<T>* x = nullptr;
        NoRedBlack<T>* x_pai = nullptr;
        bool cor_original_y = y->cor;

        if (z->esquerda == nullptr) {
            x = z->direita;
            x_pai = z->pai;
            transplanta(raiz, z, z->direita);
        } else if (z->direita == nullptr) {
            x = z->esquerda;
            x_pai = z->pai;
            transplanta(raiz, z, z->esquerda);
        } else {
            y = minimo(z->direita);
            cor_original_y = y->cor;
            x = y->direita;
            if (y->pai == z) {
                x_pai = y;
            } else {
                x_pai = y->pai;
                transplanta(raiz, y, y->direita);
                y->direita = z->direita;
                if (y->direita != nullptr) y->direita->pai = y;
            }
            transplanta(raiz, z, y);
            y->esquerda = z->esquerda;
            if (y->esquerda != nullptr) y->esquerda->pai = y;
            y->cor = z->cor;
        }

        delete z;

        if (!cor_original_y) {
            passoCED(raiz, x, x_pai);
        }

        return raiz;
    }

    static void transplanta(NoRedBlack<T>*& raiz, NoRedBlack<T>* u, NoRedBlack<T>* v) {
        if (u->pai == nullptr) {
            raiz = v;
        } else if (u == u->pai->esquerda) {
            u->pai->esquerda = v;
        } else {
            u->pai->direita = v;
        }
        if (v != nullptr) {
            v->pai = u->pai;
        }
    }

    static void imprimeEmOrdem(NoRedBlack<T>* n) {
        if (n != nullptr) {
            imprimeEmOrdem(n->esquerda);
            std::cout << *(n->info) << "(" << (n->cor ? "R" : "N") << ") ";
            imprimeEmOrdem(n->direita);
        }
    }
};

#endif
