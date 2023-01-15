int LED1 = 10; //pins 10-12 are LED outputs on HERO
int LED2 = 11;
int LED3 = 12;
int Switch1 = 2; //pins 2-4 are switch inputs on HERO
int Switch2 = 3;
int Switch3 = 4;

void setup(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  pinMode(Switch3, INPUT);
}

void loop(){
  //continuously check the status of voltage coming from input and set LEDs
  if (digitalRead(Switch1) == HIGH){
    digitalWrite(LED1, HIGH); //turn on LED
  }
  else{
    digitalWrite(LED1, LOW); //turn off LED 
  }
  if (digitalRead(Switch2) == HIGH){
    digitalWrite(LED2, HIGH); //turn on LED
  }
  else{
    digitalWrite(LED2, LOW); //turn off LED 
  }
  if (digitalRead(Switch3) == HIGH){
    digitalWrite(LED3, HIGH); //turn on LED
  }
  else{
    digitalWrite(LED3, LOW); //turn off LED 
  }
}
