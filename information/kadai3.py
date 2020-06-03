import numpy as np

a = np.array([1,2,3])
print("array ->" + str(a))
print("array.dtype -> "+ str(a.dtype))
print("array.shape -> " + str(a.shape))
print("array.size -> " + str(a.size))
print("array.nbytes -> " + str(a.nbytes))

print("a*2 = " +str(a*2))
b = a.tolist()#Conversion to list type
print("b*2 = "+ str(b*2))
a = np.array(b)
print("a*2 = " + str(a*2))

a = np.arange(5)
print("arange ->" + str(a))
print("arange.dtype -> "+ str(a.dtype))
print("arange.shape -> " + str(a.shape))
print("arange.size -> " + str(a.size))
print("arange.nbytes -> " + str(a.nbytes))

a = np.arange(1,5,3)
print("arange ->" + str(a))
print("arange.dtype -> "+ str(a.dtype))
print("arange.shape -> " + str(a.shape))
print("arange.size -> " + str(a.size))
print("arange.nbytes -> " + str(a.nbytes))

a = np.linspace(0,8,5)
print("linspace ->" + str(a))
print("linspace.dtype -> "+ str(a.dtype))
print("linspace.shape -> " + str(a.shape))
print("linspace.size -> " + str(a.size))
print("linspace.nbytes -> " + str(a.nbytes))

a = np.eye(2)
print("eye -> \n" +str(a))
print("eye.dtype -> "+ str(a.dtype))
print("eye.shape -> " + str(a.shape))
print("eye.size -> " + str(a.size))
print("eye.nbytes -> " + str(a.nbytes))

a = np.zeros(5)
print("zeros ->" + str(a))
print("zeros.dtype -> "+ str(a.dtype))
print("zeros.shape -> " + str(a.shape))
print("zeros.size -> " + str(a.size))
print("zeros.nbytes -> " + str(a.nbytes))

a = np.zeros((3,3))
print("zeros ->\n" + str(a))


