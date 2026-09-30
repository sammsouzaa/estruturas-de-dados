#ifndef _PILHA_CPP
#define _PILHA_CPP

#include "Pilha.h"
#include "Elemento.h"

template <typename T>
Pilha<T>::Pilha() {
  Topo = nullptr;
  Tamanho = 0;
}

template <typename T>
void Pilha<T>::DestroiPilha() {
  Elemento<T>* atual;
  while (Topo != nullptr) {
    atual = Topo;
    Topo = atual->GetProximo();
    delete atual;
  }
  Tamanho = 0;
}

template <typename T>
Pilha<T>::~Pilha() {
  DestroiPilha();
}

template <typename T>
bool Pilha<T>::PilhaVazia() {
  return Tamanho == 0;
}

template <typename T>
void Pilha<T>::Empilha(T dado) {
  Elemento<T>* novo = new Elemento<T>(dado, Topo);
  if (novo == nullptr) {
    throw ERRO_PILHA_CHEIA;
  }
  Topo = novo;
  Tamanho++;
}

template <typename T>
T Pilha<T>::Desempilha() {
  if (PilhaVazia()) {
    throw ERRO_PILHA_VAZIA;
  }
  Elemento<T>* saiu = Topo;
  T volta = saiu->GetInfo();
  Topo = saiu->GetProximo();
  delete saiu;
  Tamanho--;
  return volta;
}

template <typename T>
T Pilha<T>::GetTopo() {
  if (PilhaVazia()) {
    throw ERRO_PILHA_VAZIA;
  }
  return Topo->GetInfo();
}

template <typename T>
int Pilha<T>::GetTamanho() {
  return Tamanho;
}

#endif
