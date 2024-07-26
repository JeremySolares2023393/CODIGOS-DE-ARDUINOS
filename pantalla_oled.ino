#include <Wire.h>      
#include <Adafruit_GFX.h>   
#include <Adafruit_SSD1306.h>   

#define ANCHO 128     
#define ALTO 64       

int valor;

#define OLED_RESET 4      
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET);  

void setup() {
  Wire.begin();         
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
}
 
void loop() {
  oled.clearDisplay();      
  oled.setTextColor(WHITE);   
  oled.setCursor(0, 0);     
  oled.setTextSize(1);      
  oled.print("Valor del ADC en la  escala 1 ");   
  oled.setCursor (38, 30);    
  oled.setTextSize(2);    
  valor = analogRead(A0);
  oled.print(valor);  
  oled.display();     
}
