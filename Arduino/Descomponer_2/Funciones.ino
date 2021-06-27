
#define BAUDIOS 9600
#define LED1 13
#define LED2 3

#define BOTON1 4
#define BOTON2 5

//////////  Funciones  ///////////

void inicializar(){
  Serial.begin(BAUDIOS);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BOTON1, INPUT_PULLUP);
  pinMode(BOTON2, INPUT_PULLUP);
}

bool invertirLeds(bool led){
  bool ledInv = !led;
  digitalWrite(LED1, ledInv);
  digitalWrite(LED2, !ledInv);
  return ledInv;
}

bool boton_Presionado(bool boton){    //false --> boton 1 y true --> boton 2
  bool boton1 = digitalRead(BOTON1)?LOW:HIGH;
  bool boton2 = digitalRead(BOTON2)?LOW:HIGH;
  bool resp = boton?boton2:boton1;
  return resp;
}
