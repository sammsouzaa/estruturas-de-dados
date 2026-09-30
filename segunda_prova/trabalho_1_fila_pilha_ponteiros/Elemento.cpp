#ifndef _ELEMENTO_CPP
#define _ELEMENTO_CPP

#include "Elemento.h"

template <typename T>
Elemento<T>::Elemento(T info, Elemento<T>* proximo) {
  Info = new T(info);
  Proximo = proximo;
}

template <typename T>
Elemento<T>::~Elemento() {
  delete Info;
}

template <typename T>
Elemento<T>* Elemento<T>::GetProximo() {
  return Proximo;
}

template <typename T>
T Elemento<T>::GetInfo() {
  return *Info;
}

template <typename T>
void Elemento<T>::SetProximo(Elemento<T>* proximo) {
  Proximo = proximo;
}

#endif
