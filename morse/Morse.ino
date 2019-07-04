#include <Morse.h>
 
Morse morse(13);
char chr=0;
void convert(char ch)
{
  switch (ch)
  {
  case 97:{morse.dot();morse.dash();break;}//a
  case 98:{morse.dash();morse.dot();morse.dot();morse.dot();break;}//b
  case 99:{morse.dash();morse.dot();morse.dash();morse.dot();break;}
  case 100:{morse.dash();morse.dot();morse.dot();break;}
  case 101:{morse.dot();break;}//e
  case 102:{morse.dot();morse.dot();morse.dash();morse.dot();break;}
  case 103:{morse.dash();morse.dash();morse.dot();break;}
  case 104:{morse.dot();morse.dot();morse.dot();morse.dot();break;}
  case 105:{morse.dot();morse.dot();break;}
  case 106:{morse.dot();morse.dash();morse.dash();morse.dash();break;}//j
  case 107:{morse.dash();morse.dot();morse.dash();break;}
  case 108:{morse.dot();morse.dash();morse.dot();morse.dot();break;}//l
  case 109:{morse.dash();morse.dash();break;}
  case 110:{morse.dash();morse.dot();break;}//n
  case 111:{morse.dash();morse.dash();morse.dash();break;}//o
  case 112:{morse.dot();morse.dash();morse.dash();morse.dot();break;}//p
  case 113:{morse.dash();morse.dash();morse.dot();morse.dash();break;}//q
  case 114:{morse.dot();morse.dash();morse.dot();break;}
  case 115:{morse.dot();morse.dot();morse.dot();break;}
  case 116:{morse.dash();break;}//t
  case 117:{morse.dot();morse.dot();morse.dash();break;}//u
  case 118:{morse.dot();morse.dot();morse.dot();morse.dash();break;}
  case 119:{morse.dot();morse.dash();morse.dash();break;}
  case 120:{morse.dash();morse.dot();morse.dot();morse.dash();break;}//x
  case 121:{morse.dash();morse.dot();morse.dash();morse.dash();break;}//y
  case 122:{morse.dash();morse.dash();morse.dot();morse.dot();break;}//z  
  case 32:{morse.w_space();break;}
  }
}
 
void setup()
{
  Serial.begin(9600); 
}

void loop()
{
  if (Serial.available() > 0) {
    chr = Serial.read();
    convert(chr);
    morse.c_space();
}
}
