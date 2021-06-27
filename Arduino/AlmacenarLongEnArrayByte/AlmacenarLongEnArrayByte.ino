#define Tam 4
const long ent = 1325986;
long num = 0;
byte entero[Tam];

void setup() {
  Serial.begin(9600);
  Serial.println("Guardar entero en array byte:");
  Serial.print("Entero guardado: \t");
  Serial.print(ent);
  Serial.print(" - ");
  Serial.println(ent, BIN);
  Serial.print("Vector de Bytes:  \t");
  memset(entero,0,sizeof(entero));
  for(int i = 0; i < (sizeof(entero)/sizeof(byte)); i++){
    Serial.print(entero[i],BIN);
    Serial.print("\t");
    }
  Serial.println();
  
  ///////////////////////////////
  Serial.print("Bit de numero:  ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(ent, i);
    Serial.print(bt);
    bitWrite(entero[Tam - 1], i, bt);
    }
    Serial.print(" ");
  for(int i = 8; i < 16; i++){
    bool bt = bitRead(ent, i);
    Serial.print(bt);    
    bitWrite(entero[Tam - 2], (i - 8), bt);
    }
    Serial.print(" ");
    for(int i = 16; i < 24; i++){
    bool bt = bitRead(ent, i);
    Serial.print(bt);
    bitWrite(entero[Tam - 3], (i - 16), bt);
    }
    Serial.print(" ");
    for(int i = 24; i < 32; i++){
    bool bt = bitRead(ent, i);
    Serial.print(bt);
    bitWrite(entero[Tam - 4], (i - 24), bt);
    }
  //////////////////////////////
  Serial.println();
  Serial.print("Vector de Bytes:  \n");
  for(int i = 0; i < (sizeof(entero)/sizeof(byte)); i++){
    Serial.print(entero[i], BIN);
    Serial.print("\t");
    }
    Serial.print("\nBit de numero:  ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(entero[Tam - 1], i);
    Serial.print(bt);
    bitWrite(num, i, bt);
    }
    Serial.print(" ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(entero[Tam - 2], i);
    Serial.print(bt);
    bitWrite(num, (i+8), bt);
    }
    Serial.print(" ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(entero[Tam - 3], i);
    Serial.print(bt);
    bitWrite(num, (i+16), bt);
    }
    Serial.print(" ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(entero[Tam - 4], i);
    Serial.print(bt);
    bitWrite(num, (i+24), bt);
    }
    Serial.println();
  Serial.print("Entero regenerado: \t");
  Serial.print(num);
  Serial.print(" - ");
  Serial.println(num, BIN);
}

void loop() {
}
