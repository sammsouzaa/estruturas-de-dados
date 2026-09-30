#ifndef _LISTADUPLACIRCULAR_H
#define _LISTADUPLACIRCULAR_H

#define ERRO_LISTA_CHEIA -1
#define ERRO_LISTA_VAZIA -2
#define ERRO_POSICAO -3
#define ERRO_NAO_ENCONTRADO -4

#include "ElementoDuplo.h"

template<typename T>
class ListaDuplaCircular {
 private:
  ElementoDuplo<T>* Primeiro;
  int Tamanho;
 public:
  ListaDuplaCircular();
  ~ListaDuplaCircular();
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

#include "ListaDuplaCircular.cpp"

#endif
