/*

モンテカルロ法によって円周率を計算するプログラム

OpenMP 版の mcpi_random.c を MPI 用に書き換えた．
各プロセスは独立しているので，random の同時実行の問題は考えなくてよい．

*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 10000000

int mcpi(int seed);

int
main(int argc,char **argv)
{
  int	my_rank;
  int	np;
  MPI_Status	status;

  int	count,i,count_total;
  
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
  MPI_Comm_size(MPI_COMM_WORLD,&np);
  
  if (my_rank != 0){
    /* プロセス 0 以外はランダムシミュレーションを行い，結果を返す */
    count = mcpi(my_rank);
    MPI_Send(&count,1,MPI_INT,0,1,MPI_COMM_WORLD);
  }else{
    /* プロセス 0 は自分でもランダムシミュレーションを行うい，*/
    /* その後ほかのプロセスの結果をまとめる                   */
    count_total = mcpi(my_rank);
    for (i = 1;i < np;i++){
      MPI_Recv(&count,1,MPI_INT,MPI_ANY_SOURCE,1,MPI_COMM_WORLD,&status);
      count_total += count;
      printf("proc %d:count=%8d\n",status.MPI_SOURCE,count);
    }
    /* シミュレーションの総回数は N * np である */
    printf("pi=%f\n", count_total * 4.0 / (N * np));
  }
  MPI_Finalize();
}

/* 核になるループは，元の mcpi_random.c とほとんど変わっていない */
int mcpi(int seed)
{
  int i,c;
  double x,y;
  
  srandom(seed);

  for (i = 0;i < N;i++){
    x = ((double)random()) / (RAND_MAX);
    y = ((double)random()) / (RAND_MAX);
    if (x * x + y * y < 1.0){
      c++;
    }
  }
  return c;
}
