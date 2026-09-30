#include <iostream>
#include "Arvore.hpp"

using namespace std;

void mostra(NoBinario<int>* arv) {
    arv->limpaElementos();
    arv->emOrdem(arv);
    auto v = arv->getElementos();
    for (size_t i = 0; i < v.size(); i++) {
        cout << *(v[i]->getDado()) << " ";
    }
    cout << "\n";
}

int main() {
    cout << "Testando Arvore Binaria de Busca:\n";

    NoBinario<int>* raiz = new NoBinario<int>(50);
    raiz = raiz->inserir(30, raiz);
    raiz = raiz->inserir(70, raiz);
    raiz = raiz->inserir(20, raiz);
    raiz = raiz->inserir(40, raiz);
    raiz = raiz->inserir(60, raiz);
    raiz = raiz->inserir(80, raiz);

    cout << "Em-Ordem: ";
    mostra(raiz);

    try {
        cout << "Buscando 40: " << *(raiz->busca(40, raiz)) << "\n";
    } catch (int e) {
        cout << "40 nao encontrado\n";
    }

    cout << "Removendo 20 (folha):\n";
    raiz = raiz->remover(raiz, 20);
    mostra(raiz);

    cout << "Removendo 30 (2 filhos):\n";
    raiz = raiz->remover(raiz, 30);
    mostra(raiz);

    cout << "Removendo 50 (raiz):\n";
    raiz = raiz->remover(raiz, 50);
    mostra(raiz);

    return 0;
}
