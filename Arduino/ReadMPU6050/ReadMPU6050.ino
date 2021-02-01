//======================================================================
//   PROGRAM ReadMPU6050
//   Author: Prof. Marcelo M. Rocha
//======================================================================
#include <Wire.h>
#include <SPI.h>

// Auxiliary variables
   char     line[30];             // formatted output
   long     t0, t;                // time from internal clock

// MPU6050
   int      MPU = 0x68;           // MPU address (AD0 HIGH)
   int16_t  AcX, AcY, AcZ, tmp;   // accelerometer output
   int16_t  GyX, GyY, GyZ;        // gyroscope output

//======================================================================
//======================================================================

void setup() {

   Serial.begin(115200);
   while (!Serial)delay(100);

   Wire.begin();                 // Initialize comunication
   Wire.beginTransmission(MPU);  // Start communication with MPU6050
   Wire.write(0x6B);             // Talk to the register 6B
   Wire.write(0x00);             // Make reset(0 into the 6B register)
   Wire.endTransmission(true);   // end the transmission
   
   delay(1000);
   t0 = millis();
}  

//======================================================================
//======================================================================

void loop(){

     if (Serial.available() > 0){
         String NS = Serial.readString();
         int    N  = NS.toInt();
         
         for (int i = 0; i < N; i++){

              Wire.beginTransmission(MPU);
              Wire.write(0x3B);
              Wire.endTransmission(false);
              Wire.requestFrom(MPU, 6, true);  // 2 bytes for each parameters

              AcX  = Wire.read()<<8 | Wire.read();
              AcY  = Wire.read()<<8 | Wire.read();
              AcZ  = Wire.read()<<8 | Wire.read();
//            tmp  = Wire.read()<<8 | Wire.read();
//            GyX  = Wire.read()<<8 | Wire.read();
//            GyY  = Wire.read()<<8 | Wire.read();
//            GyZ  = Wire.read()<<8 | Wire.read();

              t  = millis() - t0;

              sprintf(line,"%9ld %6d %6d %6d", 
                             t,   AcX,AcY,AcZ);

              Serial.println(line);
              Wire.endTransmission(true); 
              delayMicroseconds(1000);
              }
         }
}

//======================================================================
//======================================================================
