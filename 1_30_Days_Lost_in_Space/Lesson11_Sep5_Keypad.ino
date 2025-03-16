#include <Key.h>
#include <Keypad.h>
 
 
const byte ROWS = 4;
const byte COLS = 4;

//Corresponds to row colum pins on the keypad itself.
byte rowPins[ROWS] = {5, 4, 3, 2}; //This is reversed because the rows start at the bottom not at the top.
byte colPins[COLS] = {6, 7, 8, 9}; //These remain in this order because colums still start from the left.

//This is an array of an array
//Characters are included in single quotations
char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},  // 1st row
  {'4', '5', '6', 'B'},  // 2nd row
  {'7', '8', '9', 'C'},  // 3rd row
  {'*', '0', '#', 'D'}   // 4th row
};

//We define our own instance of keypad. We set it as the keypad feature, takes a keymap with our buttons we defined before with the physical and logical definitions.
Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);
 
 
void setup() {
  Serial.begin(9600); // Begin monitoring via the serial monitor
}
 
void loop() {
  char result = myAwesomePad.getKey();  //getkey is a function that checks for the button you press
 
  if (result){                    // if a button is pressed, it means if result doesn't have a value then it equals 0, which means false, so it wont do anything until true.
    Serial.println(result);
  }
 
}
