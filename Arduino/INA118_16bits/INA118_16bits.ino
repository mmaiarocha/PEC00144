#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads1115;

// ads1015.setGain(GAIN_ONE);     // 1x gain   +/- 4.096V  1 bit = 2mV
// ads1015.setGain(GAIN_TWO);     // 2x gain   +/- 2.048V  1 bit = 1mV
// ads1015.setGain(GAIN_FOUR);    // 4x gain   +/- 1.024V  1 bit = 0.5mV
// ads1015.setGain(GAIN_EIGHT);   // 8x gain   +/- 0.512V  1 bit = 0.25mV
// ads1015.setGain(GAIN_SIXTEEN); // 16x gain  +/- 0.256V  1 bit = 0.125mV

void setup() {
  
     Serial.begin(230400);
     ads1115.begin();
     ads1115.setGain(GAIN_FOUR);
     delay(1000);
}

void loop( ){
  
     int16_t C1, C2;
     char    line[24];
     
     C1 = ads1115.readADC_Differential_0_1();
     C2 = ads1115.readADC_Differential_2_3();
     
     sprintf(line, "%9ld %6d %6d", millis(), C1, C2);
     Serial.println(line);

     delayMicroseconds(200);
}
