#include <Servo.h>
Servo servobase; //Servomotor adelante
Servo servo2; //Servomotor arriba
Servo servo1; 
Servo servopinza;  // crear un objeto servomotor para controlar un servo

int mssg = 0; //variable para guardar el mensaje

int cerrado = 1;

void setup() {
  servobase.attach(12);
  servo2.attach(10);
  servo1.attach(11);
  servopinza.attach(9);
  Serial.begin(9600); //inicializamos Serial
  servobase.write(0);
  servo1.write(80);
  servo2.write(80);
  servopinza.write(35);
   
}

void loop()
{
   if (Serial.available() > 0)
   {
      if(cerrado==1)
      {
          mssg = Serial.read(); //leemos el serial
          if(mssg == 'a')
          {                 
              cerrado=0;              


              delay(3000);

              //Pinza
              for(int i=45; i<=60; i++){
                servopinza.write(i);
                delay(25);
              }
              delay(1000);


              //Motor1
              for(int i=80; i>=0; i--){
                servo1.write(i);
                delay(25);
              }
              delay(1000);

              //Motor2
              for(int i=80; i<=150; i++){
                servo2.write(i);
                delay(25);
              }
              delay(1000);

              for(int i=60; i>=10; i--){
                servopinza.write(i);
                delay(25);
              }
              delay(1000);
              for (int i = 150; i>=80; i--){
                servo2.write(i);
                delay(25);
              }
              delay(1000);
              for (int i = 0; i<=80; i++){
                servo1.write(i);
                delay(25);
              }
              delay(1000);
              //Base
              for(int i=0; i<=45; i++){
                servobase.write(i);
                delay(25);
              }
              delay(1000);
              //DEJAR OBJETO -------
            
              for(int i=80; i>=0; i--){
                servo1.write(i);
                delay(25);
              }
              delay(1000);
              for(int i=80; i<=110; i++){
                servo2.write(i);
                delay(25);
              }
              delay(1000);
              
              for(int i=10; i<=60; i++){
                servopinza.write(i);
                delay(25);
              }
              delay(1000);
              for (int i = 110; i>=80; i--){
                servo2.write(i);
                delay(25);
              }
              delay(1000);
              for (int i = 0; i<=80; i++){
                servo1.write(i);
                delay(25);
              }
              delay(1000);
              for(int i=60; i>=10; i--){
                servopinza.write(i);
                delay(25);
              }
              delay(1000);
              //regreso
              for(int i=45; i>=0; i--){
                servobase.write(i);
                delay(25);
              }
              delay(1000);

//=-----
              cerrado=1;
          }
          if(mssg == 'b')
          {
              cerrado=0;              


              delay(3000);

              //Pinza
              for(int i=45; i<=60; i++){
                servopinza.write(i);
                delay(25);
              }
              delay(1000);


              //Motor1
              for(int i=80; i>=0; i--){
                servo1.write(i);
                delay(25);
              }
              delay(1000);

              //Motor2
              for(int i=80; i<=150; i++){
                servo2.write(i);
                delay(25);
              }
              delay(1000);

              for(int i=60; i>=10; i--){
                servopinza.write(i);
                delay(25);
              }
              delay(1000);
              for (int i = 150; i>=80; i--){
                servo2.write(i);
                delay(25);
              }
              delay(1000);
              for (int i = 0; i<=80; i++){
                servo1.write(i);
                delay(25);
              }
              delay(1000);
              //Base
              for(int i=0; i<=90; i++){
                servobase.write(i);
                delay(25);
              }
              delay(1000);
              //DEJAR OBJETO -------
            
              for(int i=80; i>=0; i--){
                servo1.write(i);
                delay(25);
              }
              delay(1000);
              for(int i=80; i<=110; i++){
                servo2.write(i);
                delay(25);
              }
              delay(1000);
              
              for(int i=10; i<=60; i++){
                servopinza.write(i);
                delay(25);
              }
              delay(1000);
              for (int i = 110; i>=80; i--){
                servo2.write(i);
                delay(25);
              }
              delay(1000);
              for (int i = 0; i<=80; i++){
                servo1.write(i);
                delay(25);
              }
              delay(1000);
              for(int i=60; i>=10; i--){
                servopinza.write(i);
                delay(25);
              }
              delay(1000);
              //regreso
              for(int i=90; i>=0; i--){
                servobase.write(i);
                delay(25);
              }
              delay(1000);

//=-----
              cerrado=1;
          }
          
          if(mssg == 'c')
          {
              cerrado=0;              
              
              delay(5000);

              cerrado=1;
          }
       }
    }
}