#include "Coche.h"

Coche coche1;
Coche coche2('X', 'T');
Coche coche3('S', 'F');
Coche coche4('C', 'M');

void setup() {
  Serial.begin(9600);
  Serial.println(coche1.getModelo());
  Serial.println(coche1.getMarca());
  Serial.println(coche2.getModelo());
  Serial.println(coche2.getMarca());
  Serial.print("Toal de coches ");
  Serial.println(cochesCont());  
}

void loop() {
  // put your main code here, to run repeatedly:

}
