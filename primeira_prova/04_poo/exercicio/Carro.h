#include <iostream>
#include <string>


class Carro{
    
    private:
        string Modelo;
        int Ano;
        double Velocidade;

    public:
        
        Carro();

        Carro(string modelo, int ano);

        void setModelo(string modelo);
        void setAno(int ano);

        string getModelo();
        int getAno();

        void acelerar(double incremento);
        void frear(double decremento);
        void exibirPainel();   
}
