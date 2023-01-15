int sensorPin = A0; //select the *analog zero* input pin for probing the photoresistor
int onboardLED = 13; //select the pin for the HERO's built-in LED
int sensorValue = 0; //variable that we'll use to store the value reading from the sensor

void setup() {
  //begining code to teach serial
  Serial.begin(9600);

  //begin code for last portion of class
  pinMode(onboardLED, OUTPUT);
}

void loop() {
  //begining code to teach serial
  //Serial.println("Hello Earthling!");
  //delay(500);
  //Serial.println("Take me to your leader!");
  //delay(1000);
  
  //Read the analog sensor value and send it to serial, you'll need A0 connected between photo resistor and resistor.
  //sensorValue = analogRead(sensorPin);
  //Serial.println(sensorValue);
  //delay(500);

  //Pulse the builtin LED for a time determined by the sensor
  sensorValue = analogRead(sensorPin);
  digitalWrite(onboardLED, HIGH);
  delay(sensorValue);
  digitalWrite(onboardLED, LOW);
  delay(sensorValue);

  Serial.println(sensorValue);
  delay(sensorValue);
}
