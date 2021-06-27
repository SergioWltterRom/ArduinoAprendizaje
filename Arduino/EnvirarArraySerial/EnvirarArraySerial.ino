byte datos[] = {72, 111, 108, 97};

void setup() {
  Serial.begin(9600);
  Serial.println("Enviar datos");

}

void loop() {
  //Serial.write(111);
  Serial.write(datos, sizeof(datos)/sizeof(byte));
  Serial.println(sizeof(datos)/sizeof(byte));
  delay(5000);
}
