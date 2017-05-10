// Programa : Het Kabinet Bezoekersteller
// Autor : PD5WL - Wijnand Laros
// Copywrite : Larosnet - Wijnand Laros

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
const int buttonPin = 3;
const int resetPin = 4;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;
int counter = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(resetPin, INPUT);
  lcd.begin (16,2);

// Backlight aan
  lcd.setBacklight(HIGH);

// Start scherm
    lcd.setCursor(0,0);
    lcd.print("  Het  Kabinet  ");
    lcd.setCursor(0,1);
    lcd.print("By Wijnand Laros");
    delay(3000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tikken: 0");
    lcd.setCursor(0,1);
    lcd.print("Bezoekers: 0");
}

void loop() {

// Start meetingen    
  boolean pressed = debounce();
  if (pressed == true) {
    counter++;
    lcd.setCursor(0,0);
    lcd.print("Tikken: ");
    lcd.setCursor(8,0);
    lcd.print(counter);
    lcd.setCursor(0,1);
    lcd.print("Bezoekers: ");
    lcd.setCursor(11,1);
    lcd.print(counter/2);
  }
}

boolean debounce() {
  boolean retVal = false;
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        retVal = true;
      }
    }
  }
  lastButtonState = reading;
  return retVal;
}
