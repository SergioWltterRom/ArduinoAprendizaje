#include <SoftwareSerial.h>

#define RX 10
#define TX 11
#define Boton 4
#define Led 7

SoftwareSerial uno(RX, TX);

void setup() {
  Serial.begin(9600);
  uno.begin(9600);
  pinMode(Led, OUTPUT);
  pinMode(Boton, INPUT_PULLUP);
}

char dato = 's';

void loop() {
  if(uno.available()){
    dato = uno.read();
    }

  if(digitalRead(Boton)==LOW)
    uno.write('a');
  else
    uno.write('b');

  if(dato == 'a')
    digitalWrite(Led, HIGH);
  else if(dato == 'b')
    digitalWrite(Led, LOW);
}
