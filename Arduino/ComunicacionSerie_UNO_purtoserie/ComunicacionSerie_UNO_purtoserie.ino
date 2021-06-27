#define RX 0
#define TX 1
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
  if(Serial.available()){             //Reccepcion de datos
    dato = Serial.read();
    Serial.flush();
    }

  if(Serial){      //Transmision de datos
    //tiempoTX = millis();
    if(digitalRead(Boton)==LOW)
      Serial.println('c');
    else
      Serial.println('d');
  }
  
  if(dato == 'a')                       //Control del led
    digitalWrite(Led, HIGH);
  else if(dato == 'b')
    digitalWrite(Led, LOW);
  
}
