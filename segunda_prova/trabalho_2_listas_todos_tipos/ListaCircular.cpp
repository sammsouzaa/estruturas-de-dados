#ifndef _LISTACIRCULAR_CPP
#define _LISTACIRCULAR_CPP

#include "ListaCircular.h"
#include "Elemento.h"

template <typename T>
ListaCircular<T>::ListaCircular() {
  Sentinela = new Elemento<T>(T(), nullptr);
  Sentinela->SetProximo(Sentinela);
  Tamanho = 0;
}

template <typename T>
void ListaCircular<T>::DestroiLista() {
  if (Sentinela == nullptr) return;
  Elemento<T>* atual = Sentinela->GetProximo();
  while (atual != Sentinela) {
    Elemento<T>* temp = atual;
    atual = atual->GetProximo();
    delete temp;
  }
  Sentinela->SetProximo(Sentinela);
  Tamanho = 0;
}

template <typename T>
ListaCircular<T>::~ListaCircular() {
  DestroiLista();
  delete Sentinela;
  Sentinela = nullptr;
}

template <typename T>
bool ListaCircular<T>::ListaVazia() {
  return Tamanho == 0;
}

template <typename T>
int ListaCircular<T>::GetTamanho() {
  return Tamanho;
}

template <typename T>
void ListaCircular<T>::AdicionaNoInicio(T dado) {
  Elemento<T>* novo = new Elemento<T>(dado, Sentinela->GetProximo());
  if (novo == nullptr) {
    throw ERRO_LISTA_CHEIA;
  }
  Sentinela->SetProximo(novo);
  Tamanho++;
}

template <typename T>
T ListaCircular<T>::RetiraDoInicio() {
  if (ListaVazia()) {
    throw ERRO_LISTA_VAZIA;
  }
  Elemento<T>* saiu = Sentinela->GetProximo();
  T volta = saiu->GetInfo();
  Sentinela->SetProximo(saiu->GetProximo());
  delete saiu;
  Tamanho--;
  return volta;
}

template <typename T>
void ListaCircular<T>::AdicionaNaPosicao(T dado, int posicao) {
  if (posicao < 0 || posicao > Tamanho) {
    throw ERRO_POSICAO;
  }
  Elemento<T>* anterior = Sentinela;
  for (int i = 0; i < posicao; i++) {
    anterior = anterior->GetProximo();
  }
  Elemento<T>* novo = new Elemento<T>(dado, anterior->GetProximo());
  if (novo == nullptr) {
    throw ERRO_LISTA_CHEIA;
  }
  anterior->SetProximo(novo);
  Tamanho++;
}

template <typename T>
T ListaCircular<T>::RetiraDaPosicao(int posicao) {
  if (ListaVazia()) {
    throw ERRO_LISTA_VAZIA;
  }
  if (posicao < 0 || posicao >= Tamanho) {
    throw ERRO_POSICAO;
  }
  Elemento<T>* anterior = Sentinela;
  for (int i = 0; i < posicao; i++) {
    anterior = anterior->GetProximo();
  }
  Elemento<T>* saiu = anterior->GetProximo();
  T volta = saiu->GetInfo();
  anterior->SetProximo(saiu->GetProximo());
  delete saiu;
  Tamanho--;
  return volta;
}

template <typename T>
void ListaCircular<T>::Adiciona(T dado) {
  AdicionaNaPosicao(dado, Tamanho);
}

template <typename T>
T ListaCircular<T>::Retira() {
  return RetiraDaPosicao(Tamanho - 1);
}

template <typename T>
int ListaCircular<T>::Posicao(T dado) {
  Elemento<T>* atual = Sentinela->GetProximo();
  int pos = 0;
  while (atual != Sentinela) {
    if (atual->GetInfo() == dado) {
      return pos;
    }
    atual = atual->GetProximo();
    pos++;
  }
  throw ERRO_NAO_ENCONTRADO;
}

template <typename T>
bool ListaCircular<T>::Contem(T dado) {
  try {
    Posicao(dado);
    return true;
  } catch (...) {
    return false;
  }
}

#endif
