#include <iostream>
#include <string>

using namespace std;

// Classe Abstrata/Interface - define as operações básicas da mesa
class Mesa{
public:
    virtual string getDescricao() = 0;
};

// Componente Concreto - a classe básica de mesa.
class ConcretMesa : public Mesa{
public:
    string getDescricao(){
        return "Mesa";
    }
};

// Decorator - classe abstrata que estende Mesa.
class Decorator : public Mesa{
protected:
    Mesa* mesa;
public:
    Decorator(Mesa* m): mesa(m){
    }

    string getDescricao(){
        return mesa->getDescricao();
    }
};

// Decorator Concreto - adiciona Rodinha.
class Rodinha : public Decorator {
public:
    Rodinha(Mesa* m): Decorator(m){
    }

    string getDescricao(){
        return mesa->getDescricao()
               + " com Rodinha";
    }
};

// Decorator Concreto - adiciona Rede de Ping Pong.
class RedePingPong : public Decorator {
public:
    RedePingPong(Mesa* m): Decorator(m){
    }

    string getDescricao(){
        return mesa->getDescricao() + " com Rede de Ping Pong";
    }
};

int main()
{
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

    return 0;
}
