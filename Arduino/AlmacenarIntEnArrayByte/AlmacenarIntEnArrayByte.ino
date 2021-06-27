#define Tam 4
const int ent = 30851;
int num = 0;
byte entero[Tam];

void setup() {
  Serial.begin(9600);
  Serial.println("Guardar entero en array byte:");
  Serial.print("Entero guardado: \t");
  Serial.println(ent);
  Serial.print("Vector de Bytes:  \t");
  memset(entero,0,sizeof(entero));
  for(int i = 0; i < (sizeof(entero)/sizeof(byte)); i++){
    Serial.print(entero[i],BIN);
    Serial.print("\t");
    }
  Serial.println();
  entero[0] = highByte(ent);
  entero[1] = lowByte(ent);
  Serial.print("Entero guardado (binario): \t");
  Serial.println(ent, BIN);
  Serial.print("Vector de Bytes:  \t");
  for(int i = 0; i < (sizeof(entero)/sizeof(byte)); i++){
    Serial.print(entero[i], BIN);
    Serial.print("\t");
    }
    Serial.print("\nBit de numero:  \t");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(entero[1], i);
    Serial.print(bt);
    bitWrite(num, i, bt);
    }
    Serial.print(" ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(entero[0], i);
    Serial.print(bt);
    bitWrite(num, (i+8), bt);
    }
    Serial.println();
  Serial.print("Entero regenerado: \t");
  Serial.print(num);
  Serial.print(" - ");
  Serial.println(num, BIN);
}

void loop() {
//  Serial.write(111);
//  Serial.write(datos, sizeof(datos)/sizeof(byte));
//  Serial.println(sizeof(datos)/sizeof(byte));
//  delay(5000);
}
