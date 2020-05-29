#include <iostream>

using namespace std;

int main() {
  double variable = 0.0;

  for (int i = 0; i < 1000000; i++) {
    variable += 0.1;
  }
  cout << variable << endl;
}