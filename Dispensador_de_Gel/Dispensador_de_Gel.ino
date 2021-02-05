const int servo = 9;     //define 'Servo Signal Pin'
const int trigPin = 10;  //define 'Trigger Pin'
const int echoPin = 11;  //define 'Echo Pin'

// define variables
long duration;
int distance;

#include <Servo.h>

Servo myservo;    // Crea una variable para controlar el servo

int pos = 0;    // Variable para almacenar la posicion del servo

void setup() {
  pinMode(trigPin, OUTPUT);    // Establece a 'trigPin' como Salida
  pinMode(echoPin, INPUT);    // Establece a 'echoPin' como Entrada
  myservo.attach(servo);     // Acopla al servo en el pin 9  
  myservo.write(0);         // Sets Servo to initially 0 degrees 
  Serial.begin(9600);      // Comienza la comunicacion serial
}

void loop() {
    //
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Establece a 'trigPin' en estado alto (HIGH) por 10 microsegundos
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Lectura del 'echoPin', retorna el tiempo de viaje de la onda ultrasonica en microsegundos
    duration = pulseIn(echoPin, HIGH);
    
    // Calculando la distancia
      distance= duration*0.034/2;
    
    // Imprime la distancia en el monitor serial
    Serial.print("Distance: ");
    Serial.println(distance);
    
    //Servo    
    if(distance<10)
    { //Revision: que la distancia sea menos que 10cm 
       myservo.write(45); // Establece el Servo en etapas de 0 a 180 grados para que el jabon no salga 
       delay(100);
       myservo.write(90);
       delay(100);
        myservo.write(135);
       delay(100);
       myservo.write(120); //Ajuste que tan lejos quiere que llegue el servo
       delay(1000);
       myservo.write(00); // Reinicia el servo a 0 Degrees
       delay(2500);   //Retrasa la proxima vez que alguien pueda conseguir jabon en milisegundos
    }                 
}
