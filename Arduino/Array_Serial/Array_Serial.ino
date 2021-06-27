const size_t dataLength = 10;
int data[dataLength] = {1,2,3,4,5,6,7,8,9,0};
int dataIndex = 0;
 
void setup()
{
   Serial.begin(9600);
  
   for(int n = 0; n < dataLength; n++)
   {
      sendBytes(data[n]);
   }
} 
 
void loop() 
{ 
  if(Serial.available() >= sizeof(data[0]))
  {
    byte byte1 = Serial.read();
    byte byte2 = Serial.read();
    data[dataIndex] = byteToInt(byte1, byte2);
 
    dataIndex++;
    if(dataIndex >= dataLength)
    {
      dataIndex = 0;
    }
  }
}
 
void sendBytes(uint16_t value)
{
  Serial.write(highByte(value));
  Serial.write(lowByte(value));
}

uint16_t byteToInt(byte byte1, byte byte2)
{
   return (uint16_t)byte1 << 8 | (uint16_t)byte2;
}
