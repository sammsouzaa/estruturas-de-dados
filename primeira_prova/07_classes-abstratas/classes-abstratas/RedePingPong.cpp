#include "RedePingPong.h"

RedePingPong::RedePingPong(Mesa* mesa):Decorator(mesa){}

string RedePingPong::getDescricao(){
  return Amesa->getDescricao() + " com Rede de Ping Pong";
}
