#ifndef _LISTACIRCULAR_H
#define _LISTACIRCULAR_H

#define ERRO_LISTA_CHEIA -1
#define ERRO_LISTA_VAZIA -2
#define ERRO_POSICAO -3
#define ERRO_NAO_ENCONTRADO -4

#include "Elemento.h"

template<typename T>
class ListaCircular {
 private:
  Elemento<T>* Sentinela;
  int Tamanho;
 public:
  ListaCircular();
  ~ListaCircular();
  void DestroiLista();

  bool ListaVazia();
  int GetTamanho();

  void AdicionaNoInicio(T dado);
  T RetiraDoInicio();

  void AdicionaNaPosicao(T dado, int posicao);
  T RetiraDaPosicao(int posicao);

  void Adiciona(T dado);
  T Retira();
  int Posicao(T dado);
  bool Contem(T dado);
};

#include "ListaCircular.cpp"

#endif
