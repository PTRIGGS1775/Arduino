//int place1 = 2;
//int place2 = 3;
//int place3 = 4;
//int place4 = 5;
//int place5 = 6;
//int place6 = 7;
//int place7 = 8;
//int place8 = 9;
//The above can be simplified to creating an array that uses the pins
int ledPin[] = {
  9,8,7,6,5,4,3,2};
int maxCount = 256;       //this allows me to just count to 255
int delayInterval = 500;   //half second delay between light change

void setup() {
  //pinMode(place1, OUTPUT);
  //pinMode(place2, OUTPUT);
  //pinMode(place3, OUTPUT);
  //pinMode(place4, OUTPUT);
  //pinMode(place5, OUTPUT);
  //pinMode(place6, OUTPUT);
  //pinMode(place7, OUTPUT);
  //pinMode(place8, OUTPUT);
  //The above can be simplified by creating a for loop to set each pin as output to save time. You start at 0 because that is the first number on your list you created in ledPin https://www.w3schools.com/cpp/cpp_for_loop.asp
  for(int i = 0; i < 9; i++){
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  //Loop through each number between 0 and 255
  for(int counter = 0; counter < maxCount; counter++){
    //pass the count number to the displayBindary function below. Functions can be declared after.
    displayBinary(counter);
    delay(delayInterval);
  }
}

void displayBinary(byte numToShow){       //byte is a known variable in arduino. Check the man page. https://www.arduino.cc/reference/en/language/variables/data-types/byte/
  for(int i = 0; i < 8; i++){
    //Use the bitRead function and cycle through each bit of the binary number to see if it is a one or a zero. If it is a one then turn the LED on.
    if(bitRead(numToShow, i) == 1){
      digitalWrite(ledPin[i], HIGH);
      }
    else{
      digitalWrite(ledPin[i], LOW);
    }
  }
}
