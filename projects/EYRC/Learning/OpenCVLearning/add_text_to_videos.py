import cv2
cap=cv2.VideoCapture(0)
print(cap.get(cv2.CAP_PROP_FRAME_WIDTH))#this notation can be used without writing the whole number, like cv2.CAP_FRAME_WIDTH can be written as 3 in numeric notation
print(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

cap.set(3,3000)#used to set some values just like get is used to get some values
cap.set(4,3000)#4--->cv2.CAP_PROP_HEIGHT is changed to 720
#the camera will only set the resolution available to it, any random height and width won't do
print(cap.get(3))
print(cap.get(4))
while(cap.isOpened()):
    ret, frame = cap.read()
    if ret == True:
         gray=cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
         cv2.imshow('frame',gray)

         if cv2.waitKey(1) & 0xFF==ord('q'):
            break
    else:
        break

cap.release()
cv2.destroyAllWindows()

