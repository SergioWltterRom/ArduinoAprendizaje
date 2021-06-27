#include "Coche.h"
#include <Arduino.h>

static unsigned int Coches = 0;

Coche::Coche(){
  Nombre = 'n';
  Modelo = 'm';
  Marca = 'm';  
  Coches++;
}

Coche::Coche(char modelo, char marca){
  Nombre = 'n';
  Modelo = modelo;
  Marca = marca;  
  Coches++;
}

void Coche::cambioNombre(char nombre){
  Nombre = nombre;
  Serial.print("Nuevo nombre: ");
  Serial.println(Nombre);
}

char Coche::getModelo(){
  return Modelo;
}
char Coche::getMarca(){
  return Marca;
}

unsigned int cochesCont(){
  return Coches;
}
