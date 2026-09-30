#ifndef _FILA_H
#define _FILA_H

#define ERRO_FILA_CHEIA -1
#define ERRO_FILA_VAZIA -2

#include "Elemento.h"

template<typename T>
class Fila {
 private:
  Elemento<T>* Inicio;
  Elemento<T>* Fim;
  int Tamanho;
 public:
  Fila();
  ~Fila();
  void DestroiFila();
  bool FilaVazia();
  void Inclui(T dado);
  T Retira();
  T GetPrimeiro();
  T GetUltimo();
  int GetTamanho();
};

#include "Fila.cpp"

#endif
