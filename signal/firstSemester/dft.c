#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define N 3/*課題の結果をチェックするためにはこちらは３か4を設定してください*.Sine波の場合は色々変えてみてください*/
#define PI 3.1416
 
struct Values{
 double Re, Im; 
};

int main(){
    int n, k;             
    double x[N]={5,2,-2};
    double Real[N]={};
    double Ima[N]={};
    struct Values X[N];
    double frequency1=4;/*1つ目のSine波の周波数*/
    double frequency2=20;/*2つ目のSine波の周波数*/
    int A1=1000;/*1つ目のSine波の振幅*/
    int A2=5;/*2つ目ののSine波の振幅*/
    double Magnitude[N];/*フーリエ変換変換後の信号の振幅*/

 /*ふたつのSin波の和*/
 // for(n=0;n<N;n++){
 //       double t = (double) n/N;
 //       x[n] = A1*sin(frequency1*t*2*M_PI)+A2*sin(frequency2*t*2*M_PI);
 //   }

    printf("value:\n");
    for (k = 0; k < N; k++){
        printf ("X[%d]=%f\n",k, x[k]);
       // printf ("Magnitude[%d]=%.3f\n",k,Magnitude[k]);
    }
    //DFT
    for (k = 0; k < N; k++){
        X[k].Re = 0;
        for (n = 0; n < N; n++)
         X[k].Re += x[n] * cos(n * k * 2*PI / N);/*式の通り行列を作ってx(n)と掛け算-----実部*/
         X[k].Im = 0;
        for (n = 0; n < N; n++)
        X[k].Im -= x[n] * sin(n * k * 2*PI / N);   /*式の通り行列を作ってx(n)と掛け算-----虚部*/
        Magnitude[k]= X[k].Re*X[k].Re+X[k].Im*X[k].Im;
    }

     printf("DFT:\n");
    for (k = 0; k < N; k++){
     /*行列の掛け算でデータ結果を表示*/
        if (X[k].Im<0)
            printf ("X[%d]=%.3f%.3fj\n",k,X[k].Re,X[k].Im);
        else
            printf ("X[%d]=%.3f+%.3fj\n",k,X[k].Re,X[k].Im);
    }
    //IDFTしてみよう
    for (k = 0; k < N; k++){
        for (n = 0; n < N; n++){
            Real[k] += X[n].Re * cos(n * k * 2*PI / N) - X[n].Im * sin(n * k * 2*PI / N);
            Ima[k] += X[n].Re * sin(n * k * 2*PI / N) + X[n].Im * cos(n * k * 2*PI / N);
        }
        Real[k] /= N;
        Ima[k] /= N;
    }
    printf("IDFT:\n");
    for (k = 0; k < N; k++){
        printf ("X[%d]=%.3f+%.3fj\n",k,Real[k], Ima[k]);
       // printf ("Magnitude[%d]=%.3f\n",k,Magnitude[k]);
    }
}