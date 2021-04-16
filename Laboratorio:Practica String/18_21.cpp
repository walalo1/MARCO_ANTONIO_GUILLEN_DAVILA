#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main() {
  string cadena1;
  cout << "Ingrese texto: ";
  cin >> cadena1;
  int longitud = cadena1.length();
  char *ptr2 = new char[longitud + 1];
  cadena1.copy(ptr2, longitud, 0);
  ptr2[longitud] = '\0';
  char *pch;
  cout << "El mensaje " << ptr2 << " se convierte en:" << endl;
  pch = strtok(ptr2, " ,.-?!¡¿;:´");
  while (pch != NULL) {
    cout << pch << endl;
    pch = strtok(NULL, " ,.-?!¡¿;:´");
  }
  return 0;
}
