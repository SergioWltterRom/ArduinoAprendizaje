#include "Variables.h"

void setup() {
  iniciarLCD();
  inicializar();  
  iniciarEntradas();
  iniciarSalidas();
  focusAtachMenu();    
}

void loop() {
  ///////  Menu
  apagarPitido();
  selectOpcion();
  direccionOpcion();
  ///////  Fin Menu
}
