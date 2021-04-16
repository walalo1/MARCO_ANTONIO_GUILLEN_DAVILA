#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void ordenamientoSeleccion(string[], const int, bool (*)(int, int));
void intercambiar(int *const, int *const);
bool ascendente(int, int);
bool descendente(int, int);

int main() {
  const int tamanioArreglo = 10;
  int orden;    // 1 = ascendente, 2 = descendente
  int contador; // subíndice del arreglo
  string a[tamanioArreglo] = {"perro",
                              "hola",
                              "o",
                              "ah",
                              "yes",
                              "babero",
                              "abduzcan",
                              "comoestas",
                              "ablaqueadoras",
                              "semitransparentes"};
  cout << "Escriba 1 para orden ascendente,\n"
       << "Escriba 2 para orden descendente: ";
  cin >> orden;
  cout << "\nElementos de datos en el orden original\n";
  for (contador = 0; contador < tamanioArreglo; contador++)
    cout << " " << a[contador];
  if (orden == 1) {
    ordenamientoSeleccion(a, tamanioArreglo, ascendente);
    cout << "\nElementos de datos en orden ascendente\n";
  } // fin de if
  else {
    ordenamientoSeleccion(a, tamanioArreglo, descendente);
    cout << "\nElementos de datos en orden descendente\n";
  }
  for (contador = 0; contador < tamanioArreglo; contador++)
    cout << setw(18) << a[contador];
  cout << endl;
  return 0;
}

void ordenamientoSeleccion(string trabajo[], const int tamanio,
                           bool (*compara)(int, int)) {
  int menorOMayor;
  for (int i = 0; i < tamanio - 1; i++) {
    menorOMayor = i;
    for (int index = i + 1; index < tamanio; index++)
      if (!(*compara)(trabajo[menorOMayor].size(), trabajo[index].size()))
        menorOMayor = index;
    trabajo[menorOMayor].swap(trabajo[i]);
  }
}

bool ascendente(int a, int b) { return a < b; }
bool descendente(int a, int b) { return a > b; }
