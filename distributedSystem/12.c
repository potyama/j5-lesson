#include <stdio.h>
#include <omp.h>

#define N 1000000

int main(){
    int i, l, count0=0;
    int a[N];

    for(i = 0; i < N; i++)a[i] = i % 100;

    #pragma omp parallel for reduction(+:count0)num_threads(4)
    for(i = 0;i < N;i++){
        count0 += a[i];
    }
    printf("count0_ave:%d\n", count0/N);
}