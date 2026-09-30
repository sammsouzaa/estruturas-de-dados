#ifndef _LISTA_CPP
#define _LISTA_CPP

#include "Lista.h"
#include "Elemento.h"

template <typename T>
Lista<T>::Lista() {
  Dados = nullptr;
  Tamanho = 0;
  Capacidade = -1;
}

template <typename T>
Lista<T>::Lista(int capacidade) {
  Dados = nullptr;
  Tamanho = 0;
  Capacidade = capacidade;
}

template <typename T>
void Lista<T>::LimpaLista() {
  DestroiLista();
}

template <typename T>
void Lista<T>::DestroiLista() {
  Elemento<T>* atual;
  while (Dados != nullptr) {
    atual = Dados;
    Dados = atual->GetProximo();
    delete atual;
  }
  Tamanho = 0;
}

template <typename T>
Lista<T>::~Lista() {
  DestroiLista();
}

template <typename T>
bool Lista<T>::ListaVazia() {
  return Tamanho == 0;
}

template <typename T>
bool Lista<T>::ListaCheia() {
  if (Capacidade <= 0) return false;
  return Tamanho >= Capacidade;
}

template <typename T>
int Lista<T>::GetTamanho() {
  return Tamanho;
}

template <typename T>
void Lista<T>::AdicionaNoInicio(T dado) {
  if (ListaCheia()) {
    throw ERRO_LISTA_CHEIA;
  }
  Elemento<T>* novo = new Elemento<T>(dado, Dados);
  if (novo == nullptr) {
    throw ERRO_LISTA_CHEIA;
  }
  Dados = novo;
  Tamanho++;
}

template <typename T>
T Lista<T>::RetiraDoInicio() {
  if (ListaVazia()) {
    throw ERRO_LISTA_VAZIA;
  }
  Elemento<T>* saiu = Dados;
  T volta = saiu->GetInfo();
  Dados = saiu->GetProximo();
  delete saiu;
  Tamanho--;
  return volta;
}

template <typename T>
void Lista<T>::EliminaDoInicio() {
  if (ListaVazia()) {
    throw ERRO_LISTA_VAZIA;
  }
  Elemento<T>* saiu = Dados;
  Dados = saiu->GetProximo();
  delete saiu;
  Tamanho--;
}

template <typename T>
void Lista<T>::AdicionaNaPosicao(T dado, int posicao) {
  if (ListaCheia()) {
    throw ERRO_LISTA_CHEIA;
  }
  if (posicao < 0 || posicao > Tamanho) {
    throw ERRO_POSICAO;
  }
  if (posicao == 0) {
    AdicionaNoInicio(dado);
    return;
  }
  Elemento<T>* anterior = Dados;
  for (int i = 0; i < posicao - 1; i++) {
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
T Lista<T>::RetiraDaPosicao(int posicao) {
  if (ListaVazia()) {
    throw ERRO_LISTA_VAZIA;
  }
  if (posicao < 0 || posicao >= Tamanho) {
    throw ERRO_POSICAO;
  }
  if (posicao == 0) {
    return RetiraDoInicio();
  }
  Elemento<T>* anterior = Dados;
  for (int i = 0; i < posicao - 1; i++) {
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
void Lista<T>::AdicionaEmOrdem(T dado) {
  if (ListaCheia()) {
    throw ERRO_LISTA_CHEIA;
  }
  if (ListaVazia()) {
    AdicionaNoInicio(dado);
    return;
  }
  Elemento<T>* atual = Dados;
  int pos = 0;
  while (atual != nullptr && dado > atual->GetInfo()) {
    atual = atual->GetProximo();
    pos++;
  }
  AdicionaNaPosicao(dado, pos);
}

template <typename T>
void Lista<T>::Adiciona(T dado) {
  AdicionaNaPosicao(dado, Tamanho);
}

template <typename T>
T Lista<T>::Retira() {
  return RetiraDaPosicao(Tamanho - 1);
}

template <typename T>
T Lista<T>::RetiraEspecifico(T dado) {
  int pos = Posicao(dado);
  return RetiraDaPosicao(pos);
}

template <typename T>
int Lista<T>::Posicao(T dado) {
  Elemento<T>* atual = Dados;
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
bool Lista<T>::Contem(T dado) {
  try {
    Posicao(dado);
    return true;
  } catch (...) {
    return false;
  }
}

#endif
