#define LASER_PIN 2

void setup () {
  Serial.begin(115200);
  pinMode (LASER_PIN, OUTPUT);
}

void loop () {
  Serial.println("Laser on");
  digitalWrite (LASER_PIN, HIGH);
  delay (1000);
}
