#ifndef _DESENVOLVEDOR_H_
#define _DESENVOLVEDOR_H_

#include <iostream>
#include <string>
#include "Trabalhador.h"

class Desenvolvedor: public Trabalhador{
 private:
  string LP;
 public:
  void SetLP(string lp);
  string GetLP();
  void CorrigirBug();
  Desenvolvedor(string nome, int idade, string organizacao, string lp);
};

#endif
