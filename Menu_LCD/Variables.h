#include <LiquidMenu.h>
#include "Definiciones.h"

#define DIRECCION 0X27
#define FILAS 4
#define COLUM 20

LiquidCrystal_I2C lcd(DIRECCION, COLUM, FILAS);

byte menu[][];
