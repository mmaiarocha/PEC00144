#include "HX711-multi.h"

#define Ncell 2                      // number of cells to be read

byte CLK = 3;                        // clock pin
byte DOUT[Ncell] = {5, 6};           // list of data pins

long dV[Ncell];                      // data matrix (same length as DOUT)
long dVsum[Ncell];                   // for averaging

long t, t0;
char line[23];

HX711MULTI cells(Ncell, DOUT, CLK);  // create object "cells" 

void setup(){

   Serial.begin(115200);
   while (!Serial) delay(100);
  
   delay(1000);          
}

void loop(){

     if (Serial.available()){
         String NS = Serial.readString();
         int    N  = NS.toInt();

         t0 = millis();
         
         for (int i = 0; i < N; i++){
          
              dVsum[0] = 0;
              dVsum[1] = 0;
              for (int j = 0; j < 8; j++){
                   cells.read(dV);
                   dVsum[0] += dV[0];
                   dVsum[1] += dV[1];
                   delay(100);
              }
              dV[0] = dVsum[0]/8;
              dV[1] = dVsum[1]/8;
              t  = millis() - t0;

              sprintf(line,"%9ld %6d %6d", t, dV[0], dV[1]);
              Serial.println(line);
              delay(100);
         }
     }
}
//======================================================================
//======================================================================
