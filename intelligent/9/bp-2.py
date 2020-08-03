# ニューラルネットワークのBP法による学習
# 練習用のため拡張性ゼロのアホアホプログラミング

import numpy as np
import matplotlib.pyplot as plt
# 乱数の種を設定
np.random.seed(3)

# パラメータ
EPSILON = 4.0 # シグモイド関数の傾き
ETA = 0.1     # 学習係数
TIME = 1000   # 学習回数

# シグモイド関数
def sigmoid(x):
    return 1/(1+np.exp(-1*EPSILON*x))

# 入力（XORの入力部分）
dataX = np.array(
    [[0,0],
     [0,1],
     [1,0],
     [1,1]]
)

# 教師信号（XORの出力部分）
dataY = np.array(
    [[0],
     [1],
     [1],
     [0]]
)

# 初期重みと初期閾値をランダムに与える
wab = (np.random.rand()-0.5)*2 * 0.3 # -0.3から0.3の一様乱数
wac = (np.random.rand()-0.5)*2 * 0.3
wbd = (np.random.rand()-0.5)*2 * 0.3
wbe = (np.random.rand()-0.5)*2 * 0.3
wcd = (np.random.rand()-0.5)*2 * 0.3
wce = (np.random.rand()-0.5)*2 * 0.3
tha = (np.random.rand()-0.5)*2 * 0.3
thb = (np.random.rand()-0.5)*2 * 0.3
thc = (np.random.rand()-0.5)*2 * 0.3

# 重みを表示
print("学習前の重み")
print('wab=', wab)
print('wac=', wac)
print('wbd=', wbd)
print('wbe=', wbe)
print('wcd=', wcd)
print('wce=', wce)
print('tha=', tha)
print('thb=', thb)
print('thc=', thc)
print()

# 誤差曲線のグラフ表示用
x = []
y = []

sum_deltaa = 0.0
sum_deltab = 0.0
sum_deltac = 0.0
sum_wab = 0.0
sum_wac = 0.0
sum_wbd = 0.0
sum_wbe = 0.0
sum_wcd = 0.0
sum_wce = 0.0
# 学習
for t in range(TIME):

    outall = []
    errorAll = 0.0
    for p in range(len(dataX)):
        #############
        # 前向き計算
        #############

        # 入力層
        outd = dataX[p][0]
        oute = dataX[p][1]

        # 中間層
        xb = wbd * outd + wbe * oute + thb
        outb = sigmoid(xb)

        xc = wcd * outd + wce * oute + thc
        outc = sigmoid(xc)

        # 出力層
        xa = wab * outb + wac * outc + tha
        outa = sigmoid(xa)

        # 誤差計算
        outall.append(outa)
        error = (outa-dataY[p])**2
        errorAll += error

        ##################
        # Back Propagation
        ##################

        # ここに更新式を書く

        #中間層-出力層
        deltaa = (outa - tha) * EPSILON * (1 - outa) * outa
        deltab = (outb - thb) * EPSILON * (1 - outb) * outb
        deltac = (outc - thc) * EPSILON * (1 - outc) * outc

        sum_deltaa += deltaa
        sum_deltab += deltab
        sum_deltac += deltac
        sum_wab += deltaa * outa
        sum_wac += deltaa * outa
        sum_wbd += deltab * outb
        sum_wbe += -deltab * outb
        sum_wcd += -deltac * outc
        sum_wce += -deltac * outc

    wab -= ETA * sum_wab
    wac -= ETA * sum_wac
    wbd -= ETA * sum_wbd
    wbe -= ETA * sum_wbe
    wcd -= ETA * sum_wcd
    wce -= ETA * sum_wce

    tha -= ETA * sum_deltaa
    thb -= ETA * sum_deltab
    thc -= ETA * sum_deltac
    # 誤差曲線のグラフ表示用の変数

    x.append(t)
    y.append(errorAll)

# 学習後の出力
print("学習後の出力")
print(outall[0])
print(outall[1])
print(outall[2])
print(outall[3])
print()

# 重みを表示
print()
print("学習後の重み")
print('wab=', wab)
print('wac=', wac)
print('wbd=', wbd)
print('wbe=', wbe)
print('wcd=', wcd)
print('wce=', wce)
print('tha=', tha)
print('thb=', thb)
print('thc=', thc)
print()
