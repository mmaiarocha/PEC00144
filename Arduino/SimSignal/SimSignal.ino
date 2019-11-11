int  led = 13;

void setup(){
     Serial.begin(9600);
     
     pinMode(led, OUTPUT);
     digitalWrite(led, LOW);
      
     randomSeed(0);
     delay(100);
}

void loop(){

     long t;
     long data[3];
     char line[40];
     byte gotIt;   

     if (Serial.available() > 0){
         gotIt   = Serial.read();
         digitalWrite(led, HIGH);

         t       = millis();
         data[0] = random(99999999);
         data[1] = random(99999999);
         data[2] = random(99999999);
     
         sprintf(line,   "%9ld %9ld %9ld %9ld", 
                 t, data[0], data[1], data[2]);
                        
         Serial.println(line);

         delay(50);
         digitalWrite(led, LOW); 
         }
}
