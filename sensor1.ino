/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: parte 1 practica 4
   Profe. Alejandro Lopez Navas
   Fecha: 17 de abril
   Jsolares-2023393
*/

#include <Adafruit_NeoPixel.h>

#define pin  4
#define Nump  6

Adafruit_NeoPixel pixels(Nump, pin, NEO_RGB + NEO_KHZ800);

int count = 1;

int TRIG = 3;
int ECO  = 2;
int DISTANCIA;
int DURACION;

void setup()
{
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A3,OUTPUT);
  pixels.begin();
  
  digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  
}  
void loop()
{
  pixels.clear();
 digitalWrite(TRIG,HIGH);
delay(1);
digitalWrite(TRIG,LOW);
DURACION=pulseIn(ECO,HIGH);
DISTANCIA=DURACION/59;
  
  if(DISTANCIA <=10 && DISTANCIA >=6)
  {  
   count++;
  to_BCD();
    delay(1000);
  }
   
  for(int i=0;i<Nump;i++)
    {
      pixels.setPixelColor(i, pixels.Color(150,0,0));
      pixels.show();
      delay(5);
    }
  
  if(count==11)
  {
    for(int i=0;i<Nump;i++)
  {
   pixels.setPixelColor(i, pixels.Color(0,150,0));
   pixels.show();
   delay(50);
  }
    delay(10000000000);
  }
  
  }       
  


void to_BCD()
{
  if (count == 1) //0000
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }

  if (count == 2) //0001
  {
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,LOW);
    digitalWrite(A3,LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }

  if (count == 3) //0010
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(A5,LOW);
    digitalWrite(A4,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }

  if (count == 4) //0011
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A3,LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }

  if (count == 5) //0100
  {
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,LOW);
    digitalWrite(A3,LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }

  if (count == 6) //0101
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A3,LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }

  if (count == 7) //0110
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }

  if (count == 8) //0111
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,LOW);
    digitalWrite(A3,LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }

  if (count == 9) //1000
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A3,HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }

  if (count == 10) //1001
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(A5,HIGH);
    digitalWrite(A4,HIGH);
    digitalWrite(A3,LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
  }
  
  if (count == 11) //1011
  {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(A5,LOW);
    digitalWrite(A4,LOW);
    digitalWrite(A3,LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }
}
