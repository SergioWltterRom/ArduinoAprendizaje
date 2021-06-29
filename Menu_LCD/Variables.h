#include "Definiciones.h"
#include <LiquidCrystal_I2C.h>
//#include <LiquidMenu.h>

#define DIRECCION 0X27
#define FILAS 4
#define COLUM 20

LiquidCrystal_I2C lcd(DIRECCION, COLUM, FILAS);
