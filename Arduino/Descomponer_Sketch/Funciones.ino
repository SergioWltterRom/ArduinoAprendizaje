#include "Menu.h"

bool esPar(int n){
  Serial.print("Es ");
  Serial.print(n);
  Serial.print(" un numero par? ");
  if(n%2 == 0)
    return true;
  else
    return false;
}


///// Menu2

#if Menu2

void mensaje(){
  Serial.println("Mensaje con menu 2 verdadero");
}

void aviso(){
  Serial.println("Aviso con menu 2 verdadero");
}
#else

void mensaje(){
  Serial.println("Mensaje con menu 2 falso");
}

void aviso(){
  Serial.println("Aviso con menu 2 falso");
}

#endif
