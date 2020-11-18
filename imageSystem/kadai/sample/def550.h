// def.h の最大要素数を550にしたもの
//   実行する前に ulimit -s unlimited を実行しておくこと

/* 画像データのタイプ */
#define Uchar unsigned char

/* 画像の最大幅と高さ */
#define MAXWIDTH  550
#define MAXHEIGHT 550

/* 最大色平面の数 */
#define COLORNUM 3

/* 処理平面の指定用 */
#define RED 0
#define GREEN 1
#define BLUE 2

/* 定数π */
#define PI 3.1415926

/* ファイルネームの長さ */
#define FNAMELEN 256

/* 白と黒の値 */
#define WHITEVALUE 255
#define BLACKVALUE 0
#define MIDDLEVALUE 128
