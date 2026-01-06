/*LAB 4.4 4x4 */
// https://app.cirkitdesigner.com/project/27ae0994-fd71-4b06-b25b-e34a51cd747b 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h> 

#define ledB 13      
#define Sol_pin 8 

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

String input_password = "";
const String password_1 = "1234";

void setup() {
  Serial.begin(9600);
  
  pinMode(ledB, OUTPUT);
  pinMode(Sol_pin, OUTPUT);    
  digitalWrite(Sol_pin, 0);  
  
  lcd.init();         
  lcd.backlight();    
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey(); 

  if (key) { // If akey ispressed
    Serial.print("Key Pressed: ");
    Serial.println(key);

    if (key == '*') {
      input_password = "";
      lcd.clear();
      lcd.print("Clear Password");
      delay(500);
      lcd.clear();
      lcd.print("Enter Password:");
    }
    else if (key == '#') {
      if (input_password == password_1) {
        lcd.clear();
        lcd.print("Password OK");
        digitalWrite(ledB, 1);
        digitalWrite(Sol_pin,1);  
        delay(2000); 
        digitalWrite(ledB, 0);
        digitalWrite(Sol_pin, 0); 
      } else {
        lcd.clear();
        lcd.print("Wrong Password!");
        delay(1000);
      }
      input_password = ""; 
      lcd.clear();
      lcd.print("Enter Password:");
    }
    else {
      
      input_password += key;
      lcd.setCursor(0, 1);
      lcd.print(input_password); 
    }
  }
}
