#include <float.h>

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  cout << fixed << setprecision(5) << "max = " << FLT_MAX << endl;
  cout << fixed << setprecision(5) << "min = " << -FLT_MAX << endl;
}