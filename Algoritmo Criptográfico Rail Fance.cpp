#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

string EncriptacionRail(string original, int r);

string DecriptacionRail(string encriptado, int r);



int main() {
  cout << "Ingresar operacion:\n[0] Encriptar \n[1] Desencriptar:\n";
  bool desencriptar = false;
  cin >> desencriptar;
  string texto;
  cout << "Ingresar texto:" << endl;
  getline(cin, texto);
  getline(cin, texto);
  cout << "Ingresar el numero de Rail: ";
  int r;
  cin >> r;
  string resultado;
  if (desencriptar) {
    resultado = DecriptacionRail(texto, r);
  } else {
    resultado = EncriptacionRail(texto, r);
  }
  cout << "Resultado:" << endl << resultado << endl;
  return 0;
}




string EncriptacionRail(string original, int r) {
  string resultado;
  for (int radio = r - 1; radio >= 0; --radio) {
    for (int pivote = r - 1; pivote - radio < original.size();
         pivote += 2 * r - 2) {
      for (int dir = -1; dir <= 1; dir += 2) {
        int pos = pivote + dir * radio;
        if (pos >= original.size()) {
          continue;
        }
        if (original[pos]) {
          resultado += original[pos];
          original[pos] = 0;
        }
      }
    }
  }
  return resultado;
}

string DecriptacionRail(string encriptado, int r) {
  vector<int> contador(r, 0);
  int len = encriptado.size();
  // Calcula el numero de elementos for fila.
  for (int i = 0; i < r; ++i) {
    int forward_len = (len - i);
    if (forward_len > 0) {
      contador[i] = (forward_len - 1) / (2 * r - 2) + 1;
    }
    if (i > 0 && i < (r - 1)) {
      int forward_len = len - (2 * r - 2 - i);
      if (forward_len > 0) {
        contador[i] += (forward_len - 1) / (2 * r - 2) + 1;
      }
    }
  }
  // Acumula los elementos de todas las filas.
  for (int i = 1; i < r; ++i) {
    contador[i] += contador[i - 1];
  }
  string resultado;
  resultado += encriptado[0];
  // Itera las posiciones en orden para llenar el resultado.
  for (int dir = 1, j = 1, diagonal = 0; resultado.size() < len;
       dir *= -1, ++diagonal, j += 2 * dir) {
    for (int i = 1; i < r && resultado.size() < len; ++i, j += dir) {
      int posicion = 0;
      if (j == r - 1) {
        posicion = diagonal / 2;
      } else if (j == 0) {
        posicion = (diagonal + 1) / 2;
      } else {
        posicion = diagonal;
      }
      if (j > 0) {
        posicion += contador[j - 1];
      }
      resultado += encriptado[posicion];
    }
  }
  return resultado;
}
