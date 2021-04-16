#include <iostream>
#include <string>

using namespace std;

string palabra_original;
string palabra_mostrar;
int vidas;
int intentos;

void mostrar_persona();
void mostrar();
void ingresar(char x);
void iniciar();

int main() {
  iniciar();
  mostrar();
  while (vidas > 0 && palabra_mostrar != palabra_original) {
    char x;
    cin >> x;
    ingresar(x);
    mostrar();
  }
  if (vidas > 0) {
    cout << "Ganaste" << endl;
    cout << "Numero de intentos: " << intentos << endl;
  } else {
    cout << "Perdiste, la palabra era: " << palabra_original << endl;
    cout << "Numero de intentos: " << intentos << endl;
  }
}

void mostrar_persona() {
  if (vidas <= 6) {
    cout << " O " << endl;
    if (vidas <= 5) {
      cout << "/";
      if (vidas <= 4) {
        cout << "|";
        if (vidas <= 3) {
          cout << "\\" << endl;
          if (vidas <= 2) {
            cout << " | " << endl;
            if (vidas <= 1) {
              cout << "/ ";
              if (vidas <= 0)
                cout << "\\" << endl;
            }
          }
        }
      }
    }
  }
}

void mostrar() {
  mostrar_persona();
  cout << "\nvidas: " << vidas << endl;
  cout << palabra_mostrar << endl;
}

void iniciar() {
  vidas = 7;
  intentos = -1;
  palabra_original = "trabajo";

  for (int i = 0; i < palabra_original.length(); i++) {
    if (palabra_original[i] >= 'A' && palabra_original[i] <= 'Z') {
      palabra_original[i] += 32;
    }
  }
  for (int i = 0; i < palabra_original.length(); i++) {
    if (palabra_original[i] >= 'a' && palabra_original[i] <= 'z') {
      palabra_mostrar += 'x';
    } else {
      palabra_mostrar += palabra_original[i];
    }
  }
}

void ingresar(char x) {
  bool perdiVidas = true;

  for (int i = 0; i < palabra_original.length(); i++) {
    if (x == palabra_original[i]) {
      perdiVidas = false;
      palabra_mostrar[i] = x;
      intentos++;
    }
  }
  if (perdiVidas) {
    vidas--;
    intentos++;
  }
}
