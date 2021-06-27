

void setup() {
  Serial.begin(9600);
  Serial.println(devolverFrase());
}

void loop() {
  // put your main code here, to run repeatedly:

}

String devolverFrase(){
  return "Hola que tal estas?";
}
