
/*LAB 4.2 4x4 */
// https://app.cirkitdesigner.com/project/d6308a5c-9c0b-4946-84bb-84e54b3e16a2

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include <Keypad.h> 



LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {12, 11, 10, 9}; 
byte colPins[COLS] = {7, 6, 5, 4}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup() {
  Serial.begin(9600);
  
  // Initialize the LCD
  lcd.init();         
  lcd.backlight();    
  
  lcd.setCursor(0, 0);
  lcd.print("Key Pressed:");
}

void loop() {
 lcd.setCursor(0, 0);
 lcd.print("Key Pressed:");
  char key = keypad.getKey(); // Get the key pressed

  if (key) { // If akey ispressed
    
    lcd.setCursor(0, 1);
    lcd.print(key); 
    Serial.print("Key Pressed: ");
    Serial.println(key);
  }
}
