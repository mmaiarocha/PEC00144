int  led = 13;
long t0;

void setup(){
     Serial.begin(115200);

     pinMode(led, OUTPUT);
     digitalWrite(led, LOW);
      
     randomSeed(0);
     delay(100);
     t0 = millis();
}

void loop(){

     long t;
     long data[3];
     char line[41];
     byte gotIt;   

     if (Serial.available()){
         String NS = Serial.readString();
         int    N  = NS.toInt();
         digitalWrite(led, HIGH);
         
         for (int i = 0; i < N; i++){

              t       = millis() - t0;
              data[0] = random(99999999);
              data[1] = random(99999999);
              data[2] = random(99999999);
       
              sprintf(line, "%9ld %9ld %9ld %9ld\n", 
                       t, data[0], data[1], data[2]);
                          
              Serial.print(line);
              delayMicroseconds(1000);
              }
              
         digitalWrite(led, LOW); 
     }
}
