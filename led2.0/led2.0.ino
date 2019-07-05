void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);

}
int i=1;
int t;
byte income=0;
void loop()
{
  if(Serial.available()>0)
  {
    income=Serial.read();
    income=income-'0';
    t=i%4;
    switch(t)
    {
      case 1:digitalWrite(8,LOW);break;
      case 2:digitalWrite(9,LOW);break;
      case 3:digitalWrite(10,LOW);break;
      case 0:digitalWrite(11,LOW);break;
    }
    if(income&0x1)
    {
     digitalWrite(2,HIGH);
    }
    else
    {
    digitalWrite(2,LOW);
    }
    if((income)>>1&0x1)
    {
    digitalWrite(3,HIGH);
    }
    else
    {
    digitalWrite(3,LOW);
    }
    if((income)>>2&0x1)
    {
    digitalWrite(4,HIGH);
    }
    else
    {
      digitalWrite(4,LOW);
    }
    if((income)>>3&0x1)
    {
      digitalWrite(5,HIGH);
    }
    else
    {
      digitalWrite(5,LOW);
    }
   delay(10);
   switch(t)
    {
      case 1:digitalWrite(8,HIGH);break;
      case 2:digitalWrite(9,HIGH);break;
      case 3:digitalWrite(10,HIGH);break;
      case 0:digitalWrite(11,HIGH);break;
    }
    i++;
  }
}