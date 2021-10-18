#to get the project into action we need to import some liabraries that are important
#cv2 is a liabrary (Opencv) that helps to get started

#I also used random liabrary that would be helpful in changing colours of Rectangle over face.

import cv2
from random import randrange 

#Now we need to put the trained data of opencv (face.xml as data) into trained_face_data variable to use it in detecting face.
trained_face_data= cv2.CascadeClassifier('face.xml')

#Now we needed input on which we can perform action
#we can take image as input or even video or a live camera photage as input data

#for image you can use 
img= cv2.imread('1.jpg')

#I am taking My pc webcam as input
webcam=cv2.VideoCapture(0)

#Here I am taking while loop because we are taking webcam video as input. 
#Let me elaborate the things:
#In trained data things are in form of image so we need to work on images like on each frame of vinput video that the reason we are using while loop 
#and breaking video into single frame to work on

while True:
      s_F_R,frame=webcam.read()
      #now we need to convert the image in gray picture as it enables to commpute fast. Like the size of data get decreased and it allows to work on thigs fast
      grayscaled_img=cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
      
      #now we have converted the image into gray scale and its time to detect the face.
      cordinates=trained_face_data.detectMultiScale(grayscaled_img)
      
       #Now we have to put rectangle on face so that its working can be seen
      for(x,y,w,h) in cordinates:
        cv2.rectangle(frame,(x,y),(x+w,y+h),(0,0,254),3)
      
      #cv2.imshow is making a new tab where you can actually see the working
      cv2.imshow('Face detector',frame)
      key=cv2.waitKey(1)

      if key==81 or key==113:
        break;