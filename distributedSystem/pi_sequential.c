﻿#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>
#include	<math.h>

#define	F(x)	(4.0L / (1.0L + x * x))

long double pi(int n_intervals, int n_threads);

int main(int argc, char **argv)
{
  int n_intervals;
  int n_threads;
  long double p;
  double ts,te;

  if (argc != 3){
    fprintf(stderr,"使い方:%s スレッド数 区間数\n", argv[0]);
    exit(1);
  }
  n_threads = atoi(argv[1]);
  n_intervals = atoi(argv[2]);
  omp_set_num_threads(n_threads);
  ts = omp_get_wtime();
  p = pi(n_intervals,n_threads);
  te = omp_get_wtime();
  printf("PI = 3.141592653589793238462643383279（正しい値）\n");
  printf("pi = %.30Lf\n",p);
  printf("%f\n",te - ts);
}

long double pi(int n_intervals, int n_threads)
{
  int i;
  long double sum,step,x;


  step = 1.0L / n_intervals;
  sum = 0.0L;

  #pragma omp_parallel for reduction(+:sum) private(x)
  for (i = 0;i < n_intervals;i++){
    x = (i + 0.5L) * step;
    sum += F(x);
  }
  return (sum / n_intervals);
}