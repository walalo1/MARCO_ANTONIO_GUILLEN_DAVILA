#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

static const string alfabeto = "abcdefghijklmnopqrstuvwxyz";

int Random(int m) {
  int resultado;
  resultado = rand() % m + 1;
  return resultado;
}

int mcd(int a, int b) {
  while (b != 0) {
    int aux = b;
    b = a % b;
    a = aux;
  }
  return a;
}

int mod(int a, int n) {
  // cout << "a: " << a << " "
  //     << "n: " << n << endl;
  int r = a - (a / n) * n;
  if (r < 0)
    return r + n;
  else
    return r;
}

int modInverse(int a, int m) {
  for (int x = 1; x < m; x++)
    if (mod((mod(a, m) * mod(x, m)), m) == 1)
      return x;
}

struct Clave {
public:
  Clave() {}
  // Genera a y b aleatorio
  Clave(int m) : _m(m) {
    _a = Random(m);
    _b = Random(m);
    int r = mcd(m, _a);
    while (r != 1) {
      _a = Random(m);
      r = mcd(m, _a);
    }
  }
  // Pasa los valores.
  Clave(int a, int b, int m) : _a(a), _b(b), _m(m) {}
  // Retorna la inversa.
  Clave Inversa() { return Clave(modInverse(_a, _m), mod(-_b, _m), _m); }
  // Imprimir.
  void Imprimir() const {
    cout << "a: " << _a << endl;
    cout << "b: " << _b << endl;
    cout << "m: " << _m << endl;
  }
  Clave &operator=(const Clave &clave) {
    _a = clave._a;
    _b = clave._b;
    _m = clave._m;
    return *this;
  }
  int a() const { return _a; }
  int b() const { return _b; }
  int m() const { return _m; }

private:
  int _a;
  int _b;
  int _m; // tamanho del alfabeto
};

class Cifrado {

public:
  string Cifrar(const Clave &clave, const string &texto);
  string Desifrar(const Clave &clave, const string &texto);
};

int main() {
  srand(time(NULL));
  string texto;
  int accion;
  cout << "Que va a hacer: \n1.Encriptar. \n2.Desencriptar.\n";
  cin >> accion;
  cout << "Ingrese mensaje: ";
  getline(cin, texto);
  getline(cin, texto);
  if (accion == 2) {
    // Descencriptar
    cout << "Tipo de clave: \n1.Emisor. \n2.Receptor.\n";
    int clave_tipo;
    cin >> clave_tipo;
    int a, b;
    cout << "Ingresa clave: \n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    Clave clave;
    if (clave_tipo == 1) {
      // Emisor
      clave = Clave(a, b, alfabeto.size()).Inversa();
    } else {
      // Receptor
      clave = Clave(a, b, alfabeto.size());
    }
    cout << "Usando clave: \n";
    clave.Imprimir();
    Cifrado cifrador;
    string descifrado = cifrador.Desifrar(clave, texto);
    cout << "Texto descifrado:\n" << descifrado << endl;
  } else if (accion == 1) {
    // Genera clave aleatoria.
    Clave clave(alfabeto.size());
    Cifrado cifrador;
    cout << "Usando clave emisor: \n";
    clave.Imprimir();
    string cifrado = cifrador.Cifrar(clave, texto);
    cout << "Texto cifrado:\n" << cifrado << endl;
    cout << "Clave receptor: \n";
    clave.Inversa().Imprimir();
  }
  return 0;
}

/*
// Fuerza bruta
void Cifrado::Descifrar() {
string respuesta = "";
string descifrado = "";
int a, b, a_inversa, max = 0;
for (a = 0; a < alphabet.length(); a++) {
if (mcd(alphabet.length(), a) == 1) {
a_inversa = modInverse(a, alphabet.length());
for (b = 0; b < alphabet.length(); b++) {
for (int i = 0; i < texto.length(); i++) {
for (int j = 0; j < alphabet.length(); j++) {
if (texto[i] == alphabet[j])
descifrado +=
alphabet[mod(((j - b) * mod(a_inversa, alphabet.length())),
alphabet.length())];
}
}
cout << "a: " << a << endl;
cout << "b: " << b << endl;
cout << "Respuesta: " << descifrado << endl;
descifrado = "";
}
}
}
cout << "Respuesta: " << respuesta << endl;
}
*/

string Cifrado::Cifrar(const Clave &clave, const string &texto) {
  string cifrado;

  // clave.Imprimir();
  for (int i = 0; i < texto.length(); i++) {
    for (int j = 0; j < alfabeto.size(); j++) {
      if (texto[i] == alfabeto[j]) {
        // cout << texto[i] << " " << j << " "
        //     << mod(clave.a() * j + mod(clave.b(), clave.m()), clave.m())
        //     << "\n";
        cifrado +=
            alfabeto[mod(clave.a() * j + mod(clave.b(), clave.m()), clave.m())];
      }
    }
  }
  return cifrado;
}

string Cifrado::Desifrar(const Clave &clave, const string &texto) {
  string descifrado;

  // clave.Imprimir();
  for (int i = 0; i < texto.length(); i++) {
    for (int j = 0; j < alfabeto.size(); j++) {
      if (texto[i] == alfabeto[j]) {
        // cout << texto[i] << " " << j << " "
        //     << mod(clave.a() * j + mod(clave.b(), clave.m()), clave.m())
        //     << "\n";
        descifrado += alfabeto[mod(clave.a() * (j + mod(clave.b(), clave.m())),
                                   clave.m())];
      }
    }
  }
  return descifrado;
}
