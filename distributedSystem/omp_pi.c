#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>
#include	<math.h>

#define	F(x)	(4.0L / (1.0L + x * x))

double pi(int n_intervals, int n_threads);

int main(int argc, char **argv)
{
  int n_intervals;
  int n_threads;
  double p;
  double ts,te;

  if (argc != 3){
    fprintf(stderr,"使い方:%s スレッド数 区間数\n", argv[0]);
    exit(1);
  }
  n_threads = atoi(argv[1]);
  n_intervals = atoi(argv[2]);
  ts = omp_get_wtime();
  p = pi(n_intervals,n_threads);
  te = omp_get_wtime();
  printf("pi = %.30f\n",p);
  printf("%f\n",te - ts);
}

double pi(int n_intervals, int n_threads)
{
  int i;
  double sum,step,x;

  omp_set_num_threads(n_threads);
  step = 1.0L / n_intervals;
  sum = 0.0L;
  #pragma omp parallel for reduction(+:sum) private(x)
  for (i = 0;i < n_intervals;i++){
    x = (i + 0.5L) * step;
    sum += F(x);
  }
  return (sum / n_intervals);
}
