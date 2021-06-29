#include "Variables.h"

////////    Pantalla Principal
LiquidLine linea1(1, 0, "Home");
LiquidLine linea2(1, 1, "Controlar Led 1");
LiquidLine linea3(1, 2, "Controlar Led 2");
LiquidLine linea4(1, 3, "Controlar Led 3");
LiquidLine linea5(1, 0, "Atras");
LiquidLine linea6(1, 1, "Controlar Todos Leds");
LiquidLine linea7(1, 2, "Cinfiguracion");

LiquidScreen pantalaPrinc(linea1, linea2, linea3, linea4, linea5, linea6, linea7);

/////////  Pantalla Control Led
LiquidLine linea1_Led(1, 0, "Atras");
LiquidLine linea2_Led(1, 1, "Encender");
LiquidLine linea3_Led(1, 2, "apagar");
