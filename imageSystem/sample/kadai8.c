#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "def.h"
#include "var.h"

#include "bmpfile.h"

int main(int argc, char *argv[])
{
	imgdata idata;
	//double c;
	int x,y;

	int histogram[256] = {};
	int average = 0;
	int nm[256][256] = {};

	// 例題プログラム
	// 　BMPファイルをコピーするプログラム
	//
	//	 readBMPfile関数でidata.sourceに画像データが読み込まれる
	//	 writeBMPfile関数でidata.resultsの画像データが書きだされる
	//	 これらの関数は、bmpfile.o に入っています
	//	 3次元配列のインデックスは、[RGBの種類][y座標][x座標]
	//	 BMP形式では、画像の左下が座標の原点
	//	 その他、var.h と def.h を見て下さい

	if (argc < 3) printf("使用法：cpbmp コピー元.bmp コピー先.bmp\n");
	else {
		if (readBMPfile(argv[1], &idata) > 0)
			printf("指定コピー元ファイル%sが見つかりません\n",argv[1]);
		else {
			for (y = 0; y < idata.height; y++){
				for (x = 0; x < idata.width; x++){
					histogram[idata.source[RED][y][x]]++;
					nm[idata.source[RED][y][x]][idata.source[RED][y][x]]++;
				}
			}
			average = (idata.height*idata.width)/256;
			for(int i=0;i<256;i+=4){
				printf("\n");
				for(int j=0;j<(histogram[i]+histogram[i+1])/8;j++) printf("#");
			}
			printf("-----------------------------\n");

			for(int i=0;i<256;i++){
				if(histogram[i] < average){
					printf("average: %d\n", average);
					printf("histogram[%d]: %d\n", i, histogram[i]);
					printf("husoku: %d\n", average - histogram[i]);
					for(int j=1;histogram[i] < average && i+j < 256;j++){
						int amount=0;

						// copy from higher item
						if(average - histogram[i] > histogram[i+j]){
							amount = histogram[i+j];
						}else{
							amount = average - histogram[i];
						}
						histogram[i+j] -= amount; // delete from higher item
						nm[i+j][i] = amount; // write log
						histogram[i] += amount; // append value from higher item
						printf("(%d,%d,%d) ",i+j, amount, average - histogram[i]);
					}
				} else if(histogram[i] > average) {
					int overflow =  histogram[i] - average; // calculate overflow
					histogram[i+1] += overflow; // send overflow
					histogram[i] -= overflow; // cut overflow
					nm[i][i+1] = overflow;
					printf("\noverflow %d\n", overflow);
				}
				for(int i=0;i<256;i+=4){
					for(int j=0;j<(histogram[i]+histogram[i+1])/8;j++) printf("#");
					printf("\n");
				}
				printf("\n-----------------------------");
			}


			printf("\n");
			for(int i=0;i<256;i+=2){
				printf("%d ", i);
				for(int j=0;j<(histogram[i]+histogram[i+1])/8;j++) printf("#");
				printf("\n");
			}

			int cnt[256][256] = {};

			for (y = 0; y < idata.height; y++){
				for (x = 0; x < idata.width; x++){
						idata.results[RED][y][x] = idata.source[RED][y][x];
						idata.results[GREEN][y][x] = idata.source[GREEN][y][x];
						idata.results[BLUE][y][x] = idata.source[BLUE][y][x];
				}
			}

			for(int y=0; y < idata.height; y++){
				for(int x=0; x < idata.width; x++){
					int g = idata.source[RED][y][x];
					int k = 0;
					for(; k<256; k++){
						if(g==k) continue;
						if(nm[g][k] != 0 && cnt[g][k] < nm[g][k]) break;
					}
					if(k != 256){
						idata.results[RED][y][x] = k;
						idata.results[GREEN][y][x] = k;
						idata.results[BLUE][y][x] = k;
						cnt[g][k]++;
					}else{
						printf("k not found %d",k);
						printf("(%d,%d)\n",x,y);
					}
				}
			}

			int histogram2[256] = {};

			for (y = 0; y < idata.height; y++){
				for (x = 0; x < idata.width; x++){
					histogram2[idata.results[RED][y][x]]++;
				}
			}
			for(int i=0;i<256;i++){
				printf("%d ",histogram2[i]);
			}
			printf("width %d height %d depth %d color %d", idata.width, idata.height, idata.color_depth,idata.used_color);

			if (writeBMPfile(argv[2], &idata) > 0)
				printf("コピー先ファイル%sに保存できませんでした\n",argv[2]);

		}
	}
}
