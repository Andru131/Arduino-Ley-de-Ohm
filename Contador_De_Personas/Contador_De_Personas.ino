#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal

LiquidCrystal_I2C lcd(0x27,16,2); // importa libreria LiquidCrystal

int pinIN = 8; // Crea Variable pinIN y la asocia al pin digital 8
int valorIN = 0; // Crea Variables con un valor inicial asociado
int contenido = 0;

void setup()
{
lcd.backlight();
lcd.init(); // inicializa lcd en 16 columnas por 2 filas
// entradas analógicas no requieren inicialización

lcd.setCursor(5,0); 
lcd.print("AFORO"); // Imprime DETECTOR” sobre el LCD
delay(1000); // Espera 1 segundo
lcd.setCursor(4,0); // Seteamos la ubicacion texto 0 linea 1 que sera escrita sobre el LCD
delay(1500);
lcd.clear(); // Limpia la pantalla
delay(300);

lcd.setCursor(4,0); // Seteamos la ubicacion del texto 1, linea 0 que sera escrita sobre el LCD
lcd.print("PERSONAS"); // Imprime “CUENTA OBJETOS” sobre el LCD
lcd.setCursor(2,1);
lcd.print("CANTIDAD: ");

}

void loop()
{
valorIN=digitalRead(pinIN); // Realiza la lectura Digital del pin 8
if(valorIN!=1) // Si la lectura es 1 incremente el valor de contenido
{
contenido++;
while(digitalRead(pinIN)!=1) {
delay(100); // Realiza un Delay para estabilizar
}
lcd.setCursor(12,1); // Ubicamos el cursor en la posicion 12 sobre la linea 1
lcd.print(contenido); // Imprimimos el valor del contenido sobre dicha ubicacion

}
}
