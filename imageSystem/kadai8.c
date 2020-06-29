#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "bmpfile.h"
#include "def.h"
#include "var.h"

int main(int argc, char *argv[]) {
  imgdata idata;
  double c;
  int x, y;

  double LUT[270], hist[270];
  double ave = (idata.height * idata.width) / 255;
  int nm[255][255] = {};
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
      for (int i = 0; i < 255; i++) {
        hist[i] = 0;
      }
      for (y = 0; y < idata.height; y++) {
        for (x = 0; x < idata.width; x++) {
          hist[idata.source[RED][y][x]]++;
          nm[idata.source[RED][y][x]][idata.source[RED][y][x]]++;
        }
      }

      for (int i = 0; i < 255; i++) {
        if (nm[i][i] < ave) {
          for (int j = 0; nm[i][i] != ave; j++) {
            int tmp = 0;
            if (ave - nm[i][i] > nm[i + j][i + j]) {
              tmp = nm[i + j][i + j];
            } else {
              tmp = ave - nm[i][i];
            }
            nm[i + j][i + j] -= tmp;
            nm[i + j][i] = tmp;
            nm[i][j] += tmp;
          }
        } else if (nm[i][i] > ave) {
          int a = nm[i][i] - ave;
          nm[i + 1][i + 1] += a;
          nm[i][i] = ave;
          nm[i][i + 1] = a;
        }
      }

      int cnt[255][255] = {};

        for (int y = idata.height-1; y < 255; y++) {
          for (int x = 0; x < idata.width; x++) {
          int g = idata.source[RED][y][x];
          for (int k = 0; k < 256; k++) {
            if (nm[g][k] == 0) continue;
            if (cnt[g][k] < nm[g][k]) {
              idata.results[RED][y][x] = k;
              idata.results[GREEN][y][x] = k;
              idata.results[BLUE][y][x] = k;
              cnt[g][k]++;
            }
          }
        }
      }

      if (writeBMPfile(argv[2], &idata) > 0)
        printf("コピー先ファイル%sに保存できませんでした\n", argv[2]);
    }
  }
}
