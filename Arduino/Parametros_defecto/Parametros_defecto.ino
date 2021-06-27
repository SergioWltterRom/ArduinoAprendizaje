#define Led1 9
#define Led2 10

void controlLed(int, bool = LOW);  //Los valores solo se pueden poner en la declaracion de una funcion si no da fallo en su lugar

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  controlLed(Led1, HIGH);
  controlLed(Led2, HIGH);
  delay(100);
  controlLed(Led1);  
  controlLed(Led2);
  delay(800);

}

void controlLed(int led, bool val){
  digitalWrite(led, val);
  }
