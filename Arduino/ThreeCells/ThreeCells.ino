#include "HX711-multi.h"
#include <Wire.h>

byte CLK     =  A0;
byte DOUT[3] = {A1, A2, A3};

int  powr = 7;
int  led1 = 6;
int  led2 = 5;

HX711MULTI cells(3, DOUT, CLK);

void setup(){
     Serial.begin(9600);
     
     pinMode(led1, OUTPUT);
     digitalWrite(led1, HIGH);   
     
     pinMode(led2, OUTPUT);
     digitalWrite(led2, LOW); 
       
     pinMode(powr, OUTPUT);
     digitalWrite(powr, HIGH);   
     
     delay(1000);
}

void loop(){

     long t;
     long data[3];
     char line[40];
     byte gotIt;   

     if (Serial.available() > 0){
         gotIt = Serial.read();
         digitalWrite(led2, HIGH); 
         digitalWrite(led1, LOW);   

         t = millis();
         cells.read(data);
     
         sprintf(line,   "%9ld %9ld %9ld %9ld", 
                 t, data[0], data[1], data[2]);
                        
         Serial.println(line);

         delay(100);

         digitalWrite(led2, LOW); 
         digitalWrite(led1, HIGH);   

         }
}
