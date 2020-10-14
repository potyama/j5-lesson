/*y = a1 * x + a0
  a0 = 1030, a1 = 70
  x = 8 -> 1590
   x = 13 -> 1940
  , x = 30 -> 3130
*/

#include <stdio.h>

void lsm(int x[], int y[], int N, int *a0, int *a1){

    int A_00 = 0, A_01 = 0, A_02 = 0, A_11 = 0, A_12 = 0;

    for(int i = 0; i < N; i++){
        A_00 += 1,0;
        A_01 += x[i];
        A_02 += y[i];
        A_11 += x[i] * x[i];
        A_12 += x[i] * y[i];
    }

    *a0 = (A_02 * A_11 - A_01 * A_12) / (A_00 * A_11 - A_01 * A_01);
    *a1 = (A_00 * A_12 - A_01 * A_02) / (A_00 * A_11 - A_01 * A_01);

}

int main(){
    int x[] = {5, 10, 15, 20, 25};
    int y[] = {1400, 1700, 2100, 2400, 2800};
    int a0 = 0, a1 =0;

    int N = sizeof(x) / sizeof(x[0]);

    lsm(x, y, N, &a0, &a1);
    printf("y = a1 * x + a0\na0 = %d, a1 = %d\n", a0, a1);
    int a = a1 * 8 + a0;
    int b = a1 * 13 + a0;
    int c = a1 * 30 + a0;

    printf("x = 8 -> %d\n x = 13 -> %d\n, x = 30 -> %d\n", a, b, c);
}