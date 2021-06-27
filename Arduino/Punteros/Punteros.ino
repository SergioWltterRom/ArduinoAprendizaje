#define Led1 7
#define Led2 8

void setup() {
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);

}

void loop() {
  bool leda;
  bool ledb;
  
  encender(&leda, &ledb);
  digitalWrite(Led1, leda);
  digitalWrite(Led2, ledb);
  Serial.print("Encendidos:\t");
  Serial.print(leda);
  Serial.print("\t");
  Serial.println(ledb);
  delay(1000);
  apagar(&leda, &ledb);
  digitalWrite(Led1, leda);
  digitalWrite(Led2, ledb);
  Serial.print("Apagados:\t");
  Serial.print(leda);
  Serial.print("\t");
  Serial.println(ledb);
  delay(1000);
}

void encender(bool *led1, bool *led2){
  *led1 = HIGH;
  *led2 = HIGH;
  }

void apagar(bool *led1, bool *led2){
  *led1 = LOW;
  *led2 = LOW;
  }
