/*
  HotWheelsLauncher
  
  Test code for reading two reflective optical sensors in an
  Arduino Mega, displaying their values on an 16x2 LCD 
 */

#include <LiquidCrystal.h>

// LiquidCrystal (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(41, 39, 37, 35, 33, 31);

int solenoide = 2;
int disparou = 0;

void setup() {
  //  LCD cols, lines
  lcd.begin(16, 2);
  pinMode(solenoide, OUTPUT);
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
  if (value >= 250) {
    lcd.print("DETECT");
    if (! disparou) {
      digitalWrite(solenoide, HIGH);
      delay(1000);
      digitalWrite(solenoide, LOW);
      disparou = 1;   
    } 
  }
  else lcd.print(". . . ");
  value = analogRead(A1);
  if (value >= 250) {
    lcd.print("DETECT");
  }
  else lcd.print(". . . ");
}

