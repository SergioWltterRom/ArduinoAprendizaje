#define PIN 2
#define Led 7
#define Interrumpir 10

volatile bool estado = LOW;

void setup() {
  pinMode(Interrumpir, OUTPUT);
   pinMode(Led, OUTPUT);
   pinMode(PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN), parpadeo, RISING);

}

void loop() {
   digitalWrite(Interrumpir, HIGH);
   delay(150);
   digitalWrite(Interrumpir, LOW);
   delay(150);

}

void parpadeo(){
  estado = !estado;
  digitalWrite(Led, estado);
  }
