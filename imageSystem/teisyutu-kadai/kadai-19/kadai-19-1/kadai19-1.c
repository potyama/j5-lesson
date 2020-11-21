#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "def.h"
#include "var.h"

#include "bmpfile.h"

void setUp(imgdata *idata){
    for(int y = 0; y < idata->height; y++){
        for(int x = 0; x < idata->width; x++){
            idata->cwork[RED][y][x] = idata->source[RED][y][x];
            idata->cwork[GREEN][y][x] = idata->source[RED][y][x];
            idata->cwork[BLUE][y][x] = idata->source[RED][y][x];
        }
    }
}

void swapArr(imgdata *idata){
    for(int y = 0; y < idata->height; y++){
        for(int x = 0; x < idata->width; x++){
            idata->source[RED][y][x] = idata->cwork[RED][y][x];
            idata->source[GREEN][y][x] = idata->cwork[RED][y][x];
            idata->source[BLUE][y][x] = idata->cwork[RED][y][x];
        }
    }
}

//膨張
void dilation(imgdata *idata){
    for(int y = 0; y < idata->height; y++){
        for(int x = 0; x < idata->width; x++){
            if(idata->source[RED][y][x] == BLACKVALUE){
                idata->cwork[RED][y][x-1] = BLACKVALUE;
                idata->cwork[RED][y-1][x] = BLACKVALUE;
                idata->cwork[RED][y+1][x] = BLACKVALUE;
                idata->cwork[RED][y][x+1] = BLACKVALUE;
            }
        }
    }
}
//収縮
void erosion(imgdata *idata){
    for(int y = 0; y < idata->height; y++){
        for(int x = 0; x < idata->width; x++){
            if(idata->source[RED][y][x] == WHITEVALUE){
                idata->cwork[RED][y][x-1] = WHITEVALUE;
                idata->cwork[RED][y-1][x] = WHITEVALUE;
                idata->cwork[RED][y+1][x] = WHITEVALUE;
                idata->cwork[RED][y][x+1] = WHITEVALUE;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    imgdata idata;
    double c;
    int i,x, y;

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
            /* 課題19-1 : 2値画像を4近傍で膨張->収縮->収縮->膨張するプログラム */

            setUp(&idata);

            dilation(&idata);
            swapArr(&idata);

            erosion(&idata);
            swapArr(&idata);

            erosion(&idata);
            swapArr(&idata);

            dilation(&idata);

            for(int y = 0; y < idata.height; y++){
                for(int x = 0; x < idata.width; x++){
                    idata.results[RED][y][x] = idata.cwork[RED][y][x];
                    idata.results[GREEN][y][x] = idata.cwork[RED][y][x];
                    idata.results[BLUE][y][x] = idata.cwork[RED][y][x];
                }
            }
            if (writeBMPfile(argv[2], &idata) > 0)
            printf("コピー先ファイル%sに保存できませんでした\n",argv[2]);
        }
    }
}