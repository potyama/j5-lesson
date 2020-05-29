/*
実行結果
自作:0.006737946998328
正解:0.006737946999085
*/

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

float exp() {
  // |e - d|を打ち切り誤差、|e - d|/|d|を相対打ち切り誤差とする。
  float d = 1.0;
  float e = 1.0;
  float tay = 1.0;
  float x = -5;
  for (int n = 1; n <= 20; n++) {
    d = e;
    tay = tay * fabsf(x) / n;
    e += tay;
  }
  return 1.0 / e;
}

int main() {
  cout << exp() << endl;
  cout << exp(-5) << endl;
}