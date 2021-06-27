#define Led1 9
#define Led2 10

byte brillo[2]={0,0};

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
}

void loop() {

  brillar(brillo, sizeof(brillo)/sizeof(byte));
  analogWrite(Led1, brillo[0]);
  analogWrite(Led2, brillo[1]);
  delay(500);

}

void brillar(byte br[], int tam){
  br[0]+=10;
  br[1]+=70;
  }
