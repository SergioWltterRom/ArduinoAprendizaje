#define Led1 0
#define Led2 1

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
}

void loop() {
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, LOW);
  delay(500);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, HIGH);
  delay(500);
}
