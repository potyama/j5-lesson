#include <stdio.h>
#include <math.h>

void lsm(int x[], int y[], int N, int *a0, int *a1){

    int A_00 = 0, A_01 = 0, A_02 = 0, A_11 = 0, A_12 = 0;

    for(int i = 0; i < N; i++){
        A_00 += 1.0;
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

    double mean_y;
    for(int i = 0; i < N; i++){
        mean_y += y[i];
    }
    mean_y /= N;

    double a,b;
    for(int i = 0; i < N; i++){
        a += pow((y[i] - a1 * x[i] - a0), 2);
        b += pow((y[i] - mean_y), 2);
    }

    double R = 1 - a/b;

    printf("R=%3f", R);

}