#include	"mpi.h"

int main(int argc,char **argv)
{
  /* なにはなくとも MPI_Init と MPI_Finalize */
  MPI_Init(&argc,&argv);
  MPI_Finalize();
}
