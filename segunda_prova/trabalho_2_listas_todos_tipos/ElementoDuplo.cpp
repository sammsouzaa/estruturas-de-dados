#ifndef _ELEMENTODUPLO_CPP
#define _ELEMENTODUPLO_CPP

#include "ElementoDuplo.h"

template <typename T>
ElementoDuplo<T>::ElementoDuplo(T info, ElementoDuplo<T>* anterior, ElementoDuplo<T>* proximo) {
  Info = new T(info);
  Anterior = anterior;
  Proximo = proximo;
}

template <typename T>
ElementoDuplo<T>::~ElementoDuplo() {
  delete Info;
}

template <typename T>
ElementoDuplo<T>* ElementoDuplo<T>::GetProximo() {
  return Proximo;
}

template <typename T>
ElementoDuplo<T>* ElementoDuplo<T>::GetAnterior() {
  return Anterior;
}

template <typename T>
T ElementoDuplo<T>::GetInfo() {
  return *Info;
}

template <typename T>
void ElementoDuplo<T>::SetProximo(ElementoDuplo<T>* proximo) {
  Proximo = proximo;
}

template <typename T>
void ElementoDuplo<T>::SetAnterior(ElementoDuplo<T>* anterior) {
  Anterior = anterior;
}

#endif
