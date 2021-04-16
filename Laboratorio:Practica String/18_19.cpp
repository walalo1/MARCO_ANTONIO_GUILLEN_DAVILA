#include <iostream>
#include <string>
using namespace std;

int main() {
  string a;
  string b = "******";
  cout << "ingrese texto: ";
  cin >> a;
  a.insert(a.size() / 2, b);
  cout << a << endl;
  return 0;
}
