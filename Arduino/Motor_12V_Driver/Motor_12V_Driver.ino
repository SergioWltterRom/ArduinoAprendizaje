#define ENA 6
#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 2
#define IN4 4

unsigned long tiempo1;
unsigned long tiempo2;
bool direccion1=LOW;
bool direccion2=LOW;
bool acelera1=LOW;
bool acelera2=LOW;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

int i=0;
int j=0;

void loop() {
  if (millis() > tiempo1 + 40){
    tiempo1 = millis();
    if(direccion1==LOW){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }else{
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      }
    if(i<256 && acelera1 == LOW){
      i++;
      analogWrite(ENA, i);
      }else if (acelera1 == LOW){
        acelera1=!acelera1;
      }
     if(i>-1 && acelera1 == HIGH){
      i--;
      analogWrite(ENA, i);
      }else if (acelera1 == HIGH){
        acelera1=!acelera1;
        direccion1=!direccion1;
      }
    }
    
  if (millis() > tiempo2 + 80){
    tiempo2 = millis();
    if(direccion2==LOW){
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }else{
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      }
    if(j<256 && acelera2 == LOW){
      j++;
      analogWrite(ENB, j);
      }else if (acelera2 == LOW){
        acelera2=!acelera2;
      }
     if(j>-1 && acelera2 == HIGH){
      j--;
      analogWrite(ENB, j);
      }else if (acelera2 == HIGH){
        acelera2=!acelera2;
        direccion2 = !direccion2;
      }
    }
}
