#include "Variables.h"
#include"Clases.h"

#define FREC1 311
#define FREC2 392
#define FREC3 466

/////   Entradas
#define BAUDIOS 9600
#define BTNDERECHA 2
#define BTNIZQUIERDA 3
#define BTNCENTRO 4

/////   Salidas
#define LED1 5
#define LED2 6
#define LED3 9
#define BUZER 10

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

///Apagar pitido

void apagarPitido(){
  if((millis() - tiempoPitido > tiempoBuzer)  && tempPitido){
  noTone(BUZER);
  tempPitido = false;
  }
}
//////////////
