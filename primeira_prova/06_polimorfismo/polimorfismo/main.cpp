#include <iostream>
#include <string>
#include "Trabalhador.h"
#include "Professor.h"
#include "Desenvolvedor.h"
using namespace std;

int main(){
  Trabalhador* t1 = new Trabalhador("Leo", 42, "Unioeste");
  Trabalhador* p1 = new Professor("Victor", 45, "Unioeste", "PES");
  Trabalhador* d1 = new Desenvolvedor("Luana", 36, "Serpro", "C++");
  t1->ApresenteSe();
  p1->ApresenteSe();
  d1->ApresenteSe();
  dynamic_cast<Professor *>(p1)->PrepararAula();
  dynamic_cast<Desenvolvedor *>(d1)->CorrigirBug();
  t1->Trabalho();
  p1->Trabalho();
  d1->Trabalho();
  return 0;
}
