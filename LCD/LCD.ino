// Trying LCD display with an ESP8266
// more informations on connections here : http://electroniqueamateur.blogspot.com/2018/11/esp8266-et-afficheur-lcd-16-x-2.html
#include <LiquidCrystal.h>

const int pinRS = 4;      // pin 4 (RS) connected to esp8266 GPIO04
const int pinEnable = 5;  // pin 6 (Enable) connected to esp8266 GPIO05
const int pinD4 = 12;     // pin 11 (D4) connected to esp8266 GPIO12
const int pinD5 = 13;     // pin 12 (D5) connected to esp8266 GPIO13
const int pinD6 = 14;     // pin 13 (D6) connected to esp8266 GPIO14
const int pinD7 = 15;     // pin 14 (D7) connected to esp8266 GPIO15

LiquidCrystal lcd(pinRS, pinEnable, pinD4, pinD5, pinD6, pinD7);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello Sensor Kit");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
  delay(1000);
}
