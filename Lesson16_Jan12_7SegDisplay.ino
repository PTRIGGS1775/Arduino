//Include the 7-segment display library:
#include <TM1637Display.h>

//Define the display connections pins:
#define CLK 6
#define DIO 5

//Create display object of type TM1637Display:
TM1637Display myAwesomeDisplay = TM1637Display(CLK, DIO);

//Create array that turns all segments on:
const uint8_t all_on[] = {0xff, 0xff, 0xff, 0xff};

//Create array with everything off:
const uint8_t all_off[] = {0x00, 0x00, 0x00, 0x00};

// You can set the individual segments to spell digits, words or create other symbols
// by performing bitwise OR operations of the segments you need to turn on:
const uint8_t done[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

const uint8_t paul[] = {
  SEG_A | SEG_B | SEG_E | SEG_F | SEG_G,            //p
  SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G,    //a
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,            //u
  SEG_D | SEG_E | SEG_E | SEG_F                     //l
};

void setup() {
  // Clear the display:
  myAwesomeDisplay.clear();      //should set everything to dark.
  delay(1000);
}

void loop() {
  // Set the brightness must be always higher than zero to view stuff:
  myAwesomeDisplay.setBrightness(7);
  // All segments on:
  myAwesomeDisplay.setSegments(all_on);
  delay(2000);
  myAwesomeDisplay.clear();
  delay(1000);

  // demonstrate counter:
  int i;
  for (i = 0; i <= 69; i++) {
    myAwesomeDisplay.showNumberDec(i);  // this knows how to make decimal numbers because it's already a function showNumberDecimal.
    delay(100);
  }
  delay(2000);
  myAwesomeDisplay.clear();
  delay(1000);
  myAwesomeDisplay.showNumberDec(420);
  
  delay(2000);
  myAwesomeDisplay.clear();
  delay(1000);
  myAwesomeDisplay.setSegments(paul);
  while(1);  // Is code for true, so it just means true and after one pass, hang here forever...
}
