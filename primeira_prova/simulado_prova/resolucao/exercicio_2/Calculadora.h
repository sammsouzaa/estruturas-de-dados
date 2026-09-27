#include <iostream>

using namespace std;

class OperacaoMatematica{

    private:
        double op1;
        double op2;

    public:
        OperacaoMatematica(double op1, double op2);
        double multiplicacao();
        void imprimir();
};
