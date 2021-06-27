int valores[4]={5,14,247,6};

void setup() {
  Serial.begin(9600);
  
}

void loop() {
//  int *p;
//  p=valores;
  Serial.println("Valores:");
  
  for (int i = 0; i < 4; i++){
    Serial.println(valores[i]);
    }

  delay(1000);
    
}
