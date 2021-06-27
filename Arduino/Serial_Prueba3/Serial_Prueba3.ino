#define Led1 9
#define Led2 10
#define Led3 13

unsigned long tiempo = 0;

void setup() {
  Serial.begin(9600);  
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT); 
  pinMode(Led3, OUTPUT);  
}

String dato;
String dato1 = "0";
String dato2 = "0";
String dato3 = "0";
int luz1, luz2, luz3, i, j, k;

void loop() {
  if(Serial.available()){
    dato = Serial.readString();
    Serial. print("Dato = ");
    Serial. println(dato);

    dato1 = "0";
    dato2 = "0";
    dato3 = "0";
    
    for (i = 0; i < (dato.length()-1); i++){
      if(dato[i] == '.')
        break;
      if(i==0)
        dato1[i] = dato[i];    
      else
        dato1.concat(dato[i]);
      Serial. print("Dato 1 = ");
      Serial. println(dato1);
    }
        
    int s=0;
    
    for (j = i+1; j < (dato.length()-1); j++){ 
      if(dato[j] == '.')
        break;   
      if(j==i+1)
        dato2[s++] = dato[j];
      else{
        dato2.concat(dato[j]);
        s++;
      Serial. print("Dato 2 = ");
      Serial. println(dato2);
      }      
    }
        
    int t=0;

    for (k = j+1; k < (dato.length()-1); k++){    
      if(k==j+1)
        dato3[t++] = dato[k];
      else{
        dato3.concat(dato[k]);
        t++;
        Serial. print("Dato 3 = ");
      Serial. println(dato3);
      }      
    }       
  }  

  luz1 = dato1.toInt();  
  luz2 = dato2.toInt();
  luz3 = dato3.toInt();

  if(millis() > tiempo + 1500){
    tiempo = millis();
    Serial. print("Luz 1 = ");
    Serial. println(luz1);

    Serial. print("Luz 2 = ");
    Serial. println(luz2);

    Serial. print("Luz 3 = ");
    Serial. println(luz3);
    }
      
  analogWrite(Led1, luz1);
  analogWrite(Led2, luz2);
  digitalWrite(Led3, luz3);
  
//  switch(led){
//    case 0:
//      analogWrite(Led1, luz);
//      break;
//    case 1:
//      analogWrite(Led2, luz);
//      break;
//    default:
//      Serial. println("No existe este led");      
//    }
}
