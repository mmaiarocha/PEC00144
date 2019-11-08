int myLED = 13;

void setup() {
  pinMode(myLED, OUTPUT);
  digitalWrite(myLED, LOW);
}

void loop() {
  digitalWrite(myLED, HIGH);
  delay(500);
  digitalWrite(myLED, LOW);
  delay(2000);
}
