#include <iostream>
#include <string>
#include "Lista.h"
#include "ListaDupla.h"
#include "ListaCircular.h"
#include "ListaDuplaCircular.h"

using namespace std;

int main() {
    cout << "Testando Lista Encadeada Simples:\n";
    Lista<int> l1;
    l1.AdicionaNoInicio(10);
    l1.Adiciona(30);
    l1.AdicionaNaPosicao(20, 1);
    l1.AdicionaEmOrdem(25);

    cout << "Tamanho: " << l1.GetTamanho() << "\n";
    cout << "Posicao do 25: " << l1.Posicao(25) << "\n";
    cout << "Retira especifico 25: " << l1.RetiraEspecifico(25) << "\n";
    while (!l1.ListaVazia()) {
        cout << l1.RetiraDoInicio() << " ";
    }
    cout << "\n\n";

    cout << "Testando Lista Duplamente Encadeada:\n";
    ListaDupla<int> l2;
    l2.AdicionaNoInicioDupla(100);
    l2.AdicionaDupla(300);
    l2.AdicionaNaPosicaoDupla(200, 1);
    l2.AdicionaEmOrdemDupla(150);

    cout << "Tamanho: " << l2.GetTamanho() << "\n";
    cout << "Retira especifico 150: " << l2.RetiraEspecificoDupla(150) << "\n";
    while (!l2.ListaVaziaDupla()) {
        cout << l2.RetiraDoInicioDupla() << " ";
    }
    cout << "\n\n";

    cout << "Testando Lista Circular com Sentinela:\n";
    ListaCircular<int> l3;
    l3.AdicionaNoInicio(1);
    l3.Adiciona(3);
    l3.AdicionaNaPosicao(2, 1);

    cout << "Tamanho: " << l3.GetTamanho() << "\n";
    while (!l3.ListaVazia()) {
        cout << l3.RetiraDoInicio() << " ";
    }
    cout << "\n\n";

    cout << "Testando Lista Dupla Circular:\n";
    ListaDuplaCircular<string> l4;
    l4.AdicionaNoInicio("Alfa");
    l4.Adiciona("Gama");
    l4.AdicionaNaPosicao("Beta", 1);

    cout << "Tamanho: " << l4.GetTamanho() << "\n";
    while (!l4.ListaVazia()) {
        cout << l4.RetiraDoInicio() << " ";
    }
    cout << "\n";

    return 0;
}
