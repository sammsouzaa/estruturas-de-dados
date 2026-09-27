#ifndef _PROFESSOR_H
#define _PROFESSOR_H

#include <iostream>
#include <string>
#include "Trabalhador.h"
using namespace std;

class Professor: public Trabalhador{
 private:
  string Assunto;
 public:
  void SetAssunto(string assunto);
  string GetAssunto();
  void PrepararAula();
  void Trabalho();
  Professor(string nome, int idade, string organizacao, string assunto);
};

#endif
