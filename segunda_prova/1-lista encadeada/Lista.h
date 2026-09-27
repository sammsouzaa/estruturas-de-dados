#ifndef _LISTA_H
#define _LISTA_H

#define ERRO_LISTA_CHEIA -1
#define ERRO_LISTA_VAZIA -2
#define ERRO_POSICAO -3

#define MAXLISTA 100;

#include "Elemento.h"

template<typename T>

class Lista{
private:
  Elemento<T>* Dados;
  int Tamanho = MAXLISTA;
public:
  Lista();
  void LimpaLista();
  ~Lista();

  bool ListaVazia();
  //int Posicao(T dado);
  //bool Contem(T dado);

  //void Adiciona(T dado);
  void AdicionaNoInicio(T dado);
  //void AdicionaNaPosicao(T dado, int posicao);
  //void AdicionaEmOrdem(T dado);
  //T Retira();
  T RetiraDoInicio();
  //T RetiraDaPosicao(int posicao);
  //T RetiraEspecifico(T dado);
};

#include "Lista.cpp"

#endif
