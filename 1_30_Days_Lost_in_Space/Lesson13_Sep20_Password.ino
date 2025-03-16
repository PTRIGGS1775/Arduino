#include <Key.h>
#include <Keypad.h>
 
 
const byte ROWS = 4;
const byte COLS = 4;
const byte PassLength = 4;  // passwords will be 4 characters long
char currentPassword[PassLength] = {'0','0','0','0'}; // default before setting. Adding the [PassLength] initializes the array before setting.
 
char buttons[ROWS][COLS] = {
  {'1', '2', '3', 'A'},  // 1st row
  {'4', '5', '6', 'B'},  // 2nd row
  {'7', '8', '9', 'C'},  // 3rd row
  {'*', '0', '#', 'D'}   // 4th row
};
 
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {6, 7, 12, 13};
 
Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS); 
//  custom function to process a login attempt *******************************
 
int unlockMode(){
    char result ;
   
    Serial.println("Unlock Mode: Type Password to continue");
    delay(500);
   
    for(int i = 0; i < PassLength; i++) {
       while(!(result = myAwesomePad.getKey())) {
         // wait indefinitely for keypad input of any kind
       }
       if(currentPassword[i] != result){     // a wrong key was pressed
          Serial.println("WRONG PASSWORD");
          Serial.println(result);
          return -1;                    //  -1 means failed -- return immediately
       }
       Serial.print("*");  // print a phantom character for a successful keystroke
    }  //  done after 4 characters are accepted
   
    Serial.println("");
    Serial.println("Device Successfully Unlocked!");
    return 0;           //  0 means succeeded
}
//  ************************************************************************
 
void setup() {
  Serial.begin(9600); // Begin monitoring via the serial monitor
  delay(2000);
  Serial.println("Press * to set a new password.");
  Serial.println("Press # to access the system with the existing one.");
}
 
void loop() {
  char result = myAwesomePad.getKey();
 
 
   if (result == '*'){           // choice to change password
    int access = unlockMode();  //This calls the unlockMode functions and returns the result into a variable called access. 
                                //I did not know that you could just call a function in and equation.
   
    if(access < 0) {
      Serial.println("Access Denied. Cannot change password without knowing the previous or default.");
    }
    else {
      Serial.println("Welcome, authorized user. Please Enter a new password: ");
      delay(500);

      //The below for loop runs for 4 iterations, it has a nested while loop waiting for an entry, when the while loop exit it dumps result and iterates the counter.
      for(int i = 0; i < PassLength; i++) {
        while(!(result = myAwesomePad.getKey())) {
        // wait indefinitely for keypad input of any kind, the "!" negates the false nature of no press meaning its always true while not being pressed.
        //When nothing is pressed, result = 0, or false.
        //While continues to run while it's true, and exits on a false condition.
        }
   
        currentPassword[i] = result; //because currentPassword is an array, this sets the value of the array with the result during the iteration.
        Serial.print("*");    // print a phantom character for a successful keystroke
      }   //  done after 4 characters are accepted
     
      Serial.println("");
      Serial.println("Password Successfully Changed!");
    }
  }
 
  else if (result == '#') {           // choice to access system with current password
    int access = unlockMode();
    if(access < 0) {
      Serial.println("Password error. Access Denied.");
    }
    else {
      Serial.println("Welcome, authorized user. You may now begin using the system.");
    }
  }
 
}
