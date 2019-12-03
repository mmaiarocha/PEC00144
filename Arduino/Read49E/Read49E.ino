int  dx;          // Hall sensor signal
int  sensor = A0; // Hall sensor connected to analog input A0
long t, t0;       // Timing variables

void setup() {
     Serial.begin(115200);
     while (!Serial) delay(100);
     
     pinMode(LED_BUILTIN, OUTPUT);
     digitalWrite(LED_BUILTIN, LOW);
   
     delay(500);
}

void loop() {
     char line[17];

     if (Serial.available() > 0){
         String NS = Serial.readString();
         int    N  = NS.toInt();

         digitalWrite(LED_BUILTIN, HIGH);
         t0 = millis();
         
         for (int  i = 0; i < N; i++){
              t  = millis() - t0;
              dx = analogRead(sensor);

              sprintf(line, "%9ld %6d", t, dx);
              Serial.println(line);
              delay(10);
         }
         digitalWrite(LED_BUILTIN, LOW);
     }
     delay(200);
}
