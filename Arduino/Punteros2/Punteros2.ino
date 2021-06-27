#define Led1 7
#define Led2 8

void setup() {
  Serial.begin(9600);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
}

void loop() {
  int val1;
  float val2;
  long val3;

  Serial.print("Direcciones:\t");
  Serial.print((unsigned int)(&val1)); //Imprime la direccion de la variable a la que estamos mirando
  Serial.print("\t");
  Serial.print((unsigned int)(&val2));
  Serial.print("\t");
  Serial.println((unsigned int)(&val3));

  cambiarValor(&val1, &val2, &val3);
  
  Serial.print(val1);
  Serial.print("\t");
  Serial.print(val2);
  Serial.print("\t");
  Serial.println(val3);

  delay(1000);

  Serial.print(val1);
  Serial.print("\t");
  Serial.print(val2);
  Serial.print("\t");
  Serial.println(val3);
  
  delay(1000);
}

void cambiarValor(int *v1, float *v2, long *v3){
  *v1 = random(0,1000);
  *v2 = random(0,1000);
  *v3 = random(0,1000);
  }
