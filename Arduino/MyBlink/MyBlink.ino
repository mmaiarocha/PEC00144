int myLED = 9;   // PWM 490Hz pin!!!

void setup() {
  pinMode(myLED, OUTPUT);
  digitalWrite(myLED, LOW);
}

void loop() {
  digitalWrite(myLED, HIGH);
  delay(50);
  digitalWrite(myLED, LOW);
  delay(500);
}
