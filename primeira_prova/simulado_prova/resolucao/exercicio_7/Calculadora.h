#ifndef CALCULADORA_H
#define CALCULADORA_H

#include "Operacoes.h"
#include <iostream>

class Calculadora : public OperacaoMatematica{

    public:
        Calculadora(double op1, double op2);

        double soma();
        double soma(double a, double b);
        double multiplicacao() override;
};

#endif
