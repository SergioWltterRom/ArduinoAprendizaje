#define Dispositivo1 0
#define Dispositivo2 2
#define Led1 9
#define Led2 10

unsigned long tiempo=0;

byte dato[]={0, 255, 1, 8};   //Nuevo
const size_t tamanoDato = sizeof(dato)/sizeof(dato[0]); //Nuevo

void setup()
{
  Serial.begin(9600);
  Serial.println("Enviar caracter");
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  Serial.write(dato, tamanoDato);   //Nuevo
}

byte i=0; 
byte valor[4];

void loop() 
{

  if(Serial.available()>0){
    byte val=Serial.read();    //Lee el valor de cada byte del buffer
    valor[i++]=val;            // Lo almacena en cada cuadro del vector
  } else{
    switch(valor[Dispositivo1]){    ////El byte de la posicion 2 determina a que dispositivo 1   anuncia
    case 48:
      Serial.print("Led 1 a : ");
      Serial.println(valor[Dispositivo1+1]);
      analogWrite(Led1,valor[Dispositivo1+1]);
      break;

    case 49:
      Serial.print("Led 2 a : ");
      Serial.println(valor[Dispositivo1+1]);
      analogWrite(Led1,0);
      break;

    case 50:
      Serial.print("Led 3 a : ");
      Serial.println(valor[Dispositivo1+1]);
      break;

    case 51:
      Serial.print("Motor 1 a : ");
      Serial.println(valor[Dispositivo1+1]);
      break;

    case 52:
      Serial.print("Motor 2 a : ");
      Serial.println(valor[Dispositivo1+1]);
      break;

    case 53:
      Serial.print("Motor 3 a : ");
      Serial.println(valor[Dispositivo1+1]);
      break;

    default:
      Serial.println("Este dispositivo no existe");
    }

    switch(valor[Dispositivo2]){  //El byte de la posicion 2 determina a que dispositivo 2 anuncia
    case 48:
      Serial.print("Led 1 a : ");
      Serial.println(valor[Dispositivo2+1]);
      analogWrite(Led2,0);
      break;

    case 49:
      Serial.print("Led 2 a : ");
      Serial.println(valor[Dispositivo2+1]);
      analogWrite(Led2,valor[Dispositivo2+1]);
      break;

    case 50:
      Serial.print("Led 3 a : ");
      Serial.println(valor[Dispositivo2+1]);
      break;
      
    case 51:
      Serial.print("Motor 1 a : ");
      Serial.println(valor[Dispositivo2+1]);
      break;

    case 52:
      Serial.print("Motor 2 a : ");
      Serial.println(valor[Dispositivo2+1]);
      break;

    case 53:
      Serial.print("Motor 3 a : ");
      Serial.println(valor[Dispositivo2+1]);
      break;

    default:
      Serial.println("Este dispositivo no existe");
    }
    
    memset(valor, 0,sizeof(valor));    
    }
    
  if(i==4)                 //Inicializa la posicion del vector
    i=0;
  
//  if(millis() > tiempo +2000){  //Muestra el vector por pantalla (solo para pruebas)
//    tiempo = millis();
//    Serial.println("Vector:");
//    for(int j=0; j<4;j++)
//      Serial.println(valor[j]);
//    Serial.println("Valor i: " + String (i));    
//  }  
}

  





//    Serial.println(val2);
//    Serial.println(val3);
//    val2=Serial.read();
//    val3=Serial.read();
//  int val2=0;
//  int val3=0;
