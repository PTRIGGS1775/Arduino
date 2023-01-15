/*
There is a lot of code below, I started with the video lesson then modified the circuit board to include LEDs 
*/

int sensorPin = A0; //select the *analog zero* input pin for probing the photoresistor
int onboardLED = 13; //select the pin for the HERO's built-in LED
int sensorValue = 0; //variable that we'll use to store the value reading from the sensor

//We used unsigned int because integers can only go up to 32000 (Negative or Positive) based on binary allotment, but unsigned means we can go up to 64000 because we remove the (-)/(+) bit denoter.
unsigned int batteryCapacity = 50000; 
unsigned int batteryLevel = 0;
double PercentFull;
//unsigned int ticks = 0;
//unsigned int wait = 100;

//The “time” column will be incorrect after 6.5 seconds because “ticks” overflows, then “ticks” resets to “64” and starts incrementing in increments of 100 until “% charge” changes to “Full” 
//(when “batterylevel” reaches 50000). Again, The easy fix is change the data type of “ticks” and “wait” to “double” instead of “Unsigned Integer”. 
//As revealed in the video lesson, double can handle much larger numbers. Both ticks and wait have to be modified so there isn't a type mismatch when one operates on the other
double ticks = 0;
double wait = 100;

//BEGIN ADDITION of LED reader code.
int ledPin2 = 2;
int ledPin3 = 3;
int ledPin4 = 4;
int ledPin5 = 5;


void setup() {
  //setup code
  Serial.begin(9600);
  pinMode(onboardLED, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin); //tells hero to read the value from the sensor, and assign to sensorValue
  batteryLevel += sensorValue; //This adds the current read of the analog device to a variable called batteryLevel with every loop
  ticks += wait; //This keeps track of elapsed time with every loop

  if(batteryLevel >= batteryCapacity){
    Serial.print(ticks);
    Serial.print("ms    ");
    Serial.println("FULLY CHARGED");
    batteryLevel = batteryCapacity; //Prevent integer from continuing to increase
    ticks = 0;
    //delay(20000); //long pause. (Long pause was listed in the instructions, but I wonder why they didn't use break.
    //Turn on all LEDs
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin5, HIGH);
    //To exit the code you'll need to add the exit command, but in order to exit gracefully I recommend adding in a delay of some value to give the arduino time to run the code listed before exiting.
    delay(2000);
    exit(0);  
  }

  else{
    PrintBatteryPercentage();
    //Below is additional code I wrote to light up the LEDs
    if(batteryLevel < (.33 * batteryCapacity)){
      digitalWrite(ledPin2, HIGH);
    }
    else if(batteryLevel < (.66 * batteryCapacity)){
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
    }
    else if(batteryLevel < (.99 * batteryCapacity)){
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, HIGH);
    }
  }
  
  delay(wait); //using wait as a delayed variable allows us to sync the wait with the accurate printed time to charge
}

void PrintBatteryPercentage(){
  //This code prints all of the following on one line, just Serial.print keeps it all on the same line Serial.println returns the line when done.
  //Print the elapsed time
  Serial.print(ticks);
  Serial.print("ms    charge at ");

  //conver the integers to decimal numbers, divide them and print...
  PercentFull=100*((double)batteryLevel / (double)batteryCapacity);
  Serial.print(PercentFull);

  //Print percent character at the end and line return
  Serial.println("%");
}
