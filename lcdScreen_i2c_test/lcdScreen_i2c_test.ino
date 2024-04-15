#include <LCD_I2C.h>

LCD_I2C lcd(0x27);

void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello World!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
