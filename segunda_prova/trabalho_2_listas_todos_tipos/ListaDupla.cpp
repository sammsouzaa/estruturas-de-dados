#ifndef _LISTADUPLA_CPP
#define _LISTADUPLA_CPP

#include "ListaDupla.h"
#include "ElementoDuplo.h"

template <typename T>
ListaDupla<T>::ListaDupla() {
  Primeiro = nullptr;
  Tamanho = 0;
}

template <typename T>
void ListaDupla<T>::DestroiListaDupla() {
  ElementoDuplo<T>* atual;
  while (Primeiro != nullptr) {
    atual = Primeiro;
    Primeiro = atual->GetProximo();
    delete atual;
  }
  Tamanho = 0;
}

template <typename T>
ListaDupla<T>::~ListaDupla() {
  DestroiListaDupla();
}

template <typename T>
bool ListaDupla<T>::ListaVaziaDupla() {
  return Tamanho == 0;
}

template <typename T>
int ListaDupla<T>::GetTamanho() {
  return Tamanho;
}

template <typename T>
void ListaDupla<T>::AdicionaNoInicioDupla(T dado) {
  ElementoDuplo<T>* novo = new ElementoDuplo<T>(dado, nullptr, Primeiro);
  if (novo == nullptr) {
    throw ERRO_LISTA_CHEIA;
  }
  if (Primeiro != nullptr) {
    Primeiro->SetAnterior(novo);
  }
  Primeiro = novo;
  Tamanho++;
}

template <typename T>
T ListaDupla<T>::RetiraDoInicioDupla() {
  if (ListaVaziaDupla()) {
    throw ERRO_LISTA_VAZIA;
  }
  ElementoDuplo<T>* saiu = Primeiro;
  T volta = saiu->GetInfo();
  Primeiro = saiu->GetProximo();
  if (Primeiro != nullptr) {
    Primeiro->SetAnterior(nullptr);
  }
  delete saiu;
  Tamanho--;
  return volta;
}

template <typename T>
void ListaDupla<T>::AdicionaNaPosicaoDupla(T dado, int posicao) {
  if (posicao < 0 || posicao > Tamanho) {
    throw ERRO_POSICAO;
  }
  if (posicao == 0) {
    AdicionaNoInicioDupla(dado);
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
  if (proximo != nullptr) {
    proximo->SetAnterior(novo);
  }
  Tamanho++;
}

template <typename T>
T ListaDupla<T>::RetiraDaPosicaoDupla(int posicao) {
  if (ListaVaziaDupla()) {
    throw ERRO_LISTA_VAZIA;
  }
  if (posicao < 0 || posicao >= Tamanho) {
    throw ERRO_POSICAO;
  }
  if (posicao == 0) {
    return RetiraDoInicioDupla();
  }
  ElementoDuplo<T>* saiu = Primeiro;
  for (int i = 0; i < posicao; i++) {
    saiu = saiu->GetProximo();
  }
  ElementoDuplo<T>* anterior = saiu->GetAnterior();
  ElementoDuplo<T>* proximo = saiu->GetProximo();
  anterior->SetProximo(proximo);
  if (proximo != nullptr) {
    proximo->SetAnterior(anterior);
  }
  T volta = saiu->GetInfo();
  delete saiu;
  Tamanho--;
  return volta;
}

template <typename T>
void ListaDupla<T>::AdicionaEmOrdemDupla(T dado) {
  if (ListaVaziaDupla()) {
    AdicionaNoInicioDupla(dado);
    return;
  }
  ElementoDuplo<T>* atual = Primeiro;
  int pos = 0;
  while (atual != nullptr && dado > atual->GetInfo()) {
    atual = atual->GetProximo();
    pos++;
  }
  AdicionaNaPosicaoDupla(dado, pos);
}

template <typename T>
void ListaDupla<T>::AdicionaDupla(T dado) {
  AdicionaNaPosicaoDupla(dado, Tamanho);
}

template <typename T>
T ListaDupla<T>::RetiraDupla() {
  return RetiraDaPosicaoDupla(Tamanho - 1);
}

template <typename T>
T ListaDupla<T>::RetiraEspecificoDupla(T dado) {
  int pos = PosicaoDupla(dado);
  return RetiraDaPosicaoDupla(pos);
}

template <typename T>
int ListaDupla<T>::PosicaoDupla(T dado) {
  ElementoDuplo<T>* atual = Primeiro;
  int pos = 0;
  while (atual != nullptr) {
    if (atual->GetInfo() == dado) {
      return pos;
    }
    atual = atual->GetProximo();
    pos++;
  }
  throw ERRO_NAO_ENCONTRADO;
}

template <typename T>
bool ListaDupla<T>::ContemDupla(T dado) {
  try {
    PosicaoDupla(dado);
    return true;
  } catch (...) {
    return false;
  }
}

#endif
