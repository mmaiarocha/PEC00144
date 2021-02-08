int myLED = 13;

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
