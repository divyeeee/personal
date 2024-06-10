#drawing is actually done by overwriting the image we have been given
import numpy as np
import cv2
#img=cv2.imread('lena.jpg',-1)
img=np.zeros([512,512,3],np.uint8)#creates image with height 512,width 512,this data is in form is in form of a list,next arguement takes datatype
img =cv2.line(img,(0,0),(255,255),(147,96,44),10)#draws a line over in our image, arguements-variable storing our image,point p1 to p2, coords of p1 and p2 in seperate tuples,bgr values for the line in a tuple, and thickness
#if thickness=-1, then it fills our shape with the specified color
font=cv2.FONT_HERSHEY_PLAIN
img=cv2.putText(img,'Text',(10,500),font,4,(1,255,1),5,cv2.LINE_AA)#writes on our image
cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()