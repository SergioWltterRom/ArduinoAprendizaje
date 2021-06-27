const int NUM_BYTES = 3;
byte data[NUM_BYTES];
 
bool TryGetSerialData(const byte* data, uint8_t dataLength)
{
   if (Serial.available() >= dataLength)
   {
      Serial.readBytes(data, dataLength);
      return true;
   }
   return false;
}
 
void OkAction()
{
  Serial.println(Recibido);
}
 
void setup()
{
   Serial.begin(9600);
}
 
void loop()
{
   if(TryGetSerialData(data, NUM_BYTES))
   {
      OkAction();
   }
}
