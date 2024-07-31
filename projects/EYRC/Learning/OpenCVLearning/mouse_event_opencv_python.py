import numpy as np
import cv2

#events=[i for i in dir(cv2) if 'EVENT' in i]#stores all the elements in dir(cv2) if they have 'EVENT' in their names, dir method is an inbuilt method that shows all the classes and member variables inside the specified package, here cv2 is the package
#print(events)
#find=[i for i in dir(np) if 'n' in i]
#print(find)
#we are creating script for reading mouse events
def click_event(event,x,y,flags,para):#callback function for when an event is triggered or occurs
    if event==cv2.EVENT_LBUTTONDOWN:
        """print(x,', ',y)
        font=cv2.FONT_HERSHEY_SIMPLEX
        strXY=str(x)+', '+str(y)
        cv2.putText(img,strXY,(x,y),font,.5,(255,255,0),2)
        cv2.imshow('image',img)#the name of the window must remain same throughout
    if event==cv2.EVENT_RBUTTONDOWN:#event called when we click down right button on the mouse
        blue=img[y,x,0]#returns the blue channel values at coords x,y here 0 specifies blue as in order B G R or 0 1 2,blue channel means B's value in BGR at the point of the image
        green=img[y,x,1]
        red=img[y,x,2]
        font = cv2.FONT_HERSHEY_SIMPLEX
        strBGR = str(blue) + ', ' + str(green)+', '+str(red)
        cv2.putText(img, strBGR, (x, y), font, .5, (0, 255, 255), 2)
        cv2.imshow('image', img)"""
        blue=img[x,y,0]
        green=img[x,y,1]
        red=img[x,y,2]
        cv2.circle(img,(x,y),3,(0,255,255),-1)
        mycolorImage=np.zeros((512,512,3),np.uint8) #we are creating another image wherein the image shows the color at the coordinates we click our mouse at

        mycolorImage[:]=[blue,green,red]#this replicates all the values of blue,green,red at all the indices, that the whole image is filled with the same color

        cv2.imshow('color',mycolorImage)

#img=np.zeros((512,512,3),np.uint8)#black image created using numpy
img=cv2.imread('lena.jpg')
cv2.imshow('image',img)

cv2.setMouseCallback('image',click_event)

cv2.waitKey(0)
cv2.destroyAllWindows()