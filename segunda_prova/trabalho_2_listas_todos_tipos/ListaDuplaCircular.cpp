#ifndef _LISTADUPLACIRCULAR_CPP
#define _LISTADUPLACIRCULAR_CPP

#include "ListaDuplaCircular.h"
#include "ElementoDuplo.h"

template <typename T>
ListaDuplaCircular<T>::ListaDuplaCircular() {
  Primeiro = nullptr;
  Tamanho = 0;
}

template <typename T>
void ListaDuplaCircular<T>::DestroiLista() {
  if (Primeiro == nullptr) return;
  ElementoDuplo<T>* atual = Primeiro;
  for (int i = 0; i < Tamanho; i++) {
    ElementoDuplo<T>* temp = atual;
    atual = atual->GetProximo();
    delete temp;
  }
  Primeiro = nullptr;
  Tamanho = 0;
}

template <typename T>
ListaDuplaCircular<T>::~ListaDuplaCircular() {
  DestroiLista();
}

template <typename T>
bool ListaDuplaCircular<T>::ListaVazia() {
  return Tamanho == 0;
}

template <typename T>
int ListaDuplaCircular<T>::GetTamanho() {
  return Tamanho;
}

template <typename T>
void ListaDuplaCircular<T>::AdicionaNoInicio(T dado) {
  if (ListaVazia()) {
    ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, nullptr, nullptr);
    if (novo == nullptr) {
      throw ERRO_LISTA_CHEIA;
    }
    novo->SetProximo(novo);
    novo->SetAnterior(novo);
    Primeiro = novo;
  } else {
    ElementoDuplo<T>* ultimo = Primeiro->GetAnterior();
    ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, ultimo, Primeiro);
    if (novo == nullptr) {
      throw ERRO_LISTA_CHEIA;
    }
    ultimo->SetProximo(novo);
    Primeiro->SetAnterior(novo);
    Primeiro = novo;
  }
  Tamanho++;
}

template <typename T>
T ListaDuplaCircular<T>::RetiraDoInicio() {
  if (ListaVazia()) {
    throw ERRO_LISTA_VAZIA;
  }
  T volta = Primeiro->GetInfo();
  if (Tamanho == 1) {
    delete Primeiro;
    Primeiro = nullptr;
  } else {
    ElementoDuplo<T>* saiu = Primeiro;
    ElementoDuplo<T>* ultimo = Primeiro->GetAnterior();
    ElementoDuplo<T>* segundo = Primeiro->GetProximo();
    ultimo->SetProximo(segundo);
    segundo->SetAnterior(ultimo);
    Primeiro = segundo;
    delete saiu;
  }
  Tamanho--;
  return volta;
}

template <typename T>
void ListaDuplaCircular<T>::AdicionaNaPosicao(T dado, int posicao) {
  if (posicao < 0 || posicao > Tamanho) {
    throw ERRO_POSICAO;
  }
  if (posicao == 0) {
    AdicionaNoInicio(dado);
    return;
  }
  ElementoDuplo<T>* anterior = Primeiro;
  for (int i = 0; i < posicao - 1; i++) {
    anterior = anterior->GetProximo();
  }
  ElementoDuplo<T>* proximo = anterior->GetProximo();
  ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, anterior, proximo);
  if (novo == nullptr) {
    throw ERRO_LISTA_CHEIA;
  }
  anterior->SetProximo(novo);
  proximo->SetAnterior(novo);
  Tamanho++;
}

template <typename T>
T ListaDuplaCircular<T>::RetiraDaPosicao(int posicao) {
  if (ListaVazia()) {
    throw ERRO_LISTA_VAZIA;
  }
  if (posicao < 0 || posicao >= Tamanho) {
    throw ERRO_POSICAO;
  }
  if (posicao == 0) {
    return RetiraDoInicio();
  }
  ElementoDuplo<T>* saiu = Primeiro;
  for (int i = 0; i < posicao; i++) {
    saiu = saiu->GetProximo();
  }
  ElementoDuplo<T>* anterior = saiu->GetAnterior();
  ElementoDuplo<T>* proximo = saiu->GetProximo();
  anterior->SetProximo(proximo);
  proximo->SetAnterior(anterior);
  T volta = saiu->GetInfo();
  delete saiu;
  Tamanho--;
  return volta;
}

template <typename T>
void ListaDuplaCircular<T>::Adiciona(T dado) {
  AdicionaNaPosicao(dado, Tamanho);
}

template <typename T>
T ListaDuplaCircular<T>::Retira() {
  return RetiraDaPosicao(Tamanho - 1);
}

template <typename T>
int ListaDuplaCircular<T>::Posicao(T dado) {
  if (ListaVazia()) throw ERRO_NAO_ENCONTRADO;
  ElementoDuplo<T>* atual = Primeiro;
  for (int pos = 0; pos < Tamanho; pos++) {
    if (atual->GetInfo() == dado) {
      return pos;
    }
    atual = atual->GetProximo();
  }
  throw ERRO_NAO_ENCONTRADO;
}

template <typename T>
bool ListaDuplaCircular<T>::Contem(T dado) {
  try {
    Posicao(dado);
    return true;
  } catch (...) {
    return false;
  }
}

#endif
