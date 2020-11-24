import matplotlib.pyplot as plt
import cv2
from mosaic import mosaic as mosaic

cascade_file = "./haarcascades/haarcascade_frontalface_alt.xml"
cascade = cv2.CascadeClassifier(cascade_file)

img = cv2.imread("face.jpg")
img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

face_list = cascade.detectMultiScale(img_gray, minSize=(150, 150))
if len(face_list) == 0: quit()

for (x, y, w, h) in face_list:
    img = mosaic(img, (x, y, x+w, y+h), 10)
cv2.imwrite("anime_mosaic.png", img)
plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2GRAY))
plt.show()