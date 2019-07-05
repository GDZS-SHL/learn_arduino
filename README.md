# 李顺鸿的开源硬件作业

# 第一天

#### 学习内容
- 为什么要学习开源硬件
- 如何学习开源硬件
- 三个软件

  arduino
  
  fritzing
  
  processing
  
  
- 几个常用网站

[arduino](https://www.arduino.cc/en/Main/Software)

[github](https://github.com/GDZS-SHL/learn_arduino)
# 第二天

#### 学习内容
- morse码

 morse.h
 ```
#ifndef _MORSE_H
#define _MORSE_H
class Morse
{
  public:
    Morse(int pin);
    void dot();
    void dash();
    void c_space();
    void w_space();
  private:
    int _pin;
    int _dottime;
};
#endif /*_MORSE_H*/
```
  morse.cpp
```
#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_dottime=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_dottime*3);
	digitalWrite(_pin,LOW);
	delay(_dottime);
}

void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*3);
}

void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(_dottime*7);
}
 ```
morse.ino
 ```
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
 ```
# 第三天
#### 学习内容
car：
car.ino
 ```
 //f=forward b=back l=left r=right s=stop
void setup()
{
 pinMode(5,OUTPUT); 
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}
int income;
void loop()
{
 if(Serial.available()>0)
 {
   income=Serial.read();
  switch (income)
  {
    case 'f':{forward();break;}
    case 'b':{back();break;}
    case 'l':{left();break;}
    case 'r':{right();break;}
    case 's':{stop();break;}
    default:break;
  }
 }
}

void forward()
{
  digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
}
void back()
{
  digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
}
void left()
{
  digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
}
void right()
{
  digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
}
void stop()
{
  digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
}
  ```
  led：
  led.ino
  ```
void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  Serial.begin(9600);

}
byte income=0;
void loop()
{
  if(Serial.available()>0)
  {
    digitalWrite(2,LOW);
    income=Serial.read();
    income=income-'0';
    if(income&0x1)
    {
      digitalWrite(3,HIGH);
    }
    else
    {
    digitalWrite(3,LOW);
    }
    if((income)>>1&0x1)
    {
      digitalWrite(4,HIGH);
    }
    else
    {
      digitalWrite(4,LOW);
    }
    if((income)>>2&0x1)
    {
      digitalWrite(5,HIGH);
    }
    else
    {
      digitalWrite(5,LOW);
    }
    if((income)>>3&0x1)
    {
      digitalWrite(6,HIGH);
    }
    else
    {
      digitalWrite(6,LOW);
    }
   delay(10);
   digitalWrite(2,HIGH);
  }
}  
```
# 第四天
#### 学习内容
-学习编写markdown文件
-改良了morse

morse2.0.ino
 ```
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
 ```
-改良了led

led2.0.ino
```
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
```
