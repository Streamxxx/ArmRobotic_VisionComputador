import cv2
import numpy as np
import serial

ser = serial.Serial('COM4',9600)

def dibujar(mask, color):
    contornos, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) 
    #cv2.drawContours(frame, contornos, -1 ,(255,0,0), 3)
    for c in contornos:
        area=cv2.contourArea(c)
        #Aumentar para alejar mas
        if area > 1000:
            M = cv2.moments(c)
            if (M["m00"]==0): 
                M["m00"]=1
            x = int(M["m10"]/M["m00"])
            y = int(M['m01']/M['m00'])
            nuevoContorno=cv2.convexHull(c)
            cv2.circle(frame, (x,y), 4, (0,255,0), -1)
            cv2.putText(frame, '{},{}'.format(x,y),(x+10,y), font, 0.75,(0,255,255),1,cv2.LINE_AA)
            cv2.drawContours(frame, [nuevoContorno], 0 ,color, 3)

cap = cv2.VideoCapture(0)

azulBajo = np.array([100,100,20], np.uint8)
azulAlto = np.array([125,255,255], np.uint8)

verdeBajo = np.array([45,100,20], np.uint8)
verdeAlto = np.array([75,255,255], np.uint8)

rojoBajo1 = np.array([0,100,20], np.uint8)
rojoAlto1 = np.array([8,255,255], np.uint8)
rojoBajo2 = np.array([170,100,20], np.uint8)
rojoAlto2 = np.array([179,255,255], np.uint8)


font = cv2.FONT_HERSHEY_SIMPLEX

while True:
    ret, frame = cap.read()
    if ret == True:
        frameHSV=cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        maskAzul = cv2.inRange(frameHSV,azulBajo,azulAlto)
        maskGreen = cv2.inRange(frameHSV,verdeBajo,verdeAlto)
        maskRed1 =cv2.inRange(frameHSV,rojoBajo1,rojoAlto1)
        maskRed2 =cv2.inRange(frameHSV,rojoBajo2,rojoAlto2)
        maskRed = cv2.add(maskRed1,maskRed2)
        dibujar(maskAzul,(255,0,0))
        dibujar(maskGreen,(0,143,57))
        dibujar(maskRed,(0,0,255))
        
        ser.write(str('a').encode())
        ser.write(str('b').encode())
        ser.write(str('c').encode())
        cv2.imshow('frame',frame)
        if cv2.waitKey(1) & 0xFF == ord('s'):
            break
cap.release()
cv2.destroyAllWindows()
