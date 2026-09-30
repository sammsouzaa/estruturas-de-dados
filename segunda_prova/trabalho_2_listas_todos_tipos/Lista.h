#ifndef _LISTA_H
#define _LISTA_H

#define ERRO_LISTA_CHEIA -1
#define ERRO_LISTA_VAZIA -2
#define ERRO_POSICAO -3
#define ERRO_NAO_ENCONTRADO -4

#include "Elemento.h"

template<typename T>
class Lista {
 private:
  Elemento<T>* Dados;
  int Tamanho;
  int Capacidade;
 public:
  Lista();
  Lista(int capacidade);
  ~Lista();
  void LimpaLista();
  void DestroiLista();

  bool ListaVazia();
  bool ListaCheia();
  int GetTamanho();

  void AdicionaNoInicio(T dado);
  T RetiraDoInicio();
  void EliminaDoInicio();

  void AdicionaNaPosicao(T dado, int posicao);
  T RetiraDaPosicao(int posicao);
  void AdicionaEmOrdem(T dado);

  void Adiciona(T dado);
  T Retira();
  T RetiraEspecifico(T dado);
  int Posicao(T dado);
  bool Contem(T dado);
};

#include "Lista.cpp"

#endif
