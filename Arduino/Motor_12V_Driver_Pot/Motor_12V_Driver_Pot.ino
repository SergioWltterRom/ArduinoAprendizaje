#define ENA 6
#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 2
#define IN4 4
#define POT A0

unsigned long tiempo1;

bool direccion1=LOW;
bool direccion2=LOW;
bool acelera1=LOW;
bool acelera2=LOW;

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

int i=0;
int j=0;
int vel=0;

void loop() {
 
  vel = map(analogRead(POT),0,1023,0,255);
   analogWrite(ENA, vel);
   analogWrite(ENB, vel);

  
      
  if(direccion1==LOW){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    }      
   
  if(direccion2==LOW){
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }else{
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    }  

  if(millis()>tiempo1 + 300){
    tiempo1 = millis();

    if(vel==0){
    direccion1= !direccion1;
    direccion2=!direccion2;
    }
    
    Serial.print("Direccion 1 :\t");
    Serial.println(direccion1);
    Serial.print("Direccion 2 :\t");
    Serial.println(direccion2);
    Serial.print("Velocidad :\t");
    Serial.println(vel);
    }

}
