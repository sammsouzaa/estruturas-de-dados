#include <iostream>
#include <string>
#include "Trabalhador.h"
#include "Professor.h"
#include "Desenvolvedor.h"
using namespace std;

int main(){
  
  Trabalhador t1;
  Professor p1("Leonardo", 42, "Unioeste", "Estruturas de Dados");
  Professor *p2 = new Professor("Victor", 40, "Unioeste", "PES");
  Desenvolvedor *d1 = new Desenvolvedor("Luana", 35, "Serpro", "C++");

  t1.ApresenteSe();
  t1.SetNome("Leo");
  t1.ApresenteSe();

  p1.ApresenteSe();
  p1.PrepararAula();

  p2->PrepararAula();
  delete p2;

  d1->CorrigirBug();
  d1->ApresenteSe();
  delete d1;
  return 0;
}
