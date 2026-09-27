#include "Calculadora.h"
#include <iostream>

using namespace std;

Calculadora::Calculadora(double op1, double op2) : OperacaoMatematica(op1, op2) {
}

double Calculadora::soma(){
    return getOp1() + getOp2();   
}

double Calculadora::soma(   double a, double b){
    return a + b;
}

double Calculadora::multiplicacao(){

    double resultado = 0;

    for (int i = 0; i < getOp2(); i++){
        resultado = soma(resultado, getOp1());
    }
    return resultado;
}
