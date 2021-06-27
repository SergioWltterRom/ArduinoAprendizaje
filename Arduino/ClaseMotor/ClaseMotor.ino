#include "Motor.h"

Motor motor1(true);
Motor motor2(false);
Motor motor3(true);

void setup() {
  Serial.begin(9600);
  
  motor1.setCV(140);
  motor1.setPeso(300);

  motor2.setCV(180);
  motor2.setPeso(288);

  motor3.setCV(155);
  motor3.setPeso(310);

  int ventas = VentasTotal();   /// Ahora si :)
  Serial.println(ventas);
}

void loop() {
  // put your main code here, to run repeatedly:

}
