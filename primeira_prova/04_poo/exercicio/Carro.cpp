#include <iostream>
#include <string>
#include "Carro.h"

using namespace std;

Carro::Carro(){}

Carro::Carro(string modelo, int ano){
    Modelo = modelo;
    Ano = ano;
    Velocidade = 0;
}

void Carro::setModelo(string modelo){
    Modelo = modelo;
}

void Carro::setAno(int ano){
    Ano = ano;
}

string Carro::getModelo(){
    return Modelo;
}

int Carro::getAno(){
    return Ano;
}

void Carro::acelerar(double incremento){
    Velocidade += incremento;
    cout << "Carro acelerou"<<endl;
    cout << "Velocidade atual: " << Velocidade << endl;
}

void Carro::frear(double decremento){
    Velocidade -= decremento;
    if(Velocidade < 0) Velocidade = 0;
    cout << "Carro freou"<<endl;
    cout << "Velocidade atual: " << Velocidade << endl;
}

void Carro::exibirPainel(){
    cout << "Modelo: " << Modelo << endl;
    cout << "Ano: " << Ano << endl;
    cout << "Velocidade: " << Velocidade << endl;
}
