#!/usr/bin/python
# -*- coding: utf-8 -*-

html2 = '''Content-Type: text/html

<html>
    <head>
        <meta charset='utf-8'>
        <title>テキスト入力フィールドに入力された文字を取得する</title>
    </head>
    <body>
        <h1>テキスト入力フィールドに入力された文字を取得する</h1>
        <p>入力された文字は、"%s"です。</p>
        <form action="check_txt.py" method="post">
            <input type="text" name="text" />
            <input type="submit" />
        </form>
    </body>
</html>
'''

import cgi
import html
f = cgi.FieldStorage()

txt = html.escape(f.getfirst('text', ''))
print(html2 % txt)