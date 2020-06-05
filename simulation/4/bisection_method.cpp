#include <algorithm>
#include <cmath>
#include <iostream>

#define ll long long
using namespace std;

double func(double x) { return pow(x, 2) - 2; }

double bm(double a, double b, ll x) {
  double c;

  for (int i = 0; i < x; i++) {
    c = (a + b) / 2.0;
    if (func(c) * func(a) < 0) {
      b = c;
    } else {
      a = c;
    }
  }
  cout << "ans_a = " << a << endl;
  cout << "ans_b = " << b << endl;
  return c;
}

int main() {
  double a, b;
  cin >> a >> b;
  ll N;
  cin >> N;
  double x;

  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  x = bm(a, b, N);
  cout << "x = " << x << endl;
}