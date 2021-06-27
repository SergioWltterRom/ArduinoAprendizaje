#define RX 10
#define TX 11
#define Boton 4
#define Led 7

unsigned long tiempoTX = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Led, OUTPUT);
  pinMode(Boton, INPUT_PULLUP);  
}

char dato = 's';

void loop() {
  if(Serial.available()){
    dato = Serial.read();
    Serial.flush();
    }

  if(Serial){      //Transmision de datos
    //tiempoTX = millis();
    if(digitalRead(Boton)==LOW)
      Serial.println('a');
    else
      Serial.println('b');
  }

  if(dato == 'c')
    digitalWrite(Led, HIGH);
  else if(dato == 'd')
    digitalWrite(Led, LOW);
}
