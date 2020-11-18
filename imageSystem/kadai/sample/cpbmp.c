#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "var.h"

#include "bmpfile.h"

int main(int argc, char *argv[])
{
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
  
  if (argc < 3) printf("使用法：cpbmp コピー元.bmp コピー先.bmp\n");
  else {
    if (readBMPfile(argv[1], &idata) > 0)
      printf("指定コピー元ファイル%sが見つかりません\n",argv[1]);
    else {
      /* 例題：コピーするプログラム */
      for (y = 0; y < idata.height; y++){
	for (x = 0; x < idata.width; x++){
	  idata.results[RED][y][x]
	    = idata.source[RED][y][x];
	  idata.results[GREEN][y][x]
	    = idata.source[GREEN][y][x];
	  idata.results[BLUE][y][x]
	    = idata.source[BLUE][y][x];
	}
      }
      if (writeBMPfile(argv[2], &idata) > 0)
	printf("コピー先ファイル%sに保存できませんでした\n",argv[2]);
    }
  }
}
