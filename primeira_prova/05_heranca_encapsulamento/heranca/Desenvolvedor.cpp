#include <iostream>
#include <string>
#include "Desenvolvedor.h"
using namespace std;

void Desenvolvedor::SetLP(string lp){
  LP = lp;
}

string Desenvolvedor::GetLP(){
  return LP;
}

void Desenvolvedor::CorrigirBug(){
  cout << GetNome() << " está corrigindo um bug usando " << LP << ".\n";
}

Desenvolvedor::Desenvolvedor(string nome, int idade, string organizacao, string lp):Trabalhador(nome, idade, organizacao){
  LP = lp;
}
