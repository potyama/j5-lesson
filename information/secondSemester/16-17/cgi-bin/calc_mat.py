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
        <form action="calc_det.py" method="post">
            <input type="text" name="mat1_1" size="3" value="%s" />
            <input type="text" name="mat1_2" size="3" value="%s" />
            <input type="text" name="mat1_3" size="3" value="%s" />
            <br />
            <input type="text" name="mat1_4" size="3" value="%s" />
            <input type="text" name="mat1_5" size="3" value="%s" />
            <input type="text" name="mat1_6" size="3" value="%s" />
            <br />
            <input type="text" name="mat1_7" size="3" value="%s" />
            <input type="text" name="mat1_8" size="3" value="%s" />
            <input type="text" name="mat1_9" size="3" value="%s" />
            <br />

            [sign]
            <br />
            <input type="text" name="mat2_1" size="3" value="%s" />
            <input type="text" name="mat2_2" size="3" value="%s" />
            <input type="text" name="mat2_3" size="3" value="%s" />
            <br />
            <input type="text" name="mat2_4" size="3" value="%s" />
            <input type="text" name="mat2_5" size="3" value="%s" />
            <input type="text" name="mat2_6" size="3" value="%s" />
            <br />
            <input type="text" name="mat2_7" size="3" value="%s" />
            <input type="text" name="mat2_8" size="3" value="%s" />
            <input type="text" name="mat2_9" size="3" value="%s" />
            <br />
            = %s<br />

            <input type="submit" name="plus" value="+" />
            <input type="submit" name="times" value="*" />
        </form>
    </body>
</html>
'''

import cgi
import numpy as np
f = cgi.FieldStorage()

mat1_1 = int(f.getfirst("mat1_1", "1"))
mat1_2 = int(f.getfirst("mat1_2", "1"))
mat1_3 = int(f.getfirst("mat1_3", "1"))
mat1_4 = int(f.getfirst("mat1_4", "1"))
mat1_5 = int(f.getfirst("mat1_5", "1"))
mat1_6 = int(f.getfirst("mat1_6", "1"))
mat1_7 = int(f.getfirst("mat1_7", "1"))
mat1_8 = int(f.getfirst("mat1_8", "1"))
mat1_9 = int(f.getfirst("mat1_9", "1"))

mat2_1 = int(f.getfirst("mat2_1", "1"))
mat2_2 = int(f.getfirst("mat2_2", "1"))
mat2_3 = int(f.getfirst("mat2_3", "1"))
mat2_4 = int(f.getfirst("mat2_4", "1"))
mat2_5 = int(f.getfirst("mat2_5", "1"))
mat2_6 = int(f.getfirst("mat2_6", "1"))
mat2_7 = int(f.getfirst("mat2_7", "1"))
mat2_8 = int(f.getfirst("mat2_8", "1"))
mat2_9 = int(f.getfirst("mat2_9", "1"))

arr1 = np.matrix(np.array([[mat1_1, mat1_2, mat1_3],
                 [mat1_4, mat1_5, mat1_6],
                 [mat1_7, mat1_8, mat1_9]], dtype=object))

arr2 = np.matrix(np.array([[mat2_1, mat2_2, mat2_3],
                 [mat2_4, mat2_5, mat2_6],
                 [mat2_7, mat2_8, mat2_9]], dtype=object))


if f.getfirst("plus"):
    result = arr1 + arr2
elif f.getfirst("times"):
    result = np.dot(arr1, arr2)

else:
    result = 0


print(html % (mat1_1, mat1_2, mat1_3, mat1_4, mat1_5, mat1_6, mat1_7, mat1_8, mat1_9, mat2_1, mat2_2, mat2_3, mat2_4, mat2_5, mat2_6, mat2_7, mat2_8, mat2_9, result))