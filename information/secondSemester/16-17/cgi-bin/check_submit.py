#!/usr/bin/python
# -*- coding: utf-8 -*-

html = '''Content-Type: text/html

<html>
    <head>
        <meta charset='utf-8'>
        <title>どのボタンが押されたか取得する</title>
    </head>
    <body>
        <h1>どのボタンが押されたか調べる</h1>
        <p>押されたボタンは"%s"です。</p>
        <form action="check_submit.py" method="post">
            <input type="submit" name="btn1" value="[1]" />
            <input type="submit" name="btn2" value="[2]" />
            <input type="submit" name="btn3" value="[3]" />
        </form>
    </body>
</html>
'''

import cgi
f = cgi.FieldStorage()


if f.getfirst('btn1'):
    btn = '1のボタンですよ'
elif f.getfirst('btn2'):
    btn = '2のボタンですよ'
elif f.getfirst('btn3'):
    btn = '3のボタンですよ'
else:
    btn = ' '
print(html%btn)