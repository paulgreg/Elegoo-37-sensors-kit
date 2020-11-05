#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

void setupOledScreen() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void printScreen(char* str) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.println(str);
  display.display();
}

// Inspired by https://randomnerdtutorials.com/esp8266-dht11dht22-temperature-and-humidity-web-server-with-arduino-ide/
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHTPIN 14
DHT dht(DHTPIN, DHT11);

void setup() {
  setupOledScreen();
  dht.begin();
}

float temperature = 0.0;
float humidity = 0.0;
char str[50];

void loop() {
  float newTemperature = dht.readTemperature(false);
  float newHumidity = dht.readHumidity();
  if(!isnan(newTemperature)) temperature = newTemperature;
  if(!isnan(newHumidity)) humidity = newHumidity;
  sprintf(str, "Temp: %2.1f\n\nHumi: %3.0f%%", temperature, humidity);
  printScreen(str);
  delay(100);
}
