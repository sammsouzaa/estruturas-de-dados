#ifndef _LISTADUPLA_H
#define _LISTADUPLA_H

#define ERRO_LISTA_CHEIA -1
#define ERRO_LISTA_VAZIA -2
#define ERRO_POSICAO -3
#define ERRO_NAO_ENCONTRADO -4

#include "ElementoDuplo.h"

template<typename T>
class ListaDupla {
 private:
  ElementoDuplo<T>* Primeiro;
  int Tamanho;
 public:
  ListaDupla();
  ~ListaDupla();
  void DestroiListaDupla();

  bool ListaVaziaDupla();
  int GetTamanho();

  void AdicionaNoInicioDupla(T dado);
  T RetiraDoInicioDupla();

  void AdicionaNaPosicaoDupla(T dado, int posicao);
  T RetiraDaPosicaoDupla(int posicao);
  void AdicionaEmOrdemDupla(T dado);

  void AdicionaDupla(T dado);
  T RetiraDupla();
  T RetiraEspecificoDupla(T dado);
  int PosicaoDupla(T dado);
  bool ContemDupla(T dado);
};

#include "ListaDupla.cpp"

#endif
