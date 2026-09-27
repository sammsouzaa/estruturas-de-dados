#include <iostream>
#include <string>
#include "Trabalhador.h"
using namespace std;

  string Trabalhador::GetNome(){
    return Nome;
  }
  void Trabalhador::SetNome(string nome){
    Nome = nome;
  }
  int Trabalhador::GetIdade(){
    return Idade;
  }
  void Trabalhador::SetIdade(int idade){
    Idade = idade;
  }
  string Trabalhador::GetOrganizacao(){
    return Organizacao;
  }
  void Trabalhador::SetOrganizacao(string organizacao){
    Organizacao = organizacao;
  }
  void Trabalhador::ApresenteSe(){
    cout << "Nome: " << Nome << "\t";
    cout << "Idade: " << Idade << "\t";
    cout << "Organizacao: " << Organizacao << "\n";
  }
  Trabalhador::Trabalhador(){
    Nome = "Sem nome";
    Idade = -1;
    Organizacao = "Sem organização";
  }
  Trabalhador::Trabalhador(string nome, int idade, string organizacao){
    Nome = nome;
    Idade = idade;
    Organizacao = organizacao;
  }
