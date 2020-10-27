#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 最小の転送サイズ（byte） */
#define MIN_XFR_SIZE (1LL << 8)

/* 最大の転送サイズ（byte） */
#define MAX_XFR_SIZE (1LL << 28)

/* トータルで転送するバイト数                             */
/* 転送サイズによらず，トータルの転送バイト数は同じにする */
#define TOTAL_XFR (1LL<<38)

/* キャッシュラインサイズ */
#define CACHE_LINE_SIZE  (64)

/* 転送元，転送先の配列 */
char __attribute__ ((aligned(64))) a[MAX_XFR_SIZE];
char __attribute__ ((aligned(64))) b[MAX_XFR_SIZE];


/* a[] から b[] へ size バイトの転送を count 回繰り返す */
double copy(char *a,char *b,long long int size,long long int count);

int main(int argc,char **argv)
{
  long long int size;
  double t;
  
  printf("size(KB)\ttime(s)\trate(GB/s)\n");
  for (size = MIN_XFR_SIZE;size <= MAX_XFR_SIZE;size <<= 1){
    t = copy(a,b,size,TOTAL_XFR / size);
    printf("%10.2f\t%4.2f\t%6.2f\n",(double)size / (1 << 10),t,(TOTAL_XFR / t) / (1 << 30));
  }
}

double copy(char *a,char  *b,long long int size,long long int count)
{
  long long int i, j;
  struct timespec ts,te;

  clock_gettime(CLOCK_REALTIME, &ts);
  for (i = 0;i < count;i++){
    /* キャッシュラインにつき 1 バイトだけコピーする            */
    /* その方がメモリ部分の性能をダイレクトに観測できると思った */
    /* んだが...                                                */
    /* size が大きいとき，なぜか j++ で全バイトをコピーした方が */
    /* 実行時間が短くなる謎                                     */
    for  (j = 0;j < size;j += CACHE_LINE_SIZE){
      b[j] = a[j];
    }
    /* 手動でコピーするかわりに memcpy を使ったら，転送が速く   */
    /* なるんじゃないかと思ったんだが...                        */
    //memcpy(b,a,size);
  }
  clock_gettime(CLOCK_REALTIME, &te);
  return ((double)(te.tv_sec - ts.tv_sec) + (double)(te.tv_nsec - ts.tv_nsec) / (1000 * 1000 * 1000));
}
