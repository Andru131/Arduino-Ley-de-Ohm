#include <LiquidCrystal_I2C.h> // Debe descargar la Librería que controla el I2C
#include<Wire.h>

LiquidCrystal_I2C lcd(0x3f,16,2);

const int sensorPin = A0;
const int R=4;
const int G=3;
const int B=2;

void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.begin(16,2);
  
  Serial.begin(9600);
  pinMode(R,OUTPUT);//Inicializar el pin 4 como salida
  pinMode(G,OUTPUT);//Inicializar el pin 3 como salida
  pinMode(B,OUTPUT);//Inicializar el pin 2 como salida

   //El led inicie apagado
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
}
 
void loop()
{
  float valueAdc = analogRead(sensorPin);
  float volts = (valueAdc / 1023.0) * 5;
  float celsius = volts * 100.00; 
  
  if(celsius>26 && celsius<30){
    digitalWrite(R,LOW);
    digitalWrite(G,LOW);
    digitalWrite(B,HIGH);
    delay(1000);
    
  }
  if(celsius>=30 && celsius<=36){
    digitalWrite(R,LOW);
    digitalWrite(G,HIGH);
    digitalWrite(B,LOW);
    delay(1000);
  }
    if(celsius>=37 && celsius<=40){
    digitalWrite(R,HIGH);
    digitalWrite(G,LOW);
    digitalWrite(B,LOW);
    delay(1000); 

  }

   lcd.clear();
   lcd.home();
   lcd.print("Temperatura:");
   lcd.setCursor(0,1);
   lcd.print(celsius);
   lcd.print(" grados C");
   delay(1000);
}
