
void setup() {
  pinMode(13, OUTPUT);

}         //Importante para cargar el programa debemos pulsar el boton subir, rapidamente pulsar el boton rset del ardino y soltarlo justo cuando pasa de "compilando" a "subiendo"

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(20);

}
