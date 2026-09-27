#ifndef CALCULADORA_H
#define CALCULADORA_H

#include "Operacoes.h"
#include <iostream>

class Calculadora : public OperacaoMatematica{

    private:

    public:
        Calculadora(double op1, double op2);

        double soma();
};

#endif
