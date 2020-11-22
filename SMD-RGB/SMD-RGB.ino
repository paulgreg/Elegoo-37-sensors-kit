#define RED 2
#define GREEN 0
#define BLUE 4

void setup() {
  Serial.begin(115200);
  delay(500);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  int redValue = random(255);
  int greenValue = random(255);
  int blueValue = random(255);
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue);
  Serial.printf("red: %i - green: %i - blue %i\n", redValue, greenValue, blueValue);
  delay(1000);
}
