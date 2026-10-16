#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int buttonPin = 7;
int count = 0;
int lastState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.begin(16, 2);
  showCount();
}

void loop() {
  int state = digitalRead(buttonPin);
  if (lastState == HIGH && state == LOW) {
    count = (count + 1) % 16;
    showCount();
    delay(50);
  }
  lastState = state;
}

void showCount() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Binary: ");
  for (int i = 3; i >= 0; i--) {
    lcd.print((count >> i) & 1);
  }
  lcd.setCursor(0, 1);
  lcd.print("Decimal: ");
  lcd.print(count);
}