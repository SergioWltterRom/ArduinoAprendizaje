#include "Variables.h"

////////    Pantalla Principal
LiquidLine linea1(1, 1, "Controlar Led 1");
LiquidLine linea2(1, 2, "Controlar Led 2");
LiquidLine linea3(1, 3, "Controlar Led 3");
LiquidLine linea4(1, 2, "Cinfiguracion");

LiquidScreen pantallaPrinc(linea1, linea2, linea3, linea4);

/////////  Pantalla Control Led
LiquidLine linea1_Led(1, 0, "Atras");
LiquidLine linea2_Led(1, 1, "Encender");
LiquidLine linea3_Led(1, 2, "apagar");

LiquidScreen pantallaLed(linea1_Led, linea2_Led, linea3_Led);

/////////  Pantalla Configuracion
LiquidLine linea1_Confi(1, 0, "Atras");
LiquidLine linea2_Confi(1, 1, "Apagar Pantalla");
LiquidLine linea3_Confi(1, 2, "Encender Pantalla");

LiquidScreen pantallaConfi(linea1_Confi, linea2_Confi, linea3_Confi);

LiquidMenu menu(lcd, pantallaPrinc, pantallaLed, pantallaConfi);
