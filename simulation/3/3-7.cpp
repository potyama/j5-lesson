#include <float.h>

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  cout << fixed << setprecision(10) << "machineEpsilon = " << FLT_EPSILON
       << endl;
}
