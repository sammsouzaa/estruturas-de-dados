#include "Rodinha.h"

Rodinha::Rodinha(Mesa* mesa):Decorator(mesa){}

string Rodinha::getDescricao(){
  return Amesa->getDescricao() + " com Rodinha";
}
