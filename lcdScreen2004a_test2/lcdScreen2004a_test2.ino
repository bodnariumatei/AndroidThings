// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int xPos, yPos;

byte ship[8] = {
  B00000,
  B00100,
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B11011,
};

void moveLeft(){

}


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.createChar(0, ship);
  lcd.setCursor(10, 2);
  xPos = 10;
  yPos = 2;
  lcd.write(byte(0));

  Serial.begin(9600);
}

void loop() {
  Serial.println("Direction");
  String direction = Serial.readString();
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}