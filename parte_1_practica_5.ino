/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: Uso de la pantalla LCD con interfaz I2C
   Dev: Paulo Calito 2020265
   Fecha: 16 de mayo de 2024   
*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

//Directivas de preprocesador para la LCD
#define direccion_lcd 0x20     //Sla_add pantalla LCD
#define filas 2                //Cantidad de filas que posee la pantalla LCD
#define columnas 16            //Cantidad de columnas que posee la pantalla LCD 

//Directicas de proceprocesador para el teclado matricial
#define filas_teclado 4        //cantidad de filas que posee el teclado matricial.
#define columnas_teclado 4     //cantidad de columnas que posee el teclado matricial.
#define f1_teclado 9         //pin9 conectado a la fila 1
#define f2_teclado 8          //pin8 conectado a la fila 2
#define f3_teclado 7          //pin7 conectado a la fila 3
#define f4_teclado 6          //pin6 conectado a la fila 4
#define c1_teclado 5           //pin 5  conectado a la columna 1
#define c2_teclado 4           //pin  4conectado a la columna 2
#define c3_teclado 3           //pin 3 conectado a la columna 3
#define c4_teclado 2           //pin 2 conectado a la columna 4

//Directicas de proceprocesador para el servomotor, leds y buzzer
#define pin_servo 11           //pin conectado al servomotor
#define pin_buzz  10           //pin conectado al buzzer
#define led_rojo  A3            //pin conectado al led rojo
#define led_amar  A1           //pin conectado al led amarillo
#define led_verd  A2            //pinconectado al led verde
#define ON(pin)     digitalWrite(pin, HIGH);
#define OFF(pin)    digitalWrite(pin, LOW);


//Variables para el uso del teclado
char keys[filas_teclado][columnas_teclado] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pines_filas[filas_teclado] = {f1_teclado,f2_teclado,f3_teclado,f4_teclado};
byte pines_columnas[columnas_teclado] = {c1_teclado,c2_teclado,c3_teclado,c4_teclado};


//Variables para el uso del servomotor
const int lock_pos = 0;             //posicion de 0 grados para indicar que la puerta se encuentra cerrada
const int unlock_pos = 90;          //posicion de 90 grados para indicar que la puerta se encuentra abierta


//Variables donde almacenare las contraseñas
String contrasenaCerradura = "2502*";   //Variable donde almaceno la contraseña definida por el sistema
String info_recibida = "";                //Variable donde voy a ir guardando los caracteres que ingreso por medio del teclado

//variables auxiliares
byte pos_lcd = 0;      //posición del cursor


//Constructor
LiquidCrystal_I2C lcdCerradura(direccion_lcd, columnas, filas);   //LCD con direccion 0x20 y tamanio 16x2
Servo ServoCerradura;                                             //Servomotor controlado por medio del PWM en el pin9
Keypad tecladoCerradura = Keypad( makeKeymap(keys), pines_filas, pines_columnas, filas_teclado,columnas_teclado);   //teclado matricial 4x4 conectado al arduino por diversos pines


//Funciones
//Funcion utiliza para configurar pines de entrada y salida
void config_outputs(void);

//Funcion que realiza las configuraciones de la interfaz hombre - maquina
void config_HMI(void);

void setup()
{
  Serial.begin(9600);             //Inicio la comunicacion serial
  Serial.println("Practica 6 Parte 2");   //Envio el mensaje al monitor serie
  config_outputs();               //Realizo las configuraciones de los pines de salida
  config_HMI();                   //configuro e inicializo la pantalla LCD y el servomotor
  ON(led_amar);                   //enciendo el led amarillo
  ON(led_rojo);
  OFF(led_verd);
  
}


void loop()
{
  //Obtengo el valor de la tecla presionada
  char key= tecladoCerradura.getKey(); 
  
  if(key)
  {
    
    info_recibida = info_recibida + key;
    Serial.println(key);
    lcdCerradura.setCursor(pos_lcd,1);
    lcdCerradura.print("*         ");
    pos_lcd++;
    if(key == '*')
    {
      lcdCerradura.setCursor(0,1);
      lcdCerradura.print("               ");

      if(info_recibida == contrasenaCerradura)
      {
        lcdCerradura.setCursor(0,1);
        lcdCerradura.print("Contrasena correcta");
        delay(1000);
        lcdCerradura.setCursor(0,1);
        lcdCerradura.print("Pue. Abierta      ");
        ON(led_verd);
        OFF(led_rojo);
        Serial.println("Contraseña correcta");
      }
      else
      {
        lcdCerradura.setCursor(0,1);
        lcdCerradura.print("Contrasena inco");
        delay(1000);
        lcdCerradura.setCursor(0,1);
        lcdCerradura.print("Pue. Cerrada      ");
        OFF(led_verd);
        ON(led_rojo);
        Serial.println("Contraseña incorrecta");
      }
      info_recibida = "";     //limpio el string
      delay(1000);
      lcdCerradura.setCursor(0,1);
      lcdCerradura.print("Pue. Cerrada      ");
      pos_lcd = 0;
    }
  }

}


void config_outputs(void)
{
  pinMode(pin_servo, OUTPUT);
  pinMode(pin_buzz, OUTPUT);
  pinMode(led_amar, OUTPUT);
  pinMode(led_rojo, OUTPUT);
  pinMode(led_verd, OUTPUT);
}

void config_HMI(void)
{
  ServoCerradura.attach(pin_servo);
  lcdCerradura.init();
  lcdCerradura.backlight();
  lcdCerradura.setCursor(2,0);
  lcdCerradura.print("Bienvenidos");
  lcdCerradura.setCursor(0,1);
  lcdCerradura.print("Pue. Cerrado      ");
}
