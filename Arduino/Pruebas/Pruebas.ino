byte datos[60];
unsigned long tiempo = 0;

void setup() {
  Serial.begin(9600);
}

bool leer = LOW;

void loop() {
  int num = 10;
  int val = Serial.available();
  if(Serial.available()>0){
    delay(5);
    num = Serial.readBytes(datos, Serial.available());
    Serial.print("Bytes en bufer: ");
    Serial.println(val, DEC);
    leer = HIGH;
    }

  if(leer == HIGH){
    leer = LOW;
    Serial.print("Datos: ");
    for(int i = 0; i < num; i++){ //sizeof(datos)/sizeof(byte)
      Serial.print(datos[i]);
      Serial.print(" ");
      }
      Serial.println();
    
    Serial.print("Datos char: ");
    for(int i = 0; i < num; i++){
      Serial.write(datos[i]);      
      }
      Serial.println();
      Serial.print("Num: ");
      Serial.println(num);
    }
          
  //if(millis() > tiempo + ){}
}
