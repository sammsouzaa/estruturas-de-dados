#include <iostream>
#include "ArvoreAVL.hpp"

using namespace std;

void mostra(ArvoreAVL<int>* arv) {
    if (arv != nullptr) {
        arv->limpaElementos();
        arv->emOrdem(arv);
        auto v = arv->getElementos();
        for (size_t i = 0; i < v.size(); i++) {
            cout << *(v[i]->getDado()) << " ";
        }
        cout << "\n";
    }
}

int main() {
    cout << "Testando Arvore AVL:\n";

    ArvoreAVL<int>* avl = new ArvoreAVL<int>(30);
    avl = avl->inserir(20, avl);
    avl = avl->inserir(10, avl); // Rotacao simples a direita
    avl = avl->inserir(25, avl);
    avl = avl->inserir(28, avl); // Rotacao dupla
    avl = avl->inserir(40, avl);
    avl = avl->inserir(50, avl);

    cout << "Raiz: " << *(avl->getDado()) << "\n";
    cout << "Altura: " << avl->getAltura() << "\n";
    cout << "Fator da raiz: " << avl->fator(avl) << "\n";

    cout << "Em-Ordem: ";
    mostra(avl);

    cout << "Removendo 10:\n";
    avl = avl->remover(avl, 10);
    mostra(avl);

    cout << "Removendo raiz (" << *(avl->getDado()) << "):\n";
    avl = avl->remover(avl, *(avl->getDado()));
    cout << "Nova raiz: " << *(avl->getDado()) << "\n";
    mostra(avl);

    return 0;
}
