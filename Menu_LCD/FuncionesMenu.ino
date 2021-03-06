#include "MenuLcd.h"

byte ledSeleccionado = 0;

//////  Pantalla principal

void fnLinea1(){
  Serial.println("Estoy en funcion linea 2");
  menu.change_screen(2);
  menu.set_focusedLine(0);
  ledSeleccionado = 1;
}

void fnLinea2(){
  Serial.println("Estoy en funcion linea 3");
  menu.change_screen(2);
  menu.set_focusedLine(0);
  ledSeleccionado = 2;
}

void fnLinea3(){
  Serial.println("Estoy en funcion linea 4");
  menu.change_screen(2);
  menu.set_focusedLine(0);
  ledSeleccionado = 3;
}

void fnLinea4(){
  Serial.println("Estoy en funcion linea 7");
  menu.change_screen(3);
  menu.set_focusedLine(0);
}

//////  Pantalla Led
void fnLinea1_Led(){
  Serial.println("Estoy en funcion linea 1 de led");
  menu.change_screen(1);
  menu.set_focusedLine(0);
}

void fnLinea2_Led(){
  Serial.println("Estoy en funcion linea 2 de led");
  controlaLed(HIGH);
}

void fnLinea3_Led(){
  Serial.println("Estoy en funcion linea 3 de led");
  controlaLed(LOW);
}

//////  Pantalla Configuracion
void fnLinea1_Confi(){
  Serial.println("Estoy en funcion linea 1 de Configuracion");
}

void fnLinea2_Confi(){
  Serial.println("Estoy en funcion linea 2 de Configuracion");
}

void fnLinea3_Confi(){
  Serial.println("Estoy en funcion linea 3 de Configuracion");
  menu.change_screen(1);
  menu.set_focusedLine(0);
}

void controlaLed(bool s){
  switch(ledSeleccionado){
    case 0:
    digitalWrite(LED1, s);
    digitalWrite(LED2, s);
    digitalWrite(LED3, s);
    break;
    case 1:
    digitalWrite(LED1, s);
    break;
    case 2:
    digitalWrite(LED2, s);
    break;
    case 3:
    digitalWrite(LED3, s);
    break;
  }
}

void menuAtras(){
  menu.change_screen(1);
  menu.set_focusedLine(0);
}
