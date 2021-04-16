#include <iostream>
#include <string>
using namespace std;

int main() {
  string cadena;
  int espacio;
  cout << "Ingrese su texto: ";
  getline(cin, cadena);
  cout << "\ningrese el tamaño de los bloques: ";
  cin >> espacio;
  for (int i = 0; i < cadena.length(); i++) {
    cout << cadena[i];
    if (i % espacio == 0 && i > 0) {
      cout << "*";
    }
    if (cadena.length() % 4 != 0) {
      cadena.insert(cadena.end(), 'X');
    }
  }
  cout << endl;

  return 0;
}
