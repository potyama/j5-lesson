#include <stdio.h>
#include "MT.h"

#define NUM 100

int main(void){
    int i;
    int seed;

    seed = 0;
    init_genrand(seed);

    int cnt = 0;
    for (i=0;i<NUM;i++) {
        double x = genrand_real1();
        double y = genrand_real1();
        if(x*x + y*y <= 1)cnt++;
    }
    double pi = (double)cnt / NUM * 4;
    printf("%f\n", pi);

}
