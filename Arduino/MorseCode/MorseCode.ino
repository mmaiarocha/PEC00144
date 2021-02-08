int LED_pin  = 13;
int velocity = 50;

void setup() {

  pinMode(LED_pin, OUTPUT);

}

void loop() {

  dot();  dot();  dot();  space();
  dash(); dash(); dash(); space();
  dot();  dot();  dot();  space();
  
  space(); space(); space();
  
}

void dot(){
  digitalWrite(LED_pin, HIGH);    
  delay(velocity);
  digitalWrite(LED_pin, LOW);    
  delay(velocity);
}

void dash(){
  digitalWrite(LED_pin, HIGH);    
  delay(2*velocity);
  digitalWrite(LED_pin, LOW);    
  delay(2*velocity);
}

void space(){
  delay(4*velocity);
}
