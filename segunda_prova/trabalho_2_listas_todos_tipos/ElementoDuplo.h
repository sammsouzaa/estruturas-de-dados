#ifndef ELEMENTODUPLO_H
#define ELEMENTODUPLO_H

template<typename T>
class ElementoDuplo {
 private:
  T *Info;
  ElementoDuplo<T>* Proximo;
  ElementoDuplo<T>* Anterior;
 public:
  ElementoDuplo(T info, ElementoDuplo<T>* anterior, ElementoDuplo<T>* proximo);
  ~ElementoDuplo();
  ElementoDuplo<T>* GetProximo();
  ElementoDuplo<T>* GetAnterior();
  T GetInfo();
  void SetProximo(ElementoDuplo<T>* proximo);
  void SetAnterior(ElementoDuplo<T>* anterior);
};

#include "ElementoDuplo.cpp"

#endif
