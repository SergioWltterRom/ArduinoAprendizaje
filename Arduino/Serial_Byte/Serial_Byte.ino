#define Led1 9
#define Led2 10

unsigned long tiempo = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);  
}

String dato;
String dato1 = "0";
String dato2 = "0";
int led, luz, i, j;

void loop() {
  if(Serial.available()){
    dato = Serial.readString();
    Serial. print("Dato = ");
    Serial. println(dato);

    dato1 = "0";
    dato2 = "0";
    
    for (i = 0; i < (dato.length()-1); i++){
      if(dato[i] == '.')
        break;
      if(i==0){
        dato1[i] = dato[i];        
      }
      else
        dato1.concat(dato[i]);
    }
    
    dato1[i] = '\0';
    int s=0;
    
    for (j = i+1; j < (dato.length()-1); j++){    
      if(j==i+1)
        dato2[s++] = dato[j];
      else{
        dato2.concat(dato[j]);
        s++;
      }      
    }
    dato2[s] = '\0';

    
  }  

  if(millis() > tiempo + 1500){
    tiempo = millis();
//    Serial. print("Luz 1 = ");
//    Serial. println(luz1);
//
//    Serial. print("Luz 2 = ");
//    Serial. println(luz2);
    }

  led = dato1.toInt();  
  luz = dato2.toInt();

  switch(led){
    case 0:
      analogWrite(Led1, luz);
      break;
    case 1:
      analogWrite(Led2, luz);
      break;
    default:
      Serial. println("No existe este led");      
    }

//  analogWrite(Led1, luz1);
//  analogWrite(Led2, luz2);
}
