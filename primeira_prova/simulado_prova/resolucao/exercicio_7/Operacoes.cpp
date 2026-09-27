#include "Operacoes.h"
#include <iostream>

using namespace std;

OperacaoMatematica::OperacaoMatematica(double op1, double op2){
    this->op1 = op1;
    this->op2 = op2;
}

double OperacaoMatematica::multiplicacao(){
    return op1 * op2;
}

void OperacaoMatematica::imprimir(double resultado){
    cout << op1 << " * " << op2 << " = " << resultado << endl;
}

double OperacaoMatematica::getOp1(){
    return op1;
}

double OperacaoMatematica::getOp2(){
    return op2;
}   