#include "Calculadora.h"
#include <iostream>

using namespace std;

int main(){

    OperacaoMatematica op1(10, 2);
    double resultado = op1.multiplicacao();
    op1.imprimir(resultado);

    return 0;
}