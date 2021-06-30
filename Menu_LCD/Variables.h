#include "Definiciones.h"
#include <LiquidCrystal_I2C.h>
#include <LiquidMenu.h>
//#include "Arduino.h"

#define DIRECCION 0X27
#define FILAS 4
#define COLUM 16

/////   Salidas
#define LED1 5
#define LED2 6
#define LED3 9
#define BUZER 10

LiquidCrystal_I2C lcd(DIRECCION, COLUM, FILAS);
