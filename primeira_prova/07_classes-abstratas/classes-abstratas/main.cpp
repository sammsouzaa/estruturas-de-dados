#include <iostream>
#include <string>
#include "Mesa.h"
#include "ConcretMesa.h"
#include "Decorator.h"
#include "Rodinha.h"
#include "RedePingPong.h"

using namespace std;

int main(){
    // Cria uma mesa básica
    Mesa* mesa1 = new ConcretMesa();
    cout << "Descrição: " << mesa1->getDescricao() << "\n";

    // Adicion Rodinha
    Mesa* mesa2 = new Rodinha(mesa1);
    cout << "Descrição: " << mesa2->getDescricao() << "\n";

    // Adiciona Rede de Ping Pong
    Mesa* mesa3 = new RedePingPong(mesa2);
    cout << "Descrição: " << mesa3->getDescricao() << "\n";

    // Adicion Rodinha
    Mesa* mesa4 = new Rodinha(mesa3);
    cout << "Descrição: " << mesa4->getDescricao() << "\n";

    delete mesa1;
    delete mesa2;
    delete mesa3;
    delete mesa4;
}
