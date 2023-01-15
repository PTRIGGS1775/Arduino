//For creative day I'm looking to change the color of the RGB LED by how much light is in there.
int sensorPin = A0;   // select the *analog zero* input pin for probing the photoresistor
int sensorValue = 0;

int red = 11;  // these are our output pins for three LED colors
int green = 10;
int blue = 9;

void setup() {
  //Declare the RGB LED pins as outputs:
  //analogs don't need to be declared because they are only inputs
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
 
  // Start serial monitor to test photo resistor output
  //Serial.begin(9600);
}

void RGB_color(int red_value, int green_value, int blue_value)
 {
// custom function to set three PWM color channels to any given mixture. This sets the value of pulse for each pin.
// it returns NO numerical result (void)
 
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}

void loop() {
  //This is a test code to determine the values I want to go with.
  //Avg covered: 0
  //Avg with no light: 1-2
  //Avg with light: 18-19
  //Avg with intense light: >200
  //Serial.println(analogRead(sensorPin));
  //delay(200);
  
  // Now let's light the LED with the appropriate color...
  sensorValue = analogRead(sensorPin);     //You need to pass the sensor pin to a value that can be read and then changed otherwise it wont view the value.
  if (sensorValue == 0){
    RGB_color(125, 0, 0); // red
  }
  else if (sensorValue > 0 && sensorValue < 5){
    RGB_color(125, 80, 0); // yellow-ish
  }
  else if (sensorValue > 6 && sensorValue <150) {
    RGB_color(0, 125, 125); // blue-ish
  }
  else if (sensorValue > 151) {
    RGB_color(125, 125, 125); // white
  }
  delay(100);
  sensorValue = 0;  //You need to zero out the value for a fresh restart.
}
