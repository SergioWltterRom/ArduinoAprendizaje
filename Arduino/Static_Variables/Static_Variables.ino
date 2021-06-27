

void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.print("Contador: ");
  Serial.println(incrementar());
  delay(2000);
}
