#ifndef _PILHA_H
#define _PILHA_H

#define ERRO_PILHA_CHEIA -1
#define ERRO_PILHA_VAZIA -2

#include "Elemento.h"

template<typename T>
class Pilha {
 private:
  Elemento<T>* Topo;
  int Tamanho;
 public:
  Pilha();
  ~Pilha();
  void DestroiPilha();
  bool PilhaVazia();
  void Empilha(T dado);
  T Desempilha();
  T GetTopo();
  int GetTamanho();
};

#include "Pilha.cpp"

#endif
