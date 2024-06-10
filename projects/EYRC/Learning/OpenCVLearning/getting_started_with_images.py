import cv2    #opencv module we are using
img = cv2.imread('lena.jpg',1)
"""imread reads our image, arguements include file name and second arguement is our flag which specifies how our umage will be read, ie either grayscale=0,color=-1,same image through alpha channels=1"""
print(img)#prints image in matrix form, which means it has read our image and stored in img variable in form of a matrix
cv2.imshow('image',img)#imshow--takes format in which you want to display, and the img value is passed, thus it converts our matrix in an image
k=cv2.waitKey(0) & 0xFF#waitKey specifies delay before passing or executing the next statement, here 0 value specifies infinite time or waiting for user input
if k==27:#ascii for esc
    cv2.destroyAllWindows()#destroys all the windows
elif k==ord('s'):#k stores any value passed when waiting,captures the keyboard value
    cv2.imwrite('lena_copy.png',img)#writes the value into another file named lena_copy.png
    cv2.destroyAllWindows()