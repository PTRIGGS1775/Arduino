const int led = 5;
int pwmValues[5] = {50, 100, 150, 200, 255};

void dimLed(int pinLed, int pwm, int duration){ //Set PWM to a value between 0-255
  Serial.print("PWM Value is: ");
  Serial.println(pwm);
  analogWrite(pinLed, pwm);
  delay(duration);

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 5; i++){
    dimLed(led, pwmValues[i], i*400);
  }
}
