int  led = 13;

void setup(){
     Serial.begin(9600);
     
     pinMode(led, OUTPUT);
     digitalWrite(led, LOW);
      
     randomSeed(0);
     delay(1000);
}

void loop(){

     long data[3];
     char line[27];
     int  gotIt;   

     if (Serial.available() > 0){
         digitalWrite(led, HIGH);
         
         gotIt   = Serial.read();
         data[0] = random(99999999);
         data[1] = random(99999999);
         data[2] = random(99999999);
     
         sprintf(line,    "%8ld %8ld %8ld", 
                 data[0], data[1], data[2]);
                        
         Serial.println(line);

         delay(100);
         digitalWrite(led, LOW); 
         }
}
