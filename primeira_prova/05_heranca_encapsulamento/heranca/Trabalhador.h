#ifndef _TRABALHADOR_H
#define _TRABALHADOR_H

#include <iostream>
#include <string>
using namespace std;

class Trabalhador{
private:
  string Nome;
  int Idade;
  string Organizacao;
public:
  string GetNome();
  void SetNome(string nome);
  int GetIdade();
  void SetIdade(int idade);
  string GetOrganizacao();
  void SetOrganizacao(string organizacao);
  void ApresenteSe();
  Trabalhador();
  Trabalhador(string nome, int idade, string organizacao);
};

#endif
