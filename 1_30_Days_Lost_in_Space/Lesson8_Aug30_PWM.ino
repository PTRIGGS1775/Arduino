//While we can't change the voltage of a digital output, we can change the duration that it's on.
//This is referred to as pulse width modulation (PWM) and the digital pins capable of achieving this are marked with a "~"
int red = 11; //output pins for three LED colors
int green = 10;
int blue = 9;

void setup() {
  //set our pins to drive output to the LEDs
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void RGB_color(int red_value, int green_value, int blue_value){     //whatever you put in the parentheses in a function is considered as an input.
  //custom function to set three PWM color channels to any given mixture.
  analogWrite(red, red_value);
  analogWrite(green, green_value);
  analogWrite(blue, blue_value);
}

void loop() {
  //cycle through several different color settings that runs the RGB_color function
  RGB_color(125, 0, 0); //red
  delay(800);
  RGB_color(0, 125, 0); //green
  delay(800);
  RGB_color(0, 0, 125); //blue
  delay(800);
  RGB_color(64, 32, 0); //yello
  delay(800);
  RGB_color(125, 0, 125); //purple
  delay(800);
  RGB_color(125, 125, 125); //white
  delay(800);
}
