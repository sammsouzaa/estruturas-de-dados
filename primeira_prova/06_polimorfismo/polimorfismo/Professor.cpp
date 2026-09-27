#include <iostream>
#include <string>
#include "Professor.h"
using namespace std;

void Professor::SetAssunto(string assunto){
  Assunto = assunto;
}

string Professor::GetAssunto(){
  return Assunto;
}

void Professor::PrepararAula(){
  cout << GetNome() << " está preparando uma aula de " << Assunto << ".\n";
}

void Professor::Trabalho(){
  cout << GetNome() << " está ensinando " << Assunto << ".\n";
}

Professor::Professor(string nome, int idade, string organizacao, string assunto):Trabalhador(nome, idade, organizacao){
  Assunto = assunto;
}
