#include "Calculadora.h"
#include <iostream>

using namespace std;

Calculadora::Calculadora(double op1, double op2) : OperacaoMatematica(op1, op2) {
}

double Calculadora::soma(){
    return getOp1() + getOp2();
}

double Calculadora::multiplicacao(){
    return getOp1() * getOp2();
}
