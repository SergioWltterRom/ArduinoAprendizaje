#define Tam 32
#define Baudios 9600

byte datosE[Tam];

void setup() {
  Serial.begin(Baudios);
  Serial.println("Crear array de bytes:");
  memset(datosE, 0, sizeof(datosE));
}

bool envio = LOW;
byte pos = 0;
String textoE = "Hola me llamo Sergio";

void loop() {
  if(envio == HIGH){
    Serial.println();
    Serial.write(datosE, pos);    //Envia el array al puerto Serial
    Serial.println();
    Serial.print("Datos enviados: ");
    for(int i = 0; i < pos; i++){
      Serial.print(datosE[i]);
      Serial.print(" ");
      }
    Serial.println();
    pos = 0;
    envio = LOW;
    }

  enviaTexto();   
  
  enviaLong(random(-2000000, 2000000));

   enviaInt(random(-25000, 30000));
  
  finTextoE();
  delay(9000);
}

void enviaInt(int ent){
  datosE[pos++] = 2;
  Serial.print("\n\nEntero: ");
  Serial.print(ent);
  Serial.print(" - ");
  Serial.println(ent, BIN);  
  datosE[pos] = highByte(ent);
  Serial.print(datosE[pos]);
  Serial.print(" ");
  datosE[++pos] = lowByte(ent);
  Serial.println(datosE[pos]);
  pos++;
  }

void enviaLong(long larg){
  datosE[pos] = 4;
  pos +=4;
  Serial.print("Largo: ");
  Serial.print(larg);
  Serial.print(" - ");
  Serial.println(larg, BIN);
  Serial.print("Bit de numero:  ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(larg, i);
    Serial.print(bt);
    bitWrite(datosE[pos], i, bt);
    }
    Serial.print(" ");
  for(int i = 8; i < 16; i++){
    bool bt = bitRead(larg, i);
    Serial.print(bt);    
    bitWrite(datosE[pos - 1], (i - 8), bt);
    }
    Serial.print(" ");
    for(int i = 16; i < 24; i++){
    bool bt = bitRead(larg, i);
    Serial.print(bt);
    bitWrite(datosE[pos - 2], (i - 16), bt);
    }
    Serial.print(" ");
    for(int i = 24; i < 32; i++){
    bool bt = bitRead(larg, i);
    Serial.print(bt);
    bitWrite(datosE[pos - 3], (i - 24), bt);
    }
    pos++;
    Serial.println();
  }

void enviaTexto(){
  datosE[pos++] = 6; 
  Serial.println();
  for(int i = 0; i < textoE.length(); i++){    
    char tx = textoE.charAt(i);
    datosE[pos++] = tx;    
    Serial.write(datosE[pos-1]);
    }
    datosE[pos++] = 126; // Caracter fin de texto 
    Serial.print("Pos:");
  Serial.println(pos);    
  }

void finTextoE(){
  envio = HIGH;
  datosE[pos++] = 10;
  Serial.print("Pos:");
  Serial.println(pos);
  }
