#include <EEPROM.h>

struct Estructura{
  float campo1;
  byte campo2;
  char name[10];
  }; 

void setup() {
  Serial.begin(9600);
  int eeDir = 0;

  Estructura miEst;
  EEPROM.get(eeDir, miEst);       //Leemos la estructura de la EEPROM

  leerEstructura(miEst);

  eeDir += sizeof(Estructura);
    
  EEPROM.get(eeDir, miEst);

  leerEstructura(miEst);
}

void loop() {  
}

void leerEstructura(Estructura est){
  Serial.println("Lectura de estructura:");
  Serial.print("\t");
  Serial.println(est.campo1);
  Serial.print("\t");
  Serial.println(est.campo2);
  Serial.print("\t");
  Serial.println(est.name);
  Serial.println();
  }
