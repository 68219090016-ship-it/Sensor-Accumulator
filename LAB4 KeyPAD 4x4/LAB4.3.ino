/*LAB 4.3 4x4 */
// https://app.cirkitdesigner.com/project/9b262b5a-d5e1-463d-aa01-3831ad01c7c3

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h> 
#define ledB 13



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
  pinMode(ledB,OUTPUT);
  digitalWrite(ledB,LOW);
  lcd.init();         
  lcd.backlight();    
  
  lcd.setCursor(0, 0);
  lcd.print("Key Pressed:");
}

void loop() {
 lcd.setCursor(0, 0);
 lcd.print("Key Pressed:");
 char key = keypad.getKey(); 

  if (key) { // If akey ispressed
  Serial.print("Key Pressed: ");
    Serial.println(key);


    if (key == '*') {
     input_password = "";
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Clear Password");
     delay(3000);
     lcd.clear();
    }

    else if (key == '#'){
        if(input_password == password_1){
            lcd.clear();
            lcd.print("Password OK");
            Serial.print("Password OK");
            digitalWrite(ledB,HIGH);   
            delay(3000);
            digitalWrite(ledB,LOW); 
        }
     input_password = "";
     lcd.clear();

    }
    else {
     input_password += key;
     lcd.setCursor(0, 1);
     lcd.print( input_password);
    }
    }
}
  
