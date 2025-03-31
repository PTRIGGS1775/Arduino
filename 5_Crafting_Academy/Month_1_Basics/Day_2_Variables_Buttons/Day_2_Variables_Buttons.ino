const int ledPinOn = 2;
const int ledPinOff = 3;
const int button = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPinOn, OUTPUT);
  pinMode(ledPinOff, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = digitalRead(button);
  if (buttonState == HIGH){
    digitalWrite(ledPinOn, HIGH);
    digitalWrite(ledPinOff, LOW);
    Serial.println("I'm HIGH!");
  }
  else{
    digitalWrite(ledPinOn, LOW);
    digitalWrite(ledPinOff, HIGH);
    Serial.println("I'm LOW!");
  }

}
