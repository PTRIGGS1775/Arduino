const int led = 5;

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
  dimLed(led, 100, 500);
  dimLed(led, 255, 1000);
  dimLed(led, 50, 100);
}
