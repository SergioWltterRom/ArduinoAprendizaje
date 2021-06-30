

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
  ///////  Fin Menu
}
