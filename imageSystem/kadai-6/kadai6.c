#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "def.h"
#include "var.h"

#include "bmpfile.h"

int main(int argc, char *argv[])
{
    imgdata idata;
    double c;
    int i,x, y;
    double Zm =255.0;

    double LUT[270];
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

        for(i = 0;i < Zm ;i++){
            LUT[i] = Zm*sqrt(i/Zm);
        }
        for (y = 0; y < idata.height; y++){
            for (x = 0; x < idata.width; x++){
                idata.results[RED][y][x] = LUT[idata.source[RED][y][x]];
                idata.results[GREEN][y][x] = LUT[idata.source[GREEN][y][x]];
                idata.results[BLUE][y][x] = LUT[idata.source[BLUE][y][x]];
            }
        }
        if (writeBMPfile(argv[2], &idata) > 0)
            printf("コピー先ファイル%sに保存できませんでした\n",argv[2]);
        }
    }
}