#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "def.h"
#include "var.h"

#include "bmpfile.h"

int main(int argc, char *argv[])
{
    imgdata idata;
    int hist[256] = {};
    int l, r;
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
        for(int y = 0; y < idata.height; y++){
            for(int x = 0; x < idata.width; x++){
                hist[idata.source[RED][y][x]]++;
            }
        }

            int h_max=0;
            int hi_max=0;
            for(int i = 0; i <= 255; i++){
                if(hist[i] >= h_max){
                    h_max = hist[i];
                    hi_max = i;
                }
            }

            int h_max2=0;
            int hi_max2=0;
            for(int i = 0; i <= 255; i++){
                if(hist[i] > h_max2){
                    if(h_max2 < h_max && abs(hi_max-i) > 50){
                        h_max2 = hist[i];
                        hi_max2 = i;
                    }
                }
            }

            if(hi_max < hi_max2){
                l = hi_max;
                r = hi_max2;
            }else{
                l = hi_max2;
                r = hi_max;
            }

            int h_min = 255;
            int h_min2 = 0;
            for(int i = l; i <= r; i++){
                if(h_min > hist[i]){
                    h_min = hist[i];
                    h_min2 = i;
                }
            }
            for (int y = 0; y < idata.height; y++){
                for (int x = 0; x < idata.width; x++){

                    if(idata.source[RED][y][x] >= h_min2){
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