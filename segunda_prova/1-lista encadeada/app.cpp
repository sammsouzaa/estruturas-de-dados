#include <iostream>
#include "Lista.h"

using namespace std;

int main(){
  Lista<int> li ;
  li.AdicionaNoInicio(1);
  li.AdicionaNoInicio(2);
  li.AdicionaNoInicio(3);
  cout << "Lista\n";
  cout << li.RetiraDoInicio() << "\n";
  cout << li.RetiraDoInicio() << "\n";
  cout << li.RetiraDoInicio() << "\n";
  return 0; 
}
