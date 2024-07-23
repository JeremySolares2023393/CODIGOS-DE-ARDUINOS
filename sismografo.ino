#include <Wire.h>
#include <SparkFun_ADXL345.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

ADXL345 adxl = ADXL345();
SoftwareSerial mp3_sismo(8,9);
DFRobotDFPlayerMini reproductor_mp3;
int leds[] = {2,3,4,5,6,7};
int LED = 6;
unsigned int x;
unsigned int y;
unsigned int z;
float magnitud;

void setup() {
  Serial.begin(9600);
  mp3_sismo.begin(9600);
  adxl.powerOn();
  adxl.setRangeSetting(8);
  for(int i = 0; i < LED; i++){
    pinMode(leds[i], OUTPUT);
  }
  if(!reproductor_mp3.begin(mp3_sismo)){
    Serial.println("ERROR");
    while(1);
  }
  reproductor_mp3.volume(50);
  Serial.println("MP3 funcionando");
  reproductor_mp3.play(1);
  delay(100);
}
void loop() {
  adxl.readAccel(&x,&y,&z);
  magnitud = sqrtf(((x*x)+(y*y)+(z*z))*0.6);
  int intensidad = map(magnitud, 47, 75, 0, 10);
  for(int i = 0; i < LED; i++){
    if(i < intensidad){
      digitalWrite(leds[i], HIGH);
    }else{
      digitalWrite(leds[i], LOW);
    }
  }
  if(magnitud == 0){
    digitalWrite(leds[1], LOW);
  }
  if(intensidad >= 6){
    reproductor_mp3.play(1);
  }
  delay(1000);
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  Serial.println(magnitud);
}
