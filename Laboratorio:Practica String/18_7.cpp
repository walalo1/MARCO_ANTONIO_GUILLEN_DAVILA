#include <cctype>
#include <iostream>
#include <string>
using namespace std;

string ROT13(string a);

int main() {
  string texto;
  cout << "Ingrese el texto: ";
  getline(cin, texto);
  cout << "Resultado: " << ROT13(texto) << endl;
  return 0;
}
// funcion para cifrado y descifrado
string ROT13(string a) {
  string resultado;
  for (int i = 0; i < a.size(); ++i) {
    // para ver si es a[i] pertenece al alfabeto
    if (isalpha(a[i])) {
      // el tolower es para que si nos topamos con una mayuscula esta por el
      // momento se convierta en minuscila para poder ser comparada con a
      if ((tolower(a[i]) - 'a') < 13)
        // se le agrega al string resultado la letra cifrada con append
        resultado.append(1, a[i] + 13);
      else
        // debido a la naturaleza del alfabeto ingel que solo tiene 26 letras
        // nos podemos desplazar sumando 13 o restando 13 para reaccionar valor,
        // en este caso tenemos que restar 13 puesto que excede a 'a' en 13 y si
        // le sumanos 13 se saldria del rango de las letras en ascii.
        resultado.append(1, a[i] - 13);
      // si no es aflabetico se agrega de frente
    } else {
      resultado.append(1, a[i]);
    }
  }
  return resultado;
}
