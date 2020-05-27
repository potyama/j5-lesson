#include <stdio.h>

#define FALSE 0
#define TRUE 1

int main(){
  int number = 1;
  int done = FALSE;

  while(number <= 10){
    printf("next integer:%d\n", number);
    number += 1;
  }
  while(!done){
    printf("next integer:%d\n", number);
    number += 1;
    if(number == 21){
      done = TRUE;
    }
  }
}
