#include "MenuLcd.h"

#define FREC1 311
#define FREC2 392
#define FREC3 466

/////   Entradas
#define BAUDIOS 9600
#define BTNDERECHA 2
#define BTNIZQUIERDA 3
#define BTNCENTRO 4

///   Variables

unsigned long tiempoPitido = 0;
bool tempPitido = false;
int tiempoBuzer = 0;

/////   Funciones
void iniciarEntradas(){
  pinMode(BTNDERECHA, INPUT_PULLUP);
  pinMode(BTNIZQUIERDA, INPUT_PULLUP);
  pinMode(BTNCENTRO, INPUT_PULLUP);
}

void iniciarSalidas(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZER, OUTPUT);
}

void inicializar(){
  Serial.begin(BAUDIOS);
}

void iniciarLCD(){
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("     BIENVENIDO");
  lcd.setCursor(0, 1);
  lcd.print("   SERGIO ROMERO");
  menu.init();
}

bool btnPulsado(byte boton){    //0 --> Btn Derecha, 1 --> Btn Izquierda, 2 --> Btn Centro
  bool resp = false;
  switch(boton){
    case 0:
      if(!digitalRead(BTNDERECHA))
        resp = true;
        //Serial.println("Boton Derecho pulsado");
      break;
    case 1:
      if(!digitalRead(BTNIZQUIERDA))
        Serial.println("Boton Izquierda pulsado");
      break;
    case 2:
      if(!digitalRead(BTNCENTRO))
        Serial.println("Boton Centro pulsado");
      break;
    default:
      Serial.println("Este boton no existe");
  }
  return resp;
}

void controlLed(byte led, byte luminusidad){  //1 --> Led1, 2 --> Led2, 3 --> Led3  
  switch(led){
    case 1:
      analogWrite(LED1, luminusidad);
      break;
    case 2:
      analogWrite(LED2, luminusidad);
      break;
    case 3:
      analogWrite(LED3, luminusidad);
      break;
    default:
      Serial.println("Este led no existe");      
  }  
}

void pitido(byte frec, int tP){
  tempPitido = true;
  switch(frec){
    case 1:
      tone(BUZER, FREC1);      
      break;
    case 2:
      tone(BUZER, FREC2);      
      break;
    case 3:
      tone(BUZER, FREC3);      
      break;
    default:
      Serial.println("Esta frecuencia no existe");
      tempPitido = false;
  }
  if(tempPitido){
    tiempoPitido = millis();
    tiempoBuzer = tP;
  }    
}

void focusAtachMenu(){
  /////Pantalla principal
  linea1.set_focusPosition(Position::LEFT);
  linea2.set_focusPosition(Position::LEFT);
  linea3.set_focusPosition(Position::LEFT);
  linea4.set_focusPosition(Position::LEFT);

  linea1.attach_function(1, fnLinea1);
  linea2.attach_function(1, fnLinea2);
  linea3.attach_function(1, fnLinea3);
  linea4.attach_function(1, fnLinea4);

  menu.add_screen(pantallaPrinc);

  /////Pantalla Led
  linea1_Led.set_focusPosition(Position::LEFT);
  linea2_Led.set_focusPosition(Position::LEFT);
  linea3_Led.set_focusPosition(Position::LEFT);

  linea1_Led.attach_function(1, fnLinea1_Led);
  linea2_Led.attach_function(1, fnLinea2_Led);
  linea3_Led.attach_function(1, fnLinea3_Led);

  menu.add_screen(pantallaLed);

  /////Pantalla Configuracion
  linea1_Confi.set_focusPosition(Position::LEFT);
  linea2_Confi.set_focusPosition(Position::LEFT);
  linea3_Confi.set_focusPosition(Position::LEFT);

  linea1_Confi.attach_function(1, fnLinea1_Confi);
  linea2_Confi.attach_function(1, fnLinea2_Confi);
  linea3_Confi.attach_function(1, fnLinea3_Confi);

  menu.add_screen(pantallaConfi);

  ///// Numero de filas
  pantallaPrinc.set_displayLineCount(4);
  pantallaLed.set_displayLineCount(4);
  pantallaConfi.set_displayLineCount(4);

  menu.set_focusedLine(0);
  menu.update();
}

void selectOpcion(){
    if(digitalRead(BTNCENTRO)){
      Serial.println("Boton central");
      pitido(FREC1, 300);
      menu.call_function(1);
      delay(500);
  }
}

void direccionOpcion(){
  if(digitalRead(BTNDERECHA) || digitalRead(BTNIZQUIERDA)){
    if(digitalRead(BTNDERECHA)){
        Serial.println("Boton derecha");
        pitido(FREC2, 100);
        menu.switch_focus(true);   ///Vamos hacia abajo
    }
    if(digitalRead(BTNIZQUIERDA)){
        Serial.println("Boton izquierda");
        pitido(FREC3, 100);
        menu.switch_focus(false);   ///Vamos hacia arriba
    }
    menu.update();
  }
}

///Apagar pitido

void apagarPitido(){
  if((millis() - tiempoPitido > tiempoBuzer)  && tempPitido){
  noTone(BUZER);
  tempPitido = false;
  }
}
//////////////
