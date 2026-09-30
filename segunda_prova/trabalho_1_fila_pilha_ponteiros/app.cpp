#include <iostream>
#include <string>
#include "Pilha.h"
#include "Fila.h"

using namespace std;

int main() {
    cout << "Testando Pilha Encadeada:\n";
    Pilha<int> p;
    p.Empilha(10);
    p.Empilha(20);
    p.Empilha(30);

    cout << "Topo: " << p.GetTopo() << "\n";
    cout << "Tamanho: " << p.GetTamanho() << "\n";

    while (!p.PilhaVazia()) {
        cout << p.Desempilha() << "\n";
    }

    cout << "\nTestando Fila Encadeada:\n";
    Fila<string> f;
    f.Inclui("Primeiro");
    f.Inclui("Segundo");
    f.Inclui("Terceiro");

    cout << "Primeiro: " << f.GetPrimeiro() << "\n";
    cout << "Ultimo: " << f.GetUltimo() << "\n";
    cout << "Tamanho: " << f.GetTamanho() << "\n";

    while (!f.FilaVazia()) {
        cout << f.Retira() << "\n";
    }

    return 0;
}
