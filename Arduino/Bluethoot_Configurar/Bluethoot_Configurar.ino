#include <SoftwareSerial.h>

#define Led 13

SoftwareSerial BT(10,11);

char dato;

void setup() {
  Serial.begin(9600);
  Serial.println("Listo");
  BT.begin(9600);
  pinMode(Led, OUTPUT);
}

void loop() {
  if(BT.available()){
    dato = BT.read();
    Serial.println(dato);

    if(dato == '1')
      digitalWrite(Led, HIGH);

      if(dato == '2')
      digitalWrite(Led, LOW);
  }

  if(Serial.available())
    BT.write(Serial.read());

}
