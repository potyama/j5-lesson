#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double a, b, c, D = 0;
  cin >> a >> b >> c;
  D = ((b * b) - (4 * a * c));

  double x1 = 0, x2 = 0;
  if (D >= 0) {
    x1 = (-b + sqrt(D)) / (2.0 * a);

    //二次方程式での解と係数の関係でわかるで
    x2 = c / (a * x1);
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
  } else {
    cout << "Im" << endl;
  }
}