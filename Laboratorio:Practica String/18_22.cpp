#include <iostream>
#include <string>
using namespace std;

int main() {
  string cadena1;
  cout << "Ingrese texto: ";
  cin >> cadena1;
  string::const_iterator iterador1 = cadena1.end();
  cout << "Texto invertido: ";
  while (iterador1 >= cadena1.begin()) {
    cout << *iterador1;
    iterador1--;
  }
  cout << endl;
  return 0;
}
