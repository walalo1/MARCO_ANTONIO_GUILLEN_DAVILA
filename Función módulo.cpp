#include <iostream>
using namespace std;

int division(int a, int n) {
  int r = a - (a / n) * n;
  if (r < 0)
    return r + n;
  else
    return r;
}

int main() {
  int a, n;
  cin >> a >> n;
  cout << division(a, n) << endl;
}
