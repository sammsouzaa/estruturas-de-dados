#include<iostream>
#include<string>
using namespace std;

typedef struct{
int idade;
string nome;
float altura;
} tPessoa;

void escreveIdades(tPessoa *p){
cout << p->idade << "\n";
cout << (p+1)->idade << "\n";
}

int main (){
tPessoa pessoas[2];
pessoas[0] = {0, "", 0.00};
pessoas[1] = {0, "", 0.00};
tPessoa *ppessoa;
ppessoa = &pessoas[0];
cout << pessoas[0].idade << "\n";
cout << "Digite idade: ";
cin >> pessoas[0].idade;
cout << pessoas[0].idade << "\n";
cout << "Idade pessoas[0]: ";
cout << ppessoa->idade << "\n";
ppessoa = &pessoas[1];
cout << "Idade pessoas[1]: ";
cout << ppessoa->idade << "\n";
escreveIdades(pessoas);
return 0;
}
