#ifndef _RODINHA_H
#define _RODINHA_H

#include "Decorator.h"

class Rodinha: public Decorator {
 public:
  Rodinha(Mesa* mesa);
  string getDescricao();
};

#endif
