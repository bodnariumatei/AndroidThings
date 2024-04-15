// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte separator[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
};


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.setCursor(1, 0);
  lcd.print("Trafic");

  lcd.createChar(0, separator);
  for(int i=0;i<4;i++){
    lcd.setCursor(10, i);
    lcd.write(byte(0));
  }

  lcd.setCursor(12, 0);
  lcd.print("Pietoni");
}

void loop() {
  lcd.setCursor(2, 2);
  lcd.print("verde");
  lcd.setCursor(13, 2);
  lcd.print("rosu");
  
  delay(1000);

  lcd.setCursor(2, 2);
  lcd.print("     ");
  lcd.setCursor(13, 2);
  lcd.print("    ");

  delay(500);
  
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}