#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "def.h"
#include "var.h"

#include "bmpfile.h"

int main(int argc, char *argv[])
{
    imgdata idata;
    char h[9] = {
        -1, 0, 1,
        -2, 0, 2,
        -1, 0, 1
    };

    char w[9] = {
        -1, -2, -1,
        0, 0, 0,
        1, 2, 1,
    };

    int hist[256] = {};
  // 例題プログラム
  // 　BMPファイルをコピーするプログラム
  //
  //   readBMPfile関数でidata.sourceに画像データが読み込まれる
  //   writeBMPfile関数でidata.resultsの画像データが書きだされる
  //   これらの関数は、bmpfile.o に入っています
  //   3次元配列のインデックスは、[RGBの種類][y座標][x座標]
  //   BMP形式では、画像の左下が座標の原点
  //   その他、var.h と def.h を見て下さい

    if (argc < 3) printf("使用法：kadai1 コピー元.bmp コピー先.bmp\n");
    else {
        if (readBMPfile(argv[1], &idata) > 0)
            printf("指定コピー元ファイル%sが見つかりません\n",argv[1]);
        else {
            /* 課題6 : 入力画像を根変換するプログラム */
            for (int y = 1; y < idata.height-1; y++){
                for (int x = 1; x < idata.width-1; x++){
                    double sum=0, sum_W=0, sum_H = 0;
                    for(int i=0; i < 3; i++){
                        for(int j=0; j < 3; j++){
                            sum_H += h[i*3+j] * idata.source[RED][y-1+i][x-1+j];
                            sum_W += w[i*3+j] * idata.source[RED][y-1+i][x-1+j];
                        }
                    }
                    sum = sqrt(pow(sum_H, 2) + pow(sum_W, 2));
                    if(sum > 30){
                        hist[idata.source[RED][y][x]] += sum;
                    }
                }
            }
            int t, h_max = 0;
            for(int i = 0; i < 256; i++){
                if(h_max < hist[i]){
                    t = i;
                    h_max = hist[i];
                }
            }

            for (int y = 0; y < idata.height; y++){
                for (int x = 0; x < idata.width; x++){
                    if(idata.source[RED][y][x] >= t){
                        idata.results[RED][y][x] = 255;
                        idata.results[GREEN][y][x] = 255;
                        idata.results[BLUE][y][x] = 255;

                    }else{
                        idata.results[RED][y][x] = 0;
                        idata.results[GREEN][y][x] = 0;
                        idata.results[BLUE][y][x] = 0;
                    }
                }
            }
            if (writeBMPfile(argv[2], &idata) > 0)
                printf("コピー先ファイル%sに保存できませんでした\n",argv[2]);
        }
    }
}