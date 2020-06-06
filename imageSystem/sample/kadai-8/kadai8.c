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
    int x,y;

    double LUT[270],hist[270];
    double ave = (idata.height*idata.width)/255;
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

    if (argc < 3) printf("使用法：kadai1 コピー元.bmp コピー先.bmp\n");
    else {
        if (readBMPfile(argv[1], &idata) > 0)
            printf("指定コピー元ファイル%sが見つかりません\n",argv[1]);
        else {
        /* 課題8 : 入力画像をシグモイド変換するプログラム */
        for(int i = 0;i < 255 ;i++){
            hist[i] = 0;
        }
        for (y = 0; y < idata.height; y++){
            for (x = 0; x < idata.width; x++){
                hist[idata.source[RED][y][x]]++;
                nm[idata.source[RED][y][x]][idata.source[RED][y][x]]++;
            }
        }

        for(int i=0;i<255;i++){
			if(nm[i][i] < ave){
				for(int j=0;nm[i][i] != ave;j++){
					int tmp=0;
                    if(ave - nm[i][i] > nm[i+j][i+j]){
					    tmp = nm[i+j][i+j];
				    }else{
					    tmp = ave - nm[i][i];
			    	}
				    nm[i+j][i+j] -= tmp;
				    nm[i+j][i] = tmp;
				    nm[i][i] += tmp;
			    }
			}else if(nm[i][i] > ave){
				int over =  nm[i][i] - ave;
				nm[i+1][i+1] += over;
				nm[i][i] = ave;
				nm[i][i+1] = over;
			}
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