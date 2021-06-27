#include <SoftwareSerial.h>

#define RX 10
#define TX 11
#define Boton 4
#define Led 7

SoftwareSerial mega(RX, TX);

void setup() {
  Serial.begin(9600);
  mega.begin(9600);
  pinMode(Led, OUTPUT);
  pinMode(Boton, INPUT_PULLUP);  
}

char dato = 's';

void loop() {
  if(mega.available()){
    dato = mega.read();
    }

  if(digitalRead(Boton)==LOW)
    mega.write('a');
  else
    mega.write('b');

  if(dato == 'a')
    digitalWrite(Led, HIGH);
  else if(dato == 'b')
    digitalWrite(Led, LOW);
}
