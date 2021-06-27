#include "Motor.h"

static int Ventas = 0;

Motor::Motor(bool funciona){  
  Funciona = funciona;   
  Ventas++;
}

void Motor::setCV(int cv){
  Cv = cv;
}

void Motor::setPeso(int peso){
  Peso = peso;
}

//int Motor::getVentas(){
//  return Ventas;
//}

int VentasTotal(){
  return Ventas;
}
