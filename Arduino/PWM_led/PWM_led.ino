int myLED = 9;   // PWM 490Hz pin!!!

void setup() {
     pinMode(myLED, OUTPUT);
}

void loop() {
  
//     digitalWrite(myLED, HIGH);
//     delayMicroseconds(1000);
//     digitalWrite(myLED, LOW);
//     delayMicroseconds(10000);

     analogWrite(myLED, 63);  // zero to 255
}
