const int button = 4; 
const int led = 5;
int photoSense = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int lightLevel = analogRead(photoSense);
  Serial.println(lightLevel);
  Serial.println(digitalRead(button));

  if (digitalRead(button) == LOW){
    if (lightLevel < 600){
      digitalWrite(led, HIGH);
    }
    else{
      digitalWrite(led, LOW);
    }
  }
  else{
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
  }
}
