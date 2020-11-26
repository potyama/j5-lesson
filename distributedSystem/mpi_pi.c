#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include <math.h>

#define	F(x)	(4.0 / (1.0 + x * x))

double pi(int n_intervals, int np, int my_rank){
  int i;
  double sum,step,x;

  step = 1.0 / n_intervals;
  sum = 0.0;
  int start = (my_rank+1) * (n_intervals/np);
  int end = (my_rank+1) * (n_intervals/np);

  for (i = start; i < end;i++){
    x = (i + 0.5) * step;
    sum += F(x);
  }
  return (sum);
}

int main(int argc, char **argv)
{
  int n_intervals;
  int np;
  int my_rank;
  MPI_Status status;
  double p, p_total;

  if (argc != 2){
    fprintf(stderr,"使い方:%s スレッド数 区間数\n", argv[0]);
    exit(1);
  }

  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
  MPI_Comm_size(MPI_COMM_WORLD,&np);

  n_intervals = atoi(argv[1]);
  if(my_rank != 0){
    p = pi(n_intervals, np, my_rank);
    MPI_Send(&p, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD);
  }else{
    p = pi(n_intervals, np, my_rank);
    for (int i = 1;i < np;i++){
      p_total += p;
      MPI_Recv(&p, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, &status);
    }
  }
  printf("pi = %.30f\n",p/n_intervals);
  MPI_Finalize();

}
