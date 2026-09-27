#ifndef OPERACOES_H
#define OPERACOES_H

#include <iostream>

using namespace std;

class OperacaoMatematica{

    private:
        double op1;
        double op2;
        double resultado;

    public:
        OperacaoMatematica(double op1, double op2);
        virtual double multiplicacao();
        void imprimir(double resultado);
        double getOp1();
        double getOp2();
        
};

#endif
