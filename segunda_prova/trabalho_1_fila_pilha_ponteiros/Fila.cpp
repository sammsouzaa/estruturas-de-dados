#ifndef _FILA_CPP
#define _FILA_CPP

#include "Fila.h"
#include "Elemento.h"

template <typename T>
Fila<T>::Fila() {
  Inicio = nullptr;
  Fim = nullptr;
  Tamanho = 0;
}

template <typename T>
void Fila<T>::DestroiFila() {
  Elemento<T>* atual;
  while (Inicio != nullptr) {
    atual = Inicio;
    Inicio = atual->GetProximo();
    delete atual;
  }
  Fim = nullptr;
  Tamanho = 0;
}

template <typename T>
Fila<T>::~Fila() {
  DestroiFila();
}

template <typename T>
bool Fila<T>::FilaVazia() {
  return Tamanho == 0;
}

template <typename T>
void Fila<T>::Inclui(T dado) {
  Elemento<T>* novo = new Elemento<T>(dado, nullptr);
  if (novo == nullptr) {
    throw ERRO_FILA_CHEIA;
  }
  if (FilaVazia()) {
    Inicio = novo;
    Fim = novo;
  } else {
    Fim->SetProximo(novo);
    Fim = novo;
  }
  Tamanho++;
}

template <typename T>
T Fila<T>::Retira() {
  if (FilaVazia()) {
    throw ERRO_FILA_VAZIA;
  }
  Elemento<T>* saiu = Inicio;
  T volta = saiu->GetInfo();
  Inicio = saiu->GetProximo();
  delete saiu;
  Tamanho--;
  if (Tamanho == 0) {
    Fim = nullptr;
  }
  return volta;
}

template <typename T>
T Fila<T>::GetPrimeiro() {
  if (FilaVazia()) {
    throw ERRO_FILA_VAZIA;
  }
  return Inicio->GetInfo();
}

template <typename T>
T Fila<T>::GetUltimo() {
  if (FilaVazia()) {
    throw ERRO_FILA_VAZIA;
  }
  return Fim->GetInfo();
}

template <typename T>
int Fila<T>::GetTamanho() {
  return Tamanho;
}

#endif
