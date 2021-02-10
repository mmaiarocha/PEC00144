// ==========================================================================================
// ATTENUATION: Petrobras project for experimental analysis of soil-chain interaction.
// Author:      Prof.Dr. Marcelo M. Rocha - PPGEC/UFRGS
// ==========================================================================================
// ads.setGain(GAIN_ONE);       // 1x gain   +/- 4.096V  1 bit = 2mV      0.125mV

#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <DueFlashStorage.h>
#include <Adafruit_ADS1015.h>
#include <LiquidCrystal_I2C.h>

// Variables for file name definition through EPROM
   int    Ecount = 0;      // Flash counter for file name first part
   int    Eaddrs = 0;      // this is the flash address to be used
   int    fcount = 0;      // Counter for file name second part
   char   filename[12];    // SD card file name
   bool   rec = LOW;       // recording begins not activated
   DueFlashStorage flash;

// SD card file instance
   const int ST  = 3;      // REC start/stop pin
   const int CS  = 4;      // data pin for SD card
   File   file;

// ADS1115 instance
   Adafruit_ADS1115  ads(0x48);  //

// LCD instance
   LiquidCrystal_I2C lcd(0x27, 20, 4);

// Acquisition variables
   int       NA  = 32;          // length of mov average
   int       NB  = 32;          // memory for length above
   uint16_t  D0, D1, D2, D3;    // data from ADS115
   uint16_t  S1, C1, S2, C2;    // averaged signal
   char      line0[45];         // SD formated output
   char      line1[21];         // LCD formatted output line 1
   char      line2[21];         // LCD formatted output line 2
   long      t0, t;             // time from internal clock

// ==========================================================================================
// ==========================================================================================

void setup(){

// Setup REC start/stop pin
   pinMode(ST, INPUT_PULLUP);

// Setup serial (only for debugging)
   Serial.begin(9600);
   while (!Serial){delay(100);}

// Update EPROM file counter
   Ecount = int(flash.read(Eaddrs));
   flash.write(Eaddrs, (byte)(Ecount+1));
   fcount = 0;

// Setup ADS1115 with gain ONE:
// (0.000V - 4.096V)/15bits => dV = 0.125mV
// This implies that: 1.00V (-1g) is  8000,
//                    1.67V ( 0g) is 13333,
//                    2.33V (+1g) is 18667.
   ads.begin();
   ads.setGain(GAIN_ONE);

// Setup LCD display
   lcd.begin();
   lcd.setBacklight(HIGH);
   lcd.setCursor(0,0);
   lcd.print("Setup device... ");
   Serial.println("Setup device... ");

// Setup SD card writer
   lcd.setCursor(0,1);
   lcd.print("Setup SD card... ");
   Serial.println("Setup SD card... ");

   if (!SD.begin(CS)){
       lcd.setCursor(0,2);
       lcd.print("SD card fail! ");
       Serial.println("SD card fail! ");
       while(1);
      }
   else{
       lcd.setCursor(0,2);
       lcd.print("SD card Ok! ");
       Serial.println("SD card Ok! ");
      }
   delay(1000);

// Finishing setup
   lcd.clear();
   lcd.setCursor(0,0);
//            1---|----|----|----2
   lcd.print("PETROBRAS  --  UFRGS");
   
   t0 = millis();
}

// ==========================================================================================
// ==========================================================================================

void loop(){

// ------------------------------------------------------------------------------------------
// 1. Check is recording is activated or not

     if (!digitalRead(ST)){
 
         delay(250);
         
         if (!rec){
              rec = HIGH;
              NA  = 1;
              fcount++;
              sprintf(filename, "E%03dF%02d.txt", Ecount, fcount);

              lcd.setCursor(0,3);
              lcd.print(filename);               
              Serial.println(filename);               
              delay(2000);
            
              file = SD.open(filename, FILE_WRITE);
              Serial.println(file);
              
              if (!file){
                   lcd.setCursor(0,3);
                   lcd.print("File open fail! ");
                   Serial.println("File open fail! ");
                   while(1);
                  }

              else{
                   lcd.setCursor(0,3);
                   lcd.print("File open ok!   ");
                   Serial.println("File open ok!   ");
                   
                   delay(2000);
                   lcd.setCursor(0,3);
                   lcd.print("                ");
                   
                   lcd.setCursor(0,3);
                   lcd.print(filename);   
                   Serial.println(filename);   
                  }
          }

          else{
               rec = LOW;
               NA  = NB;
               file.close();
               lcd.setCursor(0,3);
               lcd.print("File closed!");
               Serial.println("File closed!");
                
               delay(2000);
               lcd.setCursor(0,3);
               lcd.print("            ");
          }
     }  

// ------------------------------------------------------------------------------------------
// 2. The acquisition itself
 
     t  = millis() - t0;
     
     S1 = 0; C1 = 0;
     S2 = 0; C2 = 0;

     for (int i = 0; i < NA; i++) {
      
          D0 = ads.readADC_SingleEnded(0);    // inclinometer S1
          D1 = ads.readADC_SingleEnded(1);    // inclinometer S2 
          D2 = ads.readADC_SingleEnded(2);    // load cell C1
          D3 = ads.readADC_SingleEnded(3);    // load cell C2

          S1 += D0/NA;   C1 += D2/NA;
          S2 += D1/NA;   C2 += D3/NA;

          delayMicroseconds(500);
     }

// ------------------------------------------------------------------------------------------
// 3. Output to where it belongs

     sprintf(line0, "%10ld, %6d, %6d, %6d, %6d", t, S1, C1, S2, C2);
     sprintf(line1, "I1:%6d  I2:%6d", S1, S2);
     sprintf(line2, "T1:%6d  T2:%6d", C1, C2);

     lcd.setCursor(0,1); lcd.print(line1);
     lcd.setCursor(0,2); lcd.print(line2);

     if (rec){
         file.println(line0);
//       Serial.print(line0);
        }
     else{
         Serial.print(line1);
         Serial.print("  ");
         Serial.println(line2); 
         delay(1000);
         }    
}

// ==========================================================================================
// ==========================================================================================
