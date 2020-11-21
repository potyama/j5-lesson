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

  // 例題プログラム
  // 　BMPファイルをコピーするプログラム
  //
  //   readBMPfile関数でidata.sourceに画像データが読み込まれる
  //   writeBMPfile関数でidata.resultsの画像データが書きだされる
  //   これらの関数は、bmpfile.o に入っています
  //   3次元配列のインデックスは、[RGBの種類][y座標][x座標]
  //   BMP形式では、画像の左下が座標の原点
  //   その他、var.h と def.h を見て下さい

    if (argc < 2) printf("使用法：kadai20-1 ランレングス表現で表すbmpファイル\n");
    else {
        if (readBMPfile(argv[1], &idata) > 0)
            printf("指定コピー元ファイル%sが見つかりません\n",argv[1]);
        else {
            int flag=0;
            int tmp_color = idata.source[RED][idata.height-1][0];
            int cnt=0;
            FILE *fp;
            if ((fp = fopen("ans20-1.txt", "w")) == NULL) {
                fprintf(stderr, "ファイルのオープンに失敗しました．\n");
                return EXIT_FAILURE;
            }
            fprintf(fp, "j16432\n");
            /* 課題6 : 入力画像を根変換するプログラム */
            for(int y = idata.height-1; y >= 0; y--){
                for(int x = 0; x < idata.width; x++){
                    if(!flag){
                        flag=1;
                    }

                    if(flag){
                        if(tmp_color != idata.source[RED][y][x]){
                            if(tmp_color == WHITEVALUE){
                                fprintf(fp, "(0,%d)", cnt);
                                tmp_color = idata.source[RED][y][x];
                                cnt=1;
                            }else{
                                fprintf(fp, "(1,%d)", cnt);
                                tmp_color = idata.source[RED][y][x];
                                cnt=1;
                            }
                            flag = 0;
                        }else{
                            cnt++;
                        }
                    }
                }
                if(tmp_color == 255){
                    fprintf(fp, "(%d,%d)", 0, cnt);
                }else{
                    fprintf(fp, "(%d,%d)", 1, cnt);
                }
                flag=0;
                cnt=0;
                fprintf(fp, "\n");
            }
            fclose(fp);
        }
    }
}