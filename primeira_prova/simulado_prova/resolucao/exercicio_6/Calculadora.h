#ifndef CALCULADORA_H
#define CALCULADORA_H

#include "Operacoes.h"
#include <iostream>

class Calculadora : public OperacaoMatematica{

    public:
        Calculadora(double op1, double op2);

        double soma();
        double multiplicacao() override;
};

#endif
