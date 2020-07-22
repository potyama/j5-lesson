#include <stdio.h>
#include <omp.h>

int main(){
    int a[1010],b[1010];
    #pragma omp parallel for
    for (int i = 0;i < 1000;i++){
        a[i] = i;
        b[i] = a[i] * a[i];
        printf("b[%d]=%d\n", i,b[i]);
    }
}