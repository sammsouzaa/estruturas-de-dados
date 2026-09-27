#ifndef _LISTA_CPP
#define _LISTA_CPP

#include "Lista.h"
#include "Elemento.h"

template <typename T>
Lista<T>::Lista(){
  Tamanho = 0;
  Dados = nullptr;
}

template <typename T>
void Lista<T>::LimpaLista() {
  Elemento<T> *atual;
  if (!ListaVazia()) {
    while (Dados != nullptr) {
      atual = Dados;
      Dados = atual->GetProximo();
      delete atual;
    }
  } else {
    delete Dados;
  }
  Tamanho = 0;
}

template <typename T>
Lista<T>::~Lista(){
  LimpaLista();
}

template <typename T>
bool Lista<T>::ListaVazia() {
  return Tamanho == 0;
}

template <typename T>
void Lista<T>::AdicionaNoInicio(T dado) {
  Elemento<T> *novo = new Elemento<T>(dado, Dados);
  if (novo == nullptr) {
      throw ERRO_LISTA_CHEIA;
  }
  else {
    Dados = novo;
    Tamanho++;
  }
}

template <typename T>
T Lista<T>::RetiraDoInicio() {
  if (!ListaVazia()) {
    Elemento<T> *saiu = Dados;
    T volta = saiu->GetInfo();
    Dados = saiu->GetProximo();
    Tamanho--;
    delete saiu;
    return volta;
  }
  throw ERRO_LISTA_VAZIA;
}
#endif
