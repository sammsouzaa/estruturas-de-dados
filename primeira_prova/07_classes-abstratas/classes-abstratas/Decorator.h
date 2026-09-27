#ifndef _DECORATOR_H
#define _DECORATOR_H

#include "Mesa.h"

class Decorator: public Mesa{
 protected:
  Mesa* Amesa;
 public:
  Decorator(Mesa* mesa);
  string getDescricao();
};

#endif
