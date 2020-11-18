メモ的な感じで。違ったら教えて。

# Python3でcgi起動するとき。
python -m http.server --cgi [Port]

# htmlが文字化けするとき。
```<meta>```にcharset="utf-8"を追加する。
```<meta charset="utf-8"/>```

# time.strftime()を使ったときにUnicodeEncodeErrorがでたら

もし、自分が使っているPCなどの言語設定が日本語以外のときにエラーがでるみたい。
なので、

```
import locale
locale.setlocale(locale.LC_CTYPE, "Japanese_Japan.932")
```

で直るみたい。