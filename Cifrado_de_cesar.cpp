#include <iostream>
#include <string>
#include <tuple>

using namespace std;
//si el alfabeto es diferente a las pruebas solo modificar
const string alfabeto =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz1234567890-.";

class CodificadorCesar {

public:
  CodificadorCesar() {}
  string encriptar(string, int);
  string desencriptar(string, int);
  tuple<string, int> Romper(string);
};

int main() {
  int clave, accion;
  cout << "Que va a hacer: \n1.Encriptar. \n2.Desencriptar.\n3.Romper.\n";
  cin >> accion;
  string mensaje;
  getline(cin, mensaje);
  if (accion == 1 || accion == 2) {
    cout << "Ingrese mensaje: ";
    getline(cin, mensaje);
    cout << "Clave: ";
    cin >> clave;
    CodificadorCesar a;
    if (accion == 1)
      cout << "Mensaje encriptado:\n" << a.encriptar(mensaje, clave) << endl;
    else
      cout << "Mensaje descencriptado:\n"
           << a.desencriptar(mensaje, clave) << endl;

  } else {
    CodificadorCesar a;
    cout << "Ingrese mensaje: ";
    getline(cin, mensaje);
    const tuple<string, int> resultado = a.Romper(mensaje);
    cout << "Mensaje descencriptado:\n"
         << get<0>(resultado) << "\nClave usada:\n"
         << get<1>(resultado) << "\n";
  }

  return 0;
}

// Metodos y Constructores:

int mod(int a, int n) {
  int r = a - (a / n) * n;
  if (r < 0)
    return r + n;
  else
    return r;
}

string CodificadorCesar::encriptar(string mens, int clave) {
  string cifrado = "";
  for (int i = 0; i < mens.length(); i++) {
    for (int j = 0; j < alfabeto.length(); j++) {
      if (mens[i] == alfabeto[j]) {
        cifrado += alfabeto[mod(j + clave, alfabeto.length())];
      } else if (mens[i] == ' ') {
        cifrado += mens[i];
        break;
      }
    }
  }
  return cifrado;
};

string CodificadorCesar::desencriptar(string mens, int clave) {
  string descifrado = "";
  for (int i = 0; i < mens.length(); i++) {
    for (int j = 0; j < alfabeto.length(); j++) {
      if (mens[i] == alfabeto[j]) {
        descifrado += alfabeto[mod(j - clave, alfabeto.length())];
      } else if (mens[i] == ' ') {
        descifrado += mens[i];
        break;
      }
    }
  }
  return descifrado;
}

bool EsVocal(char x) {
  static const string vocales = "aeiouAEIOU";
  for (char v : vocales) {
    if (v == x)
      return true;
  }
  return false;
}

tuple<string, int> CodificadorCesar::Romper(string mens) {
  string respuesta;
  int maxNumVocales = 0;
  int clave_respuesta = -1;
  for (int clave = 0; clave < alfabeto.length(); ++clave) {
    string desenc = desencriptar(mens, clave);
    int numeroV = 0;
    for (int j = 0; j < mens.length(); j++) {
      if (EsVocal(desenc[j])) {
        numeroV++;
      }
    }
    if (maxNumVocales < numeroV) {
      maxNumVocales = numeroV;
      respuesta = desenc;
      clave_respuesta = clave;
    }
  }
  return make_tuple(respuesta, clave_respuesta);
}
