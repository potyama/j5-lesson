#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define iMAX 256

#ifndef DEF_H

#include "def.h"
#define DEF_H

#endif
#include "var.h"

#include "bmpfile.h"

int main(int argc, char *argv[]) {
  imgdata idata;
  double c;
  int x, y;

  // 例題プログラム
  // 　BMPファイルをコピーするプログラム
  //
  //   readBMPfile関数でidata.sourceに画像データが読み込まれる
  //   writeBMPfile関数でidata.resultsの画像データが書きだされる
  //   これらの関数は、bmpfile.o に入っています
  //   3次元配列のインデックスは、[RGBの種類][y座標][x座標]
  //   BMP形式では、画像の左下が座標の原点
  //   その他、var.h と def.h を見て下さい

  if (argc < 3)
    printf("使用法：kadai1 コピー元.bmp コピー先.bmp\n");
  else {
    if (readBMPfile(argv[1], &idata) > 0)
      printf("指定コピー元ファイル%sが見つかりません\n", argv[1]);
    else {
      /* 課題8 : 入力画像をシグモイド変換するプログラム */
    double  hist[270]={};
    int nm[270][270] = {};
    double ave = (idata.height * idata.width) / iMAX;

      for (y = 0; y < idata.height; y++) {
        for (x = 0; x < idata.width; x++) {
          hist[idata.source[RED][y][x]]++;
          nm[idata.source[RED][y][x]][idata.source[RED][y][x]]++;
        }
      }

      for (int i = 0; i < iMAX; i++) {
        if (hist[i] > ave) {
          int tmp = nm[0][i];
          for(int j = 0; j <= i; j++){
            if (tmp > ave) {
              nm[j][i+1] = tmp - ave;

              nm[j][i] = nm[j][i] - nm[j][i+1];
              hist[i] = hist[i] - nm[j][i+1];
              hist[i+1] = hist[i+1] + nm[j][i+1];

              if(i != j){
                for(int k = j+1; k <= i; k++){
                  nm[k][i+1] = nm[k][i];
                  hist[i+1] = hist[i+1] + nm[k][i+1];
                  hist[i] = hist[i] - nm[k][i+1];
                  nm[k][i] = 0;
                }
              }
              break;
            }else{
              tmp = tmp + nm[j+1][i];
            }
          }
        }else{
          int tmp = hist[i];
          for(int j = i+1; j < iMAX; j++){
            tmp = tmp + hist[j];
            if(tmp > ave){
              nm[j][i] = ave - hist[i];
              hist[i] = hist[i] + nm[j][i];
              nm[j][j] = nm[j][j] - nm[j][i];
              hist[j] = hist[j] - nm[j][i];
            }else{
              nm[j][i] = hist[j];
              hist[i] = hist[i] + nm[j][i];
              nm[j][j] = 0;
              hist[j] = 0;
            }
          }
        }
      }

      int cnt[270][270] = {};
      int k;
      for (int y = idata.height-1; y >= 0; y--) {
        for (int x = 0; x < idata.width; x++) {
          int g = idata.source[RED][y][x];
          for (k = 0; k < iMAX; k++) {
            if (cnt[g][k] < nm[g][k]) break;
          }
                idata.results[RED][y][x] = k;
                idata.results[GREEN][y][x] = k;
                idata.results[BLUE][y][x] = k;
                cnt[g][k]++;
        }
      }
      if (writeBMPfile(argv[2], &idata) > 0)
        printf("コピー先ファイル%sに保存できませんでした\n", argv[2]);
      }
    }
  }
