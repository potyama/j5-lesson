#include <stdio.h>
#include "mpi.h"

int main(int argc,char **argv)
{
  int my_rank;	// 自分のランク（プロセスの番号みたいなもの）
  int np;	// プロセス数

  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
  MPI_Comm_size(MPI_COMM_WORLD,&np);
  printf("my rank is %d/%d\n",my_rank,np);
  MPI_Finalize();
}
