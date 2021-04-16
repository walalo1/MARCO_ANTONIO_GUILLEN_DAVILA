#include <iostream>
using namespace std;

int main() {
  string a, b, c;
  cout << "Ingrese nombre: ";
  cin >> a;
  cout << "Ingrese apellido: ";
  cin >> b;
  c = a + " " + b;
  cout << "Completo: " << c << endl;
  return 0;
}
