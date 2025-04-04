int sensorPin = A0;   // select the *analog zero* input pin for probing the photoresistor
int sensorValue = 0;  // variable that we'll use to store the value reading from the sensor
 
int red = 11;  // these are our output pins for three LED colors
int green = 10;
int blue = 9;
 
double batteryCapacity = 50000;
double batteryLevel = 0;
double ticks = 0;
double wait = 100;
double PercentFull;
 
//******************************************
 
void setup() {
  // Declare the RGB LED pins as outputs:
  //analogs don't need to be declared because they are only inputs
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
 
  // Start serial monitor
  Serial.begin(9600);
}
 
//******************************************
 
void RGB_color(int red_value, int green_value, int blue_value)
 {
// custom function to set three PWM color channels to any given mixture
// it returns NO numerical result (void)
 
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}
 
//******************************************
 
 double getBatteryPercentage() {
// custom function calculates battery charge percentage
// and returns the result as a double precision number
 
  return (((double)batteryLevel / (double)batteryCapacity)*100);
 
}
 
//******************************************
 
void ShowBatteryPercentage() {
  //  send battery results to both serial and LED outputs
   //  calculate the charge percentage with a custom function...
  PercentFull=getBatteryPercentage();
 
// print the elasped time
  Serial.print(ticks);
  Serial.print(" ms    charge at ");
// print the percent charge
  Serial.print(PercentFull);
// print a percent character and line return...
  Serial.println("%");
 
// Now let's light the LED with the appropriate color...
 
  if (PercentFull > 0 && PercentFull <= 25)
  {
    RGB_color(125, 0, 0); // red
  }
  else if (PercentFull > 25 && PercentFull <= 50){
    RGB_color(125, 80, 0); // yellow-ish
  }
  else if (PercentFull > 50 && PercentFull <= 75) {
    RGB_color(0, 125, 125); // blue-ish
  }
  else if (PercentFull > 75 && PercentFull < 100) {
    RGB_color(125, 125, 125); // white
  }
 
 
}
 
//******************************************
 
void loop() {
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  batteryLevel += sensorValue;
  ticks += wait;
 
  if(batteryLevel >= batteryCapacity) {
    Serial.print(ticks);
    Serial.print(" ms     ");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity; // to prevent integer from continuing to increase
    ticks = 0;  //resets the battery charge
    RGB_color(0, 125, 0); // Green for charging complete
    delay(20000);      // long pause
  }
  else {
    ShowBatteryPercentage();
  }
 
  delay(wait);
}
