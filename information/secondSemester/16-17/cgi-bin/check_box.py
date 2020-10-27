#!/usr/bin/python
# -*- coding: utf-8 -*-

html = '''Content-Type: text/html

<html>
    <head>
        <meta charset='utf-8'>
        <title>選択されたチェックボックスを取得する</title>
    </head>
    <body>
        <h1>選択されたチェックボックスを取得する</h1>
        <p>選択された値は"%s"です。</p>
        <form action="check_box.py" method="post">
            <input type="checkbox" name="Python" value="Python" id="Python"/>
                <label for="Python">Python</label><br />
            <input type="checkbox" name="Ruby" value="Ruby" id="Ruby" />
                <label for="Ruby">Ruby</label><br />

            <input type="checkbox" name="Perl" value="Perl" id="Perl" />
                <label for="Perl">Perl</label><br />
            <input type="submit" />
        </form>
    </body>
</html>
'''

import cgi
f = cgi.FieldStorage()


if f.getfirst('Python'):
    str = "Python"
if f.getfirst('Ruby'):
    str = "Ruby"
if f.getfirst('Perl'):
    str = "Perl"
print(html%str)