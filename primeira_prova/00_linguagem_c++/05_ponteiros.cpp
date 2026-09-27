#include <iostream>
#include <string>
using namespace std;
int main()
{
string alimento = "Abacate";
string *ptr = &alimento;
cout << alimento << "\n";
cout << &alimento << "\n";
cout << ptr << "\n";
cout << *ptr << "\n";
return 0;
}
