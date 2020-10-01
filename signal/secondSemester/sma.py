import pandas as pd
import matplotlib.pyplot as plt


data = pd.DataFrame(pd.read_csv('closing_price.csv', encoding="utf-8", usecols=[4]))

print(data.rolling(5).mean())

plt.plot(data, label="data")
plt.plot(data.rolling(5).mean(), label="SMA(5)")
plt.xlabel("終値", fontname="MS Gothic")
plt.ylabel("株価", fontname="MS Gothic")
plt.show()