int chr=0;	
int _dottime=250;
void dot()
{
	digitalWrite(13,HIGH);
	delay(250);
	digitalWrite(13,LOW);
	delay(250);
}

void dash()
{
	digitalWrite(13,HIGH);
	delay(750);
	digitalWrite(13,LOW);
	delay(250);
}

void c_space()
{
	digitalWrite(13,LOW);
	delay(750);
}

void w_space()
{
	digitalWrite(13,LOW);
	delay(1750);
}

void convert(int ch)
{
  switch (ch)
  {
  case 97:{dot();dash();break;}//a
  case 98:{dash();dot();dot();dot();break;}//b
  case 99:{dash();dot();dash();dot();break;}
  case 100:{dash();dot();dot();break;}
  case 101:{dot();break;}//e
  case 102:{dot();dot();dash();dot();break;}
  case 103:{dash();dash();dot();break;}
  case 104:{dot();dot();dot();dot();break;}
  case 105:{dot();dot();break;}
  case 106:{dot();dash();dash();dash();break;}//j
  case 107:{dash();dot();dash();break;}
  case 108:{dot();dash();dot();dot();break;}//l
  case 109:{dash();dash();break;}
  case 110:{dash();dot();break;}//n
  case 111:{dash();dash();dash();break;}//o
  case 112:{dot();dash();dash();dot();break;}//p
  case 113:{dash();dash();dot();dash();break;}//q
  case 114:{dot();dash();dot();break;}
  case 115:{dot();dot();dot();break;}
  case 116:{dash();break;}//t
  case 117:{dot();dot();dash();break;}//u
  case 118:{dot();dot();dot();dash();break;}
  case 119:{dot();dash();dash();break;}
  case 120:{dash();dot();dot();dash();break;}//x
  case 121:{dash();dot();dash();dash();break;}//y
  case 122:{dash();dash();dot();dot();break;}//z  
  case 32:{w_space();break;}
  }
}
 
void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600); 
}

void loop()
{
  if (Serial.available() > 0) 
  {
    chr = Serial.read();
    convert(chr);
    c_space();
  }
}