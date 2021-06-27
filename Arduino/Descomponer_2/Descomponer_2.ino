#include"Definiciones.h"
#include"Variables.h"
//#include"Clases.h"


void setup() {
  inicializar();
  Serial.print("Define Hola = ");
  Serial.println(HOLA);

  Serial.print("\nRectangulo 1 tiene:\nArea = ");
  Serial.println(rect1.Area());
  Serial.print("Perimetro = ");
  Serial.println(rect1.Perimetro());

  Serial.print("Rectangulo 2 tiene:\nArea = ");
  Serial.println(rect2.Area());
  Serial.print("Perimetro = ");
  Serial.println(rect2.Perimetro());

  Serial.print("Triangulo 1 tiene:\nArea = ");
  Serial.println(tria1.Area());
  Serial.print("Perimetro = ");
  Serial.println(tria1.Perimetro());

  Serial.print("Triangulo 2 tiene:\nArea = ");
  Serial.println(tria2.Area());
  Serial.print("Perimetro = ");
  Serial.println(tria2.Perimetro());

  Serial.print("Numero de cuadrados = ");
  Serial.println(NumCuadrados());
  Serial.print("Numero de rectangulos = ");
  Serial.println(NumRectangulos());
  Serial.print("Numero de triangulos isosceles = ");
  Serial.println(NumTrigulosIsosceles());
  Serial.print("Numero de triangulos = ");
  Serial.println(NumTrigulos());
}

void loop() {

//  if(millis() - tiempo > TIEMPO){
//    tiempo = millis();
//    ledEstado = invertirLeds(ledEstado);
//    Serial.print("Contador de inversiones del led: ");
//    Serial.println(++contador);
//    
//    Serial.print("Definiciones Globales: ");
//    Serial.println(TEMP1);
//    Serial.println(TEMP2);
//    Serial.println(HUMEDADEXT);
//    Serial.println(HUMEDADINT);
//  }  

//  if(boton_Presionado(false))
//    Serial.println("Boton 1 Presionado");
//  else
//    Serial.println("Boton 1 NO presionado");
//
//  if(boton_Presionado(true))
//    Serial.println("Boton 2 Presionado");
//  else
//    Serial.println("Boton 2 NO presionado");
}
