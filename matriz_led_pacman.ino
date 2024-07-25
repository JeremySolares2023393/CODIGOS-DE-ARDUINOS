//Librerias
#include <LedControl.h>   //libreria que me permite usar el controlador led max7219

//Directivas de preprocesador
#define dataPin0   4   //pin 12 conectado al pin de datos del max7219.
#define dataLoad0  3   //pin 10 conectado al pin de carga del max7219.
#define dataClock0 2   //pin 11 conectado al pin de clock del max7219.


//Constructores
LedControl matrix_unidades = LedControl(dataPin0,dataClock0,dataLoad0,1);

int velocidad;

byte pacman_open[8]=
{
  B00111000,
  B01010100,
  B10001000,
  B10010000,
  B10001000,
  B01000100,
  B00111000,
  B00000000
};

byte pacman_close[8]=
{
  B00111000,
  B01010100,
  B10000010,
  B10011110,
  B10000010,
  B01000100,
  B00111000,
  B00000000
};

//Prototipos de funciones
void print_pacman_open(void);
void print_pacman_close(void);

void setup()
{
  Serial.begin(9600); //Inicio la comunicacion serial a 9600 baudios.
  matrix_unidades.shutdown(0,false); //Activo el max7219 para poder mostrar los digitos.
  matrix_unidades.setIntensity(0,30);  //Brilo a la mitad 
  matrix_unidades.clearDisplay(0);    //limpio el display
  Serial.println("Animacion con la matriz led");
  velocidad = 0;
}

void loop() 
{
 int pot = analogRead(A0);
 velocidad= map(pot, 0,1023,500,80);
  print_pacman_open();
  delay(velocidad);
  print_pacman_close();
  delay(velocidad);
}

void print_pacman_open(void)
{      
  for(int i=0; i<8;i++)
  {
    matrix_unidades.setRow(0,i,pacman_open[i]);
  }
}

void print_pacman_close(void)
{
  for(int i=0; i<8;i++)
  {
    matrix_unidades.setRow(0,i,pacman_close[i]);
  }
}
