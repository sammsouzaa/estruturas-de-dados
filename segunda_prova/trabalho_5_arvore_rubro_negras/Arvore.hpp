#ifndef NOBINARIO_HPP_
#define NOBINARIO_HPP_

#include <iostream>
#include <vector>

template<typename T>
class NoBinario {
 protected:
    T* dado;
    NoBinario<T>* esquerda;
    NoBinario<T>* direita;

    virtual NoBinario<T>* balanco_insere(NoBinario<T>* arv) { return arv; }
    virtual NoBinario<T>* balanco_remove(NoBinario<T>* arv) { return arv; }
    virtual void atualiza(NoBinario<T>* arv) {}

    std::vector<NoBinario<T>*> elementos;

 public:
    NoBinario<T>(const T& dado) :
        dado(new T(dado)), esquerda(nullptr), direita(nullptr) {}

    virtual ~NoBinario<T>() {
        delete dado;
        elementos.clear();
    }

    T* getDado() {
        return this->dado;
    }

    std::vector<NoBinario<T>*> getElementos() {
        return elementos;
    }

    void limpaElementos() {
        elementos.clear();
    }

    T* busca(const T& _dado, NoBinario<T>* ptr) {
        while (ptr != nullptr && *(ptr->dado) != _dado) {
            if (*(ptr->getDado()) < _dado) {
                ptr = ptr->getDireita();
            } else {
                ptr = ptr->getEsquerda();
            }
        }
        if (ptr == nullptr) {
            throw -1;
        }
        return ptr->getDado();
    }

    NoBinario<T>* inserir(const T& _dado, NoBinario<T>* raiz) {
        if (raiz == nullptr) {
            return novoNo(_dado);
        }
        NoBinario<T>* novaRaiz;
        if (_dado < *(raiz->dado)) {
            if (raiz->esquerda == nullptr) {
                raiz->esquerda = novoNo(_dado);
                novaRaiz = balanco_insere(raiz);
                raiz = novaRaiz;
            } else {
                raiz->esquerda = inserir(_dado, raiz->esquerda);
                novaRaiz = balanco_insere(raiz);
                raiz = novaRaiz;
            }
            atualiza(raiz);
        } else if (_dado > *(raiz->dado)) {
            if (raiz->direita == nullptr) {
                raiz->direita = novoNo(_dado);
                novaRaiz = balanco_insere(raiz);
                raiz = novaRaiz;
            } else {
                raiz->direita = inserir(_dado, raiz->direita);
                novaRaiz = balanco_insere(raiz);
                raiz = novaRaiz;
            }
            atualiza(raiz);
        }
        atualiza(raiz);
        return raiz;
    }

    NoBinario<T>* remover(NoBinario<T>* raiz, const T& _dado) {
        if (raiz == nullptr) return nullptr;

        if (_dado < *(raiz->dado)) {
            raiz->esquerda = remover(raiz->esquerda, _dado);
            atualiza(raiz);
            raiz = balanco_remove(raiz);
            return raiz;
        }
        if (_dado > *(raiz->dado)) {
            raiz->direita = remover(raiz->direita, _dado);
            atualiza(raiz);
            raiz = balanco_remove(raiz);
            return raiz;
        }

        // 2 filhos
        if (raiz->esquerda != nullptr && raiz->direita != nullptr) {
            NoBinario<T>* temp = minimo(raiz->direita);
            *(raiz->dado) = *(temp->dado);
            raiz->direita = remover(raiz->direita, *(temp->dado));
            raiz = balanco_remove(raiz);
            atualiza(raiz);
            return raiz;
        }

        // 1 filho
        NoBinario<T>* filho = nullptr;
        if (raiz->direita != nullptr) {
            filho = raiz->direita;
            delete raiz;
            return filho;
        }
        if (raiz->esquerda != nullptr) {
            filho = raiz->esquerda;
            delete raiz;
            return filho;
        }

        // Folha
        delete raiz;
        return nullptr;
    }

    NoBinario<T>* minimo(NoBinario<T>* raiz) {
        if (raiz == nullptr) return nullptr;
        NoBinario<T>* atual = raiz;
        while (atual->esquerda != nullptr) {
            atual = atual->esquerda;
        }
        return atual;
    }

    void preOrdem(NoBinario<T>* raiz) {
        if (raiz != nullptr) {
            elementos.push_back(raiz);
            preOrdem(raiz->esquerda);
            preOrdem(raiz->direita);
        }
    }

    void emOrdem(NoBinario<T>* raiz) {
        if (raiz != nullptr) {
            emOrdem(raiz->esquerda);
            elementos.push_back(raiz);
            emOrdem(raiz->direita);
        }
    }

    void posOrdem(NoBinario<T>* raiz) {
        if (raiz != nullptr) {
            posOrdem(raiz->esquerda);
            posOrdem(raiz->direita);
            elementos.push_back(raiz);
        }
    }

    NoBinario<T>* getEsquerda() { return esquerda; }
    void setEsquerda(NoBinario<T>* novo) { this->esquerda = novo; }

    NoBinario<T>* getDireita() { return direita; }
    void setDireita(NoBinario<T>* novo) { this->direita = novo; }

    virtual NoBinario<T>* novoNo(const T& dado) {
        return new NoBinario<T>(dado);
    }
};

#endif
