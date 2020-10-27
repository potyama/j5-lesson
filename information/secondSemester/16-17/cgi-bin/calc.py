#!/usr/bin/python
# -*- coding: utf-8 -*-

html = '''Content-Type: text/html

<html>
    <head>
        <meta charset='utf-8'>
        <title>電卓</title>
    </head>
    <body>
        <h1>電卓</h1>
        <form action="calc.py" method="post">
            <input type="text" name="num1" size="3" value="%s" />
            [sign]
            <input type="text" name="num2" size="3" value="%s" />
            = %d<br />
        <input type="submit" name="plus" value="+" />
        <input type="submit" name="minus" value="-" />
        <input type="submit" name="times" value="*" />
        <input type="submit" name="div" value="/" />
        </form>
    </body>
</html>
'''

import cgi
f = cgi.FieldStorage()

num1 = f.getfirst("num1", "0")
num2 = f.getfirst("num2", "0")

if f.getfirst("plus"):
    result = int(num1) + int(num2)
elif f.getfirst("minus"):
    result = int(num1) - int(num2)
elif f.getfirst("times"):
    result = int(num1) * int(num2)
elif f.getfirst("div"):
    result = int(num1) / int(num2)
else:
    result = 0

print(html % (num1, num2, result))