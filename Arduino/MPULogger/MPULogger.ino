#include <LiquidCrystal_I2C.h>

//======================================================================
//======================================================================
//
//   PROGRAM MPULogger
//   Author: Prof. Marcelo M. Rocha
//   UFRGS, nov-2019
//
//======================================================================
//======================================================================

#include <EEPROM.h>
#include <Wire.h>
#include <SPI.h>
#include <SdFat.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x3F
   LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Variables for file name definition through EPROM
   int      Ecount = 0;           // EPROM counter for file name
   int      Eaddrs = 0;           // this is the EPROM to be used
   int      fcount = 0;           // number of file after setup
   char     filename[17];         // SD card file name
   char     dataline[42];         // output data string

// SD card
   int      led = 13;             // file writing warning
   int      CS  = 53;             // data pin for SD card
   SdFat    card;                 // SD card handle
   SdFile   file;                 // file handle

// MPU6050
   int      MPU = 0x69;           // MPU address (AD0 HIGH)
   uint16_t Ndt = 16384;          // length of acquisition file
   int16_t  AcX, AcY, AcZ, tmp;   // accelerometer output
   int16_t  GyX, GyY, GyZ;        // gyroscope output

//======================================================================
//======================================================================

void setup() {

//   Setup serial
     Serial.begin(57600);
     while (!Serial){
             SysCall::yield();
            }

//   Update EPROM file counter
     Ecount = int(EEPROM.read(Eaddrs));
     EEPROM.write(Eaddrs, (byte)(Ecount+1));
     fcount = 0;

//   Setup LCD
     lcd.begin(16,2);
     lcd.setBacklight(HIGH);

//   Setup SD card
     Serial.print("SD open: ");
     lcd.setCursor(0,0);
     lcd.print("Sd open: ");
     delay(1000);

     pinMode(CS, OUTPUT);
     if (!card.begin(CS)){
          Serial.println("fail!  ");
          lcd.setCursor(9,0);
          lcd.print("fail!  ");
          while(1);
     }
     else {
          Serial.println("ok!    ");
          lcd.setCursor(9,0);
          lcd.print("ok!    ");
          delay(1000);
     }

     digitalWrite(led, LOW);
}  

//======================================================================
//======================================================================

void loop() {

     fcount++;
     sprintf(filename, "E%03dF%04d.txt", Ecount, fcount);
     
     Serial.print("File open... ");
     lcd.setCursor(0,0);
     lcd.print("File open... ");
     
     Serial.print(filename);
     lcd.setCursor(0,1);
     lcd.print(filename);

     if (!file.open(filename, O_CREAT|O_WRITE|O_EXCL)){
          Serial.println(" ... fail! ");
          lcd.setCursor(0,1);
          lcd.print("File open fail! ");
          while(1);
         }

     digitalWrite(led, HIGH);
     uint32_t t0 = millis();
     for (uint16_t i = 0; i < Ndt; i++){
    
          Wire.beginTransmission(MPU);
          Wire.write(0x3B);
          Wire.endTransmission(false);
          Wire.requestFrom(MPU,14,true);
       
          AcX  = Wire.read()<<8 | Wire.read();
          AcY  = Wire.read()<<8 | Wire.read();
          AcZ  = Wire.read()<<8 | Wire.read();
          tmp  = Wire.read()<<8 | Wire.read();
          GyX  = Wire.read()<<8 | Wire.read();
          GyY  = Wire.read()<<8 | Wire.read();
          GyZ  = Wire.read()<<8 | Wire.read();

          sprintf(dataline,"%5d\t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\n", 
                            AcX,AcX,AcZ,tmp,GyX,GyY,GyZ);
                            
          file.print(dataline);
          Wire.endTransmission(true);
         }

     uint32_t dt = millis() - t0;
     file.println(dt);  
     file.close();
     digitalWrite(led, LOW);

     Serial.print(" ]... file closed after ");
     Serial.print(millis() - t0);
     Serial.println(" milliseconds.");
     lcd.setCursor(0,1);
     lcd.print("Acquisition ok! ");

     delay(5000);}

//======================================================================
//======================================================================
