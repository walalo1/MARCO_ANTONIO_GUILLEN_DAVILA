#include <iostream>
#include <string>
using namespace std;

int main() {
  string numero;
  cout << "Ingrese numero: ";
  cin >> numero;
  int numero1 = stoi(numero);
  cout << numero1 << endl;
  return 0;
}
