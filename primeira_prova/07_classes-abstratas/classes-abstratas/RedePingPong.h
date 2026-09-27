#ifndef _REDEPINGPONG_H
#define _REDEPINGPONG_H

#include "Decorator.h"

class RedePingPong: public Decorator {
 public:
  RedePingPong(Mesa* mesa);
  string getDescricao();
};

#endif 
