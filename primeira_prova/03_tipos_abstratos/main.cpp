#include <iostream>
using namespace std;

class Racional {
private:
    int numerador;
    int denominador;

    // metodo para calcular MDC
    int mdc(int a, int b) {
        if (b == 0)
            return a;
        return mdc(b, a % b);
    }

    // simplifica a fração
    void simplificar() {
        int divisor = mdc(numerador, denominador);
        numerador /= divisor;
        denominador /= divisor;

        // evitar denominador negativo
        if (denominador < 0) {
            numerador *= -1;
            denominador *= -1;
        }
    }

public:
    // construtor (com o mesmo nome da classe)
    Racional(int n = 0, int d = 1) {
        if (d == 0) {
            cout << "erro, o denominador não pode ser zero" << endl;
            d = 1;
        }
        numerador = n;
        denominador = d;
        simplificar();
    }

    // metodo soma
    Racional somar(Racional r) {
        int n = numerador * r.denominador + r.numerador * denominador;
        int d = denominador * r.denominador;
        return Racional(n, d);
    }

    // metodo subtração
    Racional subtrair(Racional r) {
        int n = numerador * r.denominador - r.numerador * denominador;
        int d = denominador * r.denominador;
        return Racional(n, d);
    }

    // metodo multiplicação
    Racional multiplicar(Racional r) {
        return Racional(numerador * r.numerador,
                        denominador * r.denominador);
    }

    // metodo divisão
    Racional dividir(Racional r) {
        return Racional(numerador * r.denominador,
                        denominador * r.numerador);
    }

    // função pra printar
    void imprimir() {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
    
    Racional f1(1, 2);
    Racional f2(3, 4);

    Racional soma = f1.somar(f2);
    cout << "Soma: ";
    soma.imprimir();
    
    Racional sub = f1.subtrair(f2);
    cout << "Subtração: ";
    sub.imprimir();
    
    Racional mult = f1.multiplicar(f2);
    cout << "Multiplicação: ";
    mult.imprimir();
    
    Racional div = f1.dividir(f2);
    cout << "Divisão: ";
    div.imprimir();

    return 0;
}
