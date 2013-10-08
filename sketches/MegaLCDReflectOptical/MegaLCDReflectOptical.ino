/*
  MegaLCDReflectOptical
  
  Test code for reading two reflective optical sensors in an
  Arduino Mega, displaying their values on an 16x2 LCD 
 */

#include <LiquidCrystal.h>

// LiquidCrystal (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(41, 39, 37, 35, 33, 31);

void setup() {
  //  LCD cols, lines
  lcd.begin(16, 2);
}

String rjust(int n) {
  char buff[10];
  sprintf(buff, "%4d", n);
  return String(buff);
}

void loop() {
  int value = analogRead(A0);
  //          col, line
  lcd.setCursor(0, 0);
  lcd.print(rjust(value));
  lcd.setCursor(7, 0);
  if (value >= 100) lcd.print("DETECT");
  else              lcd.print(". . . ");

  value = analogRead(A1);
  lcd.setCursor(0, 1);
  lcd.print(rjust(value));
  lcd.setCursor(7, 1);
  if (value >= 100) lcd.print("DETECT");
  else              lcd.print(". . . ");
}

