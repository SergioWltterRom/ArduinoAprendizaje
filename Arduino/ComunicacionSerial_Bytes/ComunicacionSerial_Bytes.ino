#define Tam 30
#define Baudios 9600
#define Led1 9
#define Led2 10

byte datos[Tam];

void setup() {
  Serial.begin(Baudios);
  Serial.println("Enviar array de bytes:");
  memset(datos, 0, sizeof(datos));
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
}

byte i=0;
bool recibido = LOW;
byte Control = 0;
String texto = "";

void loop() {

  //////Recibir Array Serial/////
  if(Serial.available()>0){
    datos[i++]=Serial.read();    //Lee el valor de cada byte del buffer  Lo almacena en cada cuadro del vector   
    //Control = 0;
    Serial.println(datos[i-1]);
    } else{
      if(datos[i-1] == 10){
      recibido = HIGH; 
      Control = 0;
      }
    if(i > Tam-1){
      Serial.println("Error de tamaño");
      errorComunicacion();
      }   
  }
  if(recibido == HIGH){ 
      i=0;
      Serial.print("Estoy en control y recibido = "); 
      Serial.println(recibido);
      Serial.print("Control : ");
      Serial.println(Control);
      opcionControl();              
    }
  //////Fin recibir array Serial////
}

void opcionControl(){
  int opcion = (int) datos[Control];
  Serial.print("Estoy en opciones y el valor es = "); 
      Serial.println(opcion);
      
    ////////Sustitucion del puto switch//////////
    if(opcion == 10){
      Serial.println("Fin");
      memset(datos, 0, sizeof(datos));
      recibido = LOW;
      Control = 0;
      }
      if(opcion == 48){
      Serial.print("Led 1 a : ");
      Serial.println(datos[Control+1]);
      analogWrite(Led1,datos[Control+1]);
      Control += 2;
      Serial.print("Control : ");
      Serial.println(Control);
      }
      if(opcion == 49){
      Serial.print("Led 1 a : 0");      
      analogWrite(Led1,LOW);
      Control += 1;
      }
      if(opcion == 50){
      Serial.print("Led 2 a : ");
      Serial.println(datos[Control+1]);
      analogWrite(Led2,datos[Control+1]);
      Control += 2;
      }
      if(opcion == 51){
      Serial.print("Led 2 a : 0");
      analogWrite(Led2,LOW);
      Control += 1;
      }
      if(opcion == 52){
      Serial.println("Envio entero");
      int entero = recibeInt(Control+2);
      Control += 3;
      Serial.print("Control : ");
      Serial.println(Control);
      Serial.println(entero, BIN);
      }
      if(opcion == 53){
      Serial.println("Envio long");
      long largo = recibeLong(Control+4);
      Control += 5;
      Serial.println(largo, BIN);
      }
      if(opcion == 54){
      Serial.println("Envio texto");
      int cont = 0;
      
      for(int j = Control + 1; datos[j] != 126; j++){
        char c = datos[j];
        if(j == Control + 1)
          texto = c;
        else      
          texto += c;
        cont++;        
        }      
      Control += (cont+2);
      Serial.print("Texto:");
      Serial.println(texto);      
      }
    //////////////////////////////////////////////
    
    if((opcion < 48 || opcion > 54) && opcion != 10){
      Serial.println("Control no valido");
      memset(datos, 0, sizeof(datos));
      recibido = LOW;
      Control = 0;
      }
  }

int recibeInt(byte pos){
  int num;
  Serial.print("Bit de numero:  \t");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(datos[pos], i);
    Serial.print(bt);
    bitWrite(num, i, bt);
    }
    Serial.print(" ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(datos[pos-1], i);
    Serial.print(bt);
    bitWrite(num, (i+8), bt);
    }
    Serial.println();
    //Serial.println(num, BIN);
    return num;
  }

long recibeLong(byte pos){
  long num;
  Serial.print("Bit de numero:  ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(datos[pos], i);
    Serial.print(bt);
    bitWrite(num, i, bt);
    }
    Serial.print(" ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(datos[pos - 1], i);
    Serial.print(bt);
    bitWrite(num, (i+8), bt);
    }
    Serial.print(" ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(datos[pos - 2], i);
    Serial.print(bt);
    bitWrite(num, (i+16), bt);
    }
    Serial.print(" ");
  for(int i = 0; i < 8; i++){
    bool bt = bitRead(datos[pos - 3], i);
    Serial.print(bt);
    bitWrite(num, (i+24), bt);
    }
    Serial.println();
    //Serial.println(num, BIN);
    return num;
  }

void errorComunicacion(){
  i=0;
  Serial.print("Datos: ");
//  for(int k=0;k<sizeof(datos);k++){
//    Serial.print(datos[k]);
//    }
  memset(datos, 0, sizeof(datos));
  recibido = LOW;
  }
