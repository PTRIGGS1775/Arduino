int LED = 12; //pin12 on the HERO will be attached to our LED through a 220ohm resistor
int Switch1 = 2; //pin2 on the HERO will be attached to our switch

void setup() {
  //setup both an output AND an input on the HERO
  pinMode(LED, OUTPUT);
  pinMode(Switch1, INPUT);

}

void loop() {
  //we take actions based on the status of the input switch
  //this is a conditional test
  if (digitalRead(Switch1) == HIGH){
    digitalWrite(LED, HIGH); //turn LED on
  }
  else{
    digitalWrite(LED, LOW); //turn LED off
  }
}
