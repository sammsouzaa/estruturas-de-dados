#include "Decorator.h"

Decorator::Decorator(Mesa* mesa):Amesa(mesa){
}

string Decorator::getDescricao(){
  return Amesa->getDescricao();
}
