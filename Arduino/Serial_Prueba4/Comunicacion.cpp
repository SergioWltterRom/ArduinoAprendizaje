//#include <Arduino.h>

void lecturaDato(int n, ){        // (numero del dato a conseguir)
  if(Serial.available()){
    String dato;
    String dato_n;
    dato = Serial.readString();
    Serial. print("Dato = ");
    Serial. println(dato);

    dato_n = "0";

    int puntos = 0;
        
    for (i = 0; i < (dato.length()-1); i++){
      if(dato[i] == '.')
        puntos++;

      if(dato[i] == '.' && puntos > (n-1))
        break;

      if (puntos == (n-1)){
        if(i==0)
        dato_n[i] = dato[i];    
      else
        dato_n.concat(dato[i]);
      Serial. print("Dato n = ");
      Serial. println(dato_n);
        }
      
    }

    return dato_n;
        
//    int s=0;
//    
//    for (j = i+1; j < (dato.length()-1); j++){ 
//      if(dato[j] == '.')
//        break;   
//      if(j==i+1)
//        dato2[s++] = dato[j];
//      else{
//        dato2.concat(dato[j]);
//        s++;
//      Serial. print("Dato 2 = ");
//      Serial. println(dato2);
//      }      
//    }
//        
//    int t=0;
//
//    for (k = j+1; k < (dato.length()-1); k++){    
//      if(k==j+1)
//        dato3[t++] = dato[k];
//      else{
//        dato3.concat(dato[k]);
//        t++;
//        Serial. print("Dato 3 = ");
//      Serial. println(dato3);
//      }      
//    }       
  }
  }
