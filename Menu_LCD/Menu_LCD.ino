

void setup() {
  inicializar();  
  iniciarEntradas();
  iniciarSalidas();
  iniciarLCD();  
}

void loop() {
  ///////  Menu
  apagarPitido();
  if(btnPulsado(0))
    pitido(3, 250);
  do{
    
  }while(0);
  ///////  Fin Menu
}
