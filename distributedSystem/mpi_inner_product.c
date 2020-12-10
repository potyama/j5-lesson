/*
実行結果:
mpicc mpi_inner_product.c
mpirun a.out
80.000000
*/

#include  <stdio.h>
#include  "mpi.h"

#define SIZE	(80)

double inner_product(double *vec_a,double *vec_b,int my_rank,int np);

int main(int argc,char **argv){
    int   my_rank;
    int   np;
    int   i;
    int   sum;
    double vec_a[SIZE];
    double vec_b[SIZE];
    double r;

    MPI_Status  status;

    /* 初期化 */
    MPI_Init(&argc,&argv);

    /* my_rank: 自分のプロセス番号 */
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);

  /* np: プロセス数 */
    MPI_Comm_size(MPI_COMM_WORLD,&np);
    if (my_rank == 0){
        for (i = 0;i < SIZE;i++){
            vec_a[i] = 1.0;
            vec_b[i] = 1.0;
        }
    }
    r = inner_product(vec_a,vec_b,my_rank,np);

    if(my_rank == 0)printf("%lf\n", r);

    MPI_Finalize();
}

double inner_product(double *vec_a,double *vec_b,int my_rank,int np){
    double r_vec_a[SIZE];
    double r_vec_b[SIZE];
    double sum = 0,result = 0;
    MPI_Scatter(vec_a, SIZE/np, MPI_DOUBLE, r_vec_a, SIZE/np, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(vec_b, SIZE/np, MPI_DOUBLE, r_vec_b, SIZE/np, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    for(int i=0; i< SIZE/np; i++){
        sum += r_vec_a[i] * r_vec_b[i];
    }
    MPI_Reduce(&sum, &result, SIZE, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    return result;
}