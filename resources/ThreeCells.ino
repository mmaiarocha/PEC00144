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

     long    data[3];
     char    dataline[27];
     byte    b;

     if (Serial.available() > 0){

         digitalWrite(led1, LOW);   
         digitalWrite(led2, HIGH); 

         b = char(Serial.read());
         cells.read(data);
     
         sprintf(dataline, "%8ld %8ld %8ld", 
                            data[0], data[1], data[2]);
                        
         Serial.println(dataline);

         delay(100);

         digitalWrite(led2, LOW); 
         digitalWrite(led1, HIGH);   

         }
}

