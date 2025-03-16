int light = 12; //HERO board pin 12

void setup() {
  //initialize the digital pin, set its value to low (0 volts)
  pinMode(light, OUTPUT);
  digitalWrite(light, LOW);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(light, LOW);
  delay(2000);
  digitalWrite(light, HIGH);
  delay(1000);
}
