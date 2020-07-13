#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef DEF_H

#include "def.h"
#define DEF_H

#endif
#include "var.h"
#include "bmpfile.h"

int main(int argc, char *argv[]) {
    imgdata idata;
    double n = 5;
    double N = 3;

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
            for(int y = 0; y < idata.height; y++){
                for(int x = 0; x < idata.width; x++){
                    int check = 0;
                    double sum_data = 0;

                    for(int j = 0;j < N; j++){
                        for(int i = 0; i < N; i++){
                            int x_coordinate = i - (N-1)/2;
                            int y_coordinate = j - (N-1)/2;
                            if(y + y_coordinate < 0
                            || y + y_coordinate >= idata.height
                            || x + x_coordinate < 0
                            || x + x_coordinate >= idata.width){
                                check++;
                                continue;
                            }
                            if(x_coordinate == 0 && y_coordinate == 0){
                                sum_data += idata.source[RED][y + y_coordinate][x + x_coordinate] * n;
                            }else{
                                sum_data += idata.source[RED][y + y_coordinate][x + x_coordinate];
                            }
                        }
                    }
                    int tmp_N = (N*N - check)-1.0;
                    double result = sum_data / (tmp_N + n);
                    idata.results[RED][y][x] = result;
                    idata.results[GREEN][y][x] = result;
                    idata.results[BLUE][y][x] = result;
                }
            }
        }
        if (writeBMPfile(argv[2], &idata) > 0)
            printf("コピー先ファイル%sに保存できませんでした\n",argv[2]);
        }
}