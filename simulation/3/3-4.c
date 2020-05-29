#include <stdio.h>
#define ui unsigned int
int main() {
  ui a = 1840083528, b = 1343303455;
  long c = 1840083528, d = 1343303455;
  printf("%u=%u", a + b, c + d);
}