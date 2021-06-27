struct mensajeMovimientoServo
{
   int servoPin;
   int posicion;
   float intervalo;
};
 
struct mensajeMovimientoServo msj;
 
void enviarEstructura(byte *estructura, int tamano)
{
    Serial.write(estructura, tamano);
}
 
void setup()
{
  Serial.begin(9600);
  
  msj.servoPin = 10;
  msj.posicion = 1200;
  msj.intervalo = 2.5;  
 
  enviarEstructura((byte*)&msj, sizeof(msj));
}
 
void loop() 
{
}
