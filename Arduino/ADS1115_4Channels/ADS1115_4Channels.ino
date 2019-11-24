#include <Wire.h>
#include <Adafruit_ADS1015.h>

// Gain setting table:
// ==========================================================================================
// ads.setGain(GAIN_TWOTHIRDS); // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
// ads.setGain(GAIN_ONE);       // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV
// ads.setGain(GAIN_TWO);       // 2x gain   +/- 2.048V  1 bit = 1mV      0.0625mV
// ads.setGain(GAIN_FOUR);      // 4x gain   +/- 1.024V  1 bit = 0.5mV    0.03125mV
// ads.setGain(GAIN_EIGHT);     // 8x gain   +/- 0.512V  1 bit = 0.25mV   0.015625mV
// ads.setGain(GAIN_SIXTEEN);   // 16x gain  +/- 0.256V  1 bit = 0.125mV  0.0078125mV

// Acquisition variables
   uint16_t C0, C1, C2, C3;     // data from ADS115
// char     line[38];           // formatted output
   char     line[24];           // formatted output
   long     t0, t;              // time from internal clock

// ADS1115 instance
   Adafruit_ADS1115  ads(0x48);  //

void setup(){

// Setup serial (only for debugging)
   Serial.begin(230400);
   while (!Serial){delay(100);}

// Setup ADS1115
   ads.begin();
   ads.setGain(GAIN_ONE);
   
   delay(1000);
   t0 = millis();
}

void loop(){
     if (Serial.available() > 0){
         String NS = Serial.readString();
         int    N  = NS.toInt();
 
         for (int i = 0; i < N; i++){

              C0 = ads.readADC_SingleEnded(0);
              C1 = ads.readADC_SingleEnded(1);
//            C2 = ads.readADC_SingleEnded(2);
//            C3 = ads.readADC_SingleEnded(3);
     
              t  = millis() - t0;
            
//            sprintf(line, "%9ld %6d %6d %6d %6d\n", 
//                            t,   C0, C1, C2, C3);
              sprintf(line, "%9ld %6d %6d\n", 
                              t,   C0, C1);
                            
              Serial.print(line);
              }
         }
}
