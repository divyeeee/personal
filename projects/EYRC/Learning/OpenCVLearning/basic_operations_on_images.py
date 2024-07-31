import cv2
import  numpy as np
img=cv2.imread('lena.jpg')

print(img.shape)#return a tuple of number of rows, columns and channels
print(img.size)#returns Total number of pixels is accessed
print(img.dtype)#returns image datatype is obtained
b,g,r=cv2.split(img)

img=cv2.merge((b,g,r))

cv2.imshow('image',img)

cv2.waitKey(0)
cv2.destroyAllWindows()

