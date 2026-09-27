#include <iostream>
#include <string>
#include "Carro.h"

using namespace std;

int main() {
    // 1. Criação estática (Alocado na Pilha / Stack)
    Carro c1;
    c1.setModelo("Honda Civic");
    c1.setAno(2022);
    
    c1.acelerar(50.5);
    c1.exibirPainel(); // Deve mostrar Civic a 50.5 km/h

    // 2. Criação dinâmica usando PONTEIRO (Alocado no Heap)
    // Esse é o jeito que o C++ gerencia objetos pesados no mundo real
    Carro *c2 = new Carro("Fusca", 1970);
    
    // ATENÇÃO: Como c2 é um ponteiro, usamos a setinha (->) em vez de ponto (.)
    c2->acelerar(30.0);
    c2->frear(50.0); // Tentar frear mais do que a velocidade atual
    c2->exibirPainel(); // Deve mostrar Fusca a 0 km/h (não pode ficar negativo)

    // Como criamos com 'new', somos obrigados a limpar da memória no final!
    delete c2;

    return 0;
}
