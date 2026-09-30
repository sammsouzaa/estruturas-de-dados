#include <iostream>
#include "NoRedBlack.hpp"

using namespace std;

int main() {
    cout << "Testando Arvore Rubro-Negra:\n";

    NoRedBlack<int>* raiz = nullptr;
    int v[] = {10, 20, 30, 15, 25, 5, 1};

    for (int x : v) {
        raiz = NoRedBlack<int>::insereRB(raiz, x);
    }

    cout << "Raiz: " << *(raiz->getDado())
         << " (Cor: " << (raiz->getCor() ? "Rubro" : "Negro") << ")\n";

    cout << "Em-Ordem [Valor(Cor)]:\n";
    NoRedBlack<int>::imprimeEmOrdem(raiz);
    cout << "\n\n";

    auto b = NoRedBlack<int>::busca(raiz, 25);
    if (b != nullptr) {
        cout << "Elemento 25 encontrado (Cor: " << (b->getCor() ? "Rubro" : "Negro") << ")\n";
    }

    cout << "Removendo 1:\n";
    raiz = NoRedBlack<int>::remover(raiz, 1);
    NoRedBlack<int>::imprimeEmOrdem(raiz);
    cout << "\n";

    cout << "Removendo 10 (Passo-CED):\n";
    raiz = NoRedBlack<int>::remover(raiz, 10);
    NoRedBlack<int>::imprimeEmOrdem(raiz);
    cout << "\n";

    cout << "Removendo raiz (" << *(raiz->getDado()) << "):\n";
    raiz = NoRedBlack<int>::remover(raiz, *(raiz->getDado()));
    cout << "Nova raiz: " << *(raiz->getDado()) << "\n";
    NoRedBlack<int>::imprimeEmOrdem(raiz);
    cout << "\n";

    return 0;
}
