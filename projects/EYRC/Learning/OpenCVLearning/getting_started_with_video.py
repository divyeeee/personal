import cv2
cap=cv2.VideoCapture(0)#this class makes an object stored in cap, which takes arguement of either video file name or device index of the camera from which we want to read
# now usually the device index is 0 or -1, but when using more cameras we can specifiy them using 1,2,....
fourcc=cv2.VideoWriter_fourcc(*'XVID')#this class generates a fourcc code
out=cv2.VideoWriter('output.avi',fourcc,20.0,(640,480))#writing our video captured into another file,first arguement-file name, second arguement-fourcc code-a four byte code which specifies the vidoe codec, our third arguement is number of frames persecond we want to write and our fourth arguemnt is the size of our video (width,height)- in form of tuple
print(cap.isOpened())
#if cap.isOpened==false, we can do cap.Open() to open our video file
while(cap.isOpened()):#while loop to capture the frame continuously, now when we give wrong file name or wrong index number,this will give an error, to avoid this we can/should write cap.isOpened() that checks if the video file or source is open or not
    ret,frame=cap.read()
    if ret== True:
        cap.get(cv2.CAP_PROP_FRAME_WIDTH)#cap.get() function allows us to get various property values regarding our video, here it will return width of our frame
    #these sorts of details we can get from opencv's documentation https://docs.opencv.org/4.0.0/d4/d15/...
        out.write(frame)#saving our video in bgr mode
    #read method is going to return true if the frame is available and store this value in ret, and the frame will be saved into frame variable.
        gray=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)#gray stores the grayscale img now,also cvtColor-->method that converts color from one to another and it takes various arguements--image,and color conversion method we want to use
        cv2.imshow('frame',gray)#window name given is frame in the first arguement
        if cv2.waitKey(1) & 0xFF == ord('q'):#0xFF is  a mask provided for 64-bit machines
            break
    else:
        break
cap.release()#releases value from cap variable
out.release()
cv2.destroyAllWindows()