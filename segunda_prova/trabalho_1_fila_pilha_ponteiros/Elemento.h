#ifndef ELEMENTO_H
#define ELEMENTO_H

template<typename T>
class Elemento {
 private:
  T *Info;
  Elemento<T>* Proximo;
 public:
  Elemento(T info, Elemento<T>* proximo);
  ~Elemento();
  Elemento<T>* GetProximo();
  T GetInfo();
  void SetProximo(Elemento<T>* proximo);
};

#include "Elemento.cpp"

#endif
