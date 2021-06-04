#include <NTL/ZZ.h>
#include <iostream>
using namespace NTL;
using namespace std;

// mcd
ZZ mcd(ZZ a, ZZ b) {
  if (b == 0) {
    return a;
  }

  return mcd(b, a % b);
}
// funcion modulo
ZZ mod(ZZ a, ZZ n) {
  ZZ r = a - (a / n) * n;
  if (r < 0)
    return r + n;
  else
    return r;
}
// inversa
ZZ Inverse(ZZ a, ZZ m) {
  for (ZZ x{1}; x < m; x++) {
    if (mod((mod(a, m) * mod(x, m)), m) == 1)
      return x;
  }
  return a;
}

// mod elevacion "arreglar"
ZZ modEle(ZZ a, ZZ b, ZZ n) {
  ZZ r = mod(a, n);
  ZZ f{0};
  ZZ x;
  ZZ t{3};
  ZZ d{2};
  ZZ resto = r;
  for (ZZ i = b / 2; i >= 1; i = i / 2) {
    x = mod(r * r, n) * mod(i, d);
    if (x != 0)
      f = mod(r * resto, n);
    r = x;
    resto = f;
    cout << "R: " << endl;
    cout << r << endl;
    cout << "fin r" << endl;
  }
  if (b > t)
    f = mod(70 * r, n);
  cout << f << endl;
  return f;
}

// resto chino
ZZ restoChino(ZZ p, ZZ q, ZZ d, ZZ C) {
  ZZ P = p * q;
  ZZ a1 = modEle(C, mod(d, p - 1), P), a2 = modEle(C, mod(d, q - 1), P);
  ZZ p1 = q, p2 = p;
  ZZ q1 = Inverse(mod(p1, p), p), q2 = Inverse(mod(p2, q), q);
  ZZ Do = mod(mod(mod(mod(a1, P) * mod(q, P), P) * mod(q1, P), P) +
                  mod(mod(mod(a2, P) * mod(p, P), P) * mod(q2, P), P),
              P);
  cout << mod(d, q - 1) << endl;
  cout << mod(mod(mod(a2, P) * mod(p, P), P) * mod(q2, P), P) << endl;
  return Do;
}
int main() {
  ZZ p{11}, q{13}, d{103}, C{115};
  cout << restoChino(p, q, d, C) << endl;
  return 0;
}
