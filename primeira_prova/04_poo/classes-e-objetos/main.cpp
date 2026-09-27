#include <iostream>
#include <string>
#include "Trabalhador.h"
using namespace std;

int main(){

  Trabalhador t1;
  Trabalhador t2("Leonardo", 42, "Unioeste");
  Trabalhador *t3 = new Trabalhador("Victor", 40, "Unioeste");

  t1.ApresenteSe();
  t1.SetNome("Leo");
  t1.ApresenteSe();
  t2.ApresenteSe();
  t3->ApresenteSe();
  delete t3;

  return 0;
}
