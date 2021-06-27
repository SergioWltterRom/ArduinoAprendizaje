#include"Clases.h"
#include<Math.h>

static unsigned int numCuadrados = 0;
static unsigned int numRectangulos = 0;
static unsigned int numTrigulosIsosceles = 0;
static unsigned int numTrigulos = 0;

///// Rectangulo
Rectangulo::Rectangulo(float tam){
  Base = tam;
  Altura = tam;
  numCuadrados++;
}
Rectangulo::Rectangulo(float base, float altura){
  Base = base;
  Altura = altura;
  (base == altura) ? numCuadrados++ : numRectangulos++;
}

float Rectangulo::Area(){
  return Base * Altura;
}
float Rectangulo::Perimetro(){
  return 2 * Base + 2 * Altura;
}

///// Triangulo
Triangulo::Triangulo(float tam){
  Base = tam;
  Altura = tam;
  numTrigulosIsosceles++;
}
Triangulo::Triangulo(float base, float altura){
  Base = base;
  Altura = altura;
  (Base == Altura) ? numTrigulosIsosceles++ : numTrigulos++;
}

float Triangulo::Area(){
  return (Base * Altura) / 2;
}
float Triangulo::Perimetro(){
  return Base + 2 * sqrt(pow(Altura, 2) + pow(Base, 2));
}

////  Funciones Clases

unsigned int NumCuadrados(){
  return numCuadrados;
}
unsigned int NumRectangulos(){
  return numRectangulos;
}
unsigned int NumTrigulosIsosceles(){
  return numTrigulosIsosceles;
}
unsigned int NumTrigulos(){
  return numTrigulos;
}
