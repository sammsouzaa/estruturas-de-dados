#include <iostream>
#include <string>
using namespace std;

int main(){
  string cumprimento = "Ola ";
  string nome = "Leonardo ";
  string sobrenome = "Medeiros";
  
  cout << cumprimento + nome + sobrenome + "\n";
  
  string nomeCompleto = nome.append(sobrenome);
  cout << nomeCompleto << " tem " << nomeCompleto.length() << " caracteres.\n";
  cout << "Agora digite seu nome: ";
  
  getline(cin, nomeCompleto);
  cout << nomeCompleto << " tem " << nomeCompleto.length() << " caracteres";  
  return 0; 
}
