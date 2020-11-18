#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

  int cnt = 0, max = 100;

   srand(time(NULL));

  for(int i=0;i<max;i++){
    double x = (double)rand()/RAND_MAX;
    double y = (double)rand()/RAND_MAX;
    if(x*x + y*y <= 1)cnt++;
  }

  double pi = (double)cnt / max * 4;
  printf("%f\n", pi);

}
