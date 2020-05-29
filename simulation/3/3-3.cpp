#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  //もし、ずらしたくなかったらdouble型をlong double型にしたらOK!!!!

  double variable1 = 123456789.0;
  double variable2 = 123456789.0;

  for (int i = 0; i < 10; i++) {
    variable1 += 0.000000001;
    variable2 += 0.00000001;
  }
  cout << fixed << setprecision(26) << variable1 << ":" << variable2 << endl;
}