int pin_led = 13;
int pin_ax  = A0;
int pin_ay  = A1;

void setup() {
     Serial.begin(9600);
     
     pinMode(pin_led, OUTPUT);
     digitalWrite(pin_led, LOW);
     delay(100);
}

void loop() {
     char line[24];
     
     digitalWrite(pin_led, HIGH);

     long t = millis();
     int ax = analogRead(pin_ax);
     int ay = analogRead(pin_ay);

     sprintf(line, "%9ld %6d %6d", t, ax, ay);
     Serial.println(line);

     digitalWrite(pin_led, LOW);
     delay(100);
}
