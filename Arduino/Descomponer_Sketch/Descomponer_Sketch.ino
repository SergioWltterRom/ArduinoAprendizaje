#include "Definiciones.h"

#define Global1 23
#define Global2 12

void setup() {
  Serial.begin(9600);

  Serial.println(Global1);
  Serial.println(Global2);
  miFuncion();
  Serial.println(esPar(114)?"Si":"No");

  Serial.println(p);
  Serial.println(a++);
  Serial.println(CTE1);
  Serial.println(CTE2);
  Serial.println(a);

  mensaje();
  aviso();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void miFuncion(){
  Serial.println("miFuncion");
}
