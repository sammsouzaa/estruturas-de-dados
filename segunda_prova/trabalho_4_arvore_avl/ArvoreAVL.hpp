#ifndef ARVOREAVL_HPP_
#define ARVOREAVL_HPP_

#include "Arvore.hpp"
#include <algorithm>

template <typename T>
class ArvoreAVL : public NoBinario<T> {
 private:
    int altura;

    int maximo(ArvoreAVL<T>* a, ArvoreAVL<T>* b) {
        if (a == nullptr && b == nullptr) return -1;
        if (a == nullptr) return b->getAltura();
        if (b == nullptr) return a->getAltura();
        return (a->getAltura() > b->getAltura()) ? a->getAltura() : b->getAltura();
    }

    void atualiza(ArvoreAVL<T>* arv) {
        if (arv != nullptr) {
            arv->altura = maximo(arv->getEsquerda(), arv->getDireita()) + 1;
        }
    }

    ArvoreAVL<T>* balanco_insere(NoBinario<T>* arv_b) {
        ArvoreAVL<T>* arv = converterAVL(arv_b);
        if (arv == nullptr) return nullptr;

        // Desbalanceamento a esquerda
        if (fator(arv) == 2) {
            if (fator(arv->getEsquerda()) == -1) {
                arv = dup_roda_esq(arv);
            } else if (fator(arv->getEsquerda()) == 1) {
                arv = simp_roda_esq(arv);
            }
        }
        // Desbalanceamento a direita
        if (fator(arv) == -2) {
            if (fator(arv->getDireita()) == 1) {
                arv = dup_roda_dir(arv);
            } else if (fator(arv->getDireita()) == -1) {
                arv = simp_roda_dir(arv);
            }
        }
        atualiza(arv);
        return arv;
    }

    ArvoreAVL<T>* balanco_remove(NoBinario<T>* arv_b) {
        ArvoreAVL<T>* arv = converterAVL(arv_b);
        if (arv == nullptr) return nullptr;

        if (fator(arv) == 2) {
            if (fator(arv->getEsquerda()) == -1) {
                arv = dup_roda_esq(arv);
            } else {
                arv = simp_roda_esq(arv);
            }
        }
        if (fator(arv) == -2) {
            if (fator(arv->getDireita()) == 1) {
                arv = dup_roda_dir(arv);
            } else {
                arv = simp_roda_dir(arv);
            }
        }
        atualiza(arv);
        return arv;
    }

 public:
    ArvoreAVL(const T& dado) : NoBinario<T>(dado), altura(0) {}
    virtual ~ArvoreAVL() {}

    ArvoreAVL<T>* inserir(const T& info, ArvoreAVL<T>* raiz) {
        NoBinario<T>* arv_b = NoBinario<T>::inserir(info, raiz);
        return converterAVL(arv_b);
    }

    ArvoreAVL<T>* remover(NoBinario<T>* raiz, const T& info) {
        NoBinario<T>* arv_b = NoBinario<T>::remover(raiz, info);
        return converterAVL(arv_b);
    }

    int fator(ArvoreAVL<T>* raiz) {
        if (raiz == nullptr) return 0;
        int altEsq = (raiz->getEsquerda() != nullptr) ? raiz->getEsquerda()->altura : -1;
        int altDir = (raiz->getDireita() != nullptr) ? raiz->getDireita()->altura : -1;
        return altEsq - altDir;
    }

    // Rotacao dupla a esquerda (Esquerda-Direita)
    ArvoreAVL<T>* dup_roda_esq(ArvoreAVL<T>* raiz) {
        raiz->setEsquerda(simp_roda_dir(raiz->getEsquerda()));
        return simp_roda_esq(raiz);
    }

    // Rotacao dupla a direita (Direita-Esquerda)
    ArvoreAVL<T>* dup_roda_dir(ArvoreAVL<T>* raiz) {
        raiz->setDireita(simp_roda_esq(raiz->getDireita()));
        return simp_roda_dir(raiz);
    }

    // Rotacao simples a esquerda
    ArvoreAVL<T>* simp_roda_esq(ArvoreAVL<T>* raiz) {
        ArvoreAVL<T>* novaRaiz = raiz->getEsquerda();
        raiz->setEsquerda(novaRaiz->getDireita());
        novaRaiz->setDireita(raiz);
        atualiza(raiz);
        atualiza(novaRaiz);
        return novaRaiz;
    }

    // Rotacao simples a direita
    ArvoreAVL<T>* simp_roda_dir(ArvoreAVL<T>* raiz) {
        ArvoreAVL<T>* novaRaiz = raiz->getDireita();
        raiz->setDireita(novaRaiz->getEsquerda());
        novaRaiz->setEsquerda(raiz);
        atualiza(raiz);
        atualiza(novaRaiz);
        return novaRaiz;
    }

    ArvoreAVL<T>* converterAVL(NoBinario<T>* binario) {
        return static_cast<ArvoreAVL<T>*>(binario);
    }

    int getAltura() {
        return altura;
    }

    ArvoreAVL<T>* getEsquerda() {
        return converterAVL(NoBinario<T>::getEsquerda());
    }

    ArvoreAVL<T>* getDireita() {
        return converterAVL(NoBinario<T>::getDireita());
    }

    std::vector<ArvoreAVL<T>*> getElementos() {
        std::vector<ArvoreAVL<T>*> vetorAVL;
        std::vector<NoBinario<T>*> vetor = NoBinario<T>::getElementos();
        for (size_t i = 0; i < vetor.size(); i++) {
            vetorAVL.push_back(converterAVL(vetor[i]));
        }
        return vetorAVL;
    }

    virtual NoBinario<T>* novoNo(const T& dado) {
        return new ArvoreAVL<T>(dado);
    }
};

#endif
