#include <EEPROM.h>

struct Estructura{
  float campo1;
  byte campo2;
  char name[10];
  }; 

void setup() {
  Serial.begin(9600);
  int eeDir = 0;
  
  Estructura miEst = {
  3.14f,
  65,
  "Hola amigos"
  };
  
  eeDir += sizeof(Estructura);
  EEPROM.put(eeDir, miEst);
  
}

void loop() {  
}
