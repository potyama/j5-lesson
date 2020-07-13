#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef DEF_H

#include "def.h"
#define DEF_H

#endif
#include "var.h"
#include "bmpfile.h"

int bsort(unsigned char c[], int cnt){
    for(int j = 0;j < cnt-1; j++){
        for (int i = 0; i < cnt-1; i++) {
            if (c[i+1] < c[i]) {
                int tmp = c[i+1];
                c[i+1] = c[i];
                c[i] = tmp;
            }
        }
    }
    if(cnt% 2 == 0)
        return (c[(cnt/2)-1] + c[cnt/2])/2;

    return c[4];
}

double median_filter(imgdata idata, int x, int y, int h_start, int h_stop, int w_start,int w_stop){
    int cnt = 0;
    unsigned char data[12] = {};
    for(int i = h_start; i <= h_stop; i++){
        for(int j = w_start; j <= w_stop; j++){
            data[cnt] = idata.source[RED][y+i][x+j];
            cnt++;
        }
    }

    return bsort(data,cnt);
}

int main(int argc, char *argv[]) {
    imgdata idata;

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
        /* 課題9 : 入力画像を平均値フィルタ処理するプログラム */
        for (int y = 0; y < idata.height; y++){
            for (int x = 0; x < idata.width; x++){
                double sum_data = 0;
                if(x == 0){
                    if(y == 0){
                        sum_data = median_filter(idata, x, y, 0, 1, 0, 1);
                    }else if(y == 255){
                        sum_data = median_filter(idata, x, y, -1, 0, 0, 1);
                    }else{
                        sum_data = median_filter(idata, x, y, -1, 1, 0, 1);
                    }
                }else if(x == 255){
                    if(y == 0){
                        sum_data = median_filter(idata, x, y, 0, 1, -1, 0);
                    }else if(y == 255){
                        sum_data = median_filter(idata, x, y, -1, 0, -1, 0);
                    }else{
                        sum_data = median_filter(idata, x, y, -1, 1, -1, 0);
                    }
                }else if(y == 0){
                    sum_data = median_filter(idata, x, y, 0, 1, -1, 1);
                }else if(y == 255){
                    sum_data = median_filter(idata, x, y, -1, 0, -1, 1);
                }else{
                    //関数に渡すよりも、ここで直接処理したほうが早い(自社調べ)
                    int cnt = 0;
                    unsigned char data[12] = {};
                    for(int i = (-1); i <= 1; i++){
                        for(int j = (-1); j <= 1; j++){
                            data[cnt] = idata.source[RED][y+i][x+j];
                            cnt++;
                        }
                    }
                    sum_data = bsort(data, cnt);
                }

                idata.results[RED][y][x] = sum_data;
                idata.results[GREEN][y][x] = sum_data;
                idata.results[BLUE][y][x] = sum_data;
            }
        }

        if (writeBMPfile(argv[2], &idata) > 0)
            printf("コピー先ファイル%sに保存できませんでした\n",argv[2]);
        }
    }
}