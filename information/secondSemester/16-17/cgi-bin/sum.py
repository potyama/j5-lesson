#!/usr/bin/python
# -*- coding: utf-8 -*-

html = '''Content-Type: text/html

<html>
    <head>
        <meta charset='utf-8'>
        <title>足し算を行うCGIスクリプト</title>
    </head>
    <body>
        <h1>足し算を行うCGIスクリプト</h1>
        <form action="sum.py" method="post">
            <input type="text" name="num1" size="3" value="%s" />
            +
            <input type="text" name="num2" size="3" value="%s" />
            = %d
        <input type="submit" />
        </form>
    </body>
</html>
'''

import cgi
f = cgi.FieldStorage()

num1 = f.getfirst("num1", "0")
num2 = f.getfirst("num2", "0")
try:
    result = int(num1) + int(num2)
except:
    result = 0
print(html % (num1, num2, result))