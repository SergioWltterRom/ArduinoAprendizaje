#include <EEPROM.h>       //Leer la memoria eeprom

int eeDir;

void setup() {
  Serial.begin(9600);
  Serial.println("Lectura de datos pre escritura");
  for(int i = 0; i < EEPROM.length(); i++){
    int val;
    EEPROM.get(i, val);       // leer la variable
    Serial.print(val);
  }
  Serial.println();
  Serial.println("Espacio memoria EEPROM");
  Serial.println(EEPROM.length());
  Serial.println();
}

void loop() {

}
