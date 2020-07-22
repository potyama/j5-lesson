#include <stdio.h>
#include <omp.h>

int main(){
    omp_set_num_threads(3);
    #pragma omp parallel num_threads(4)
    {
        printf("hi, id = %d\n", omp_get_thread_num());
    }
}