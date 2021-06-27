#define Boton 2
#define Led 7

void setup() {
  pinMode(Boton, INPUT_PULLUP);
  pinMode(Led, OUTPUT);
}

bool estado;
bool anterior = HIGH;
bool led = LOW;

void loop() {
   estado = digitalRead(Boton);
  if(estado == LOW && anterior == HIGH){
    anterior = LOW;
    digitalWrite(Led, !led);
    } else if (estado == HIGH && anterior == LOW){
      anterior = HIGH;
      }

   
}
