#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const byte fila = 4;
const byte column = 4;

char keys[fila][column]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
byte pinfil[fila]={12,11,10,9};
byte pincolum[column]={8,7,6,5};
Keypad teclado = Keypad( makeKeymap(keys), pinfil, pincolum, fila,column);
char key;
Servo miservo;
int pin;

void setup()
{
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  miservo.attach(4, 500,2500);
  miservo.write(0);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("Jeremy");        //lcd
  lcd.setCursor(1,1);
  lcd.print("Proyecto Final");
  for(pin=14;pin <= 17;pin++){
   pinMode(pin,OUTPUT); 
  }
}  
void loop()
{  
 key = teclado.getKey();
  
  if(key=='1'){ 
    for(int i=0;i<=99;i++){
     Serial.println(i);
     delay(100);
    } 
  }
  if(key=='2'){
    for(int a=99;a>=0;a--){
     Serial.println(a);
     delay(100);
    }
  }
  if(key=='3'){
   for(pin= 14;pin <= 17;pin++)
    {
    pinMode(pin, OUTPUT);
    digitalWrite(pin,HIGH);
    delay(500);
    digitalWrite(pin,LOW);
    }
  
    for(pin=17;pin >= 14;pin--)
    {
    pinMode(pin, OUTPUT);
    digitalWrite(pin,HIGH);
    delay(500);
    digitalWrite(pin,LOW);
    }  
  }
  if(key=='4'){
   digitalWrite(2,HIGH);
   delay(100);
   digitalWrite(2,LOW);
    delay(100);
   digitalWrite(3,HIGH);
   delay(100);
   digitalWrite(3,LOW);
    delay(100);
   digitalWrite(A3,HIGH);
   delay(100);
   digitalWrite(A3,LOW);
    delay(100);
   digitalWrite(A2,HIGH);
   delay(100);
   digitalWrite(A2,LOW);
    delay(100);
    digitalWrite(A1,HIGH);
   delay(100);
   digitalWrite(A1,LOW);
    delay(100);
    digitalWrite(13,HIGH);
   delay(100);
   digitalWrite(13,LOW);
    delay(100);
    digitalWrite(2,HIGH);
   delay(100);
   digitalWrite(2,LOW);
  }
  if(key=='5'){
   miservo.write(180);
      delay(4000);            //servomotor
      miservo.write(0); 
  }
}
  
