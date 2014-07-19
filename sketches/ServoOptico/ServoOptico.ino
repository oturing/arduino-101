#include <Servo.h> 
 
Servo meuservo;
 
int pos = 0;    // variavel com posicao do servo
int sensorOpticoEsq;
int sensorOpticoDir;

void setup() 
{ 
  meuservo.attach(9);  // servo no pino digital 9
} 
 
 
void loop() 
{ 
  sensorOpticoEsq = analogRead(A0); // manda valor do sensor optico para variavel
  sensorOpticoDir = analogRead(A1);
  
  if (sensorOpticoEsq < 100) {
  for(pos = 0; pos < 180; pos += 1)  // vai de 0 graus para 180 graus 
    {                                 // em incrementos de 1 grau 
    meuservo.write(pos);              // manda servo ir para posicao na variavel 'pos' 
    delay(15);                       // espera 15ms para o servo alcancar posicao 
    } 
  }
  
  if (sensorOpticoDir < 100) {
  for(pos = 180; pos>=1; pos-=1)     // vai de 180 graus para 0 graus 
    {                                
    meuservo.write(pos);              // manda servo ir para posicao na variavel 'pos' 
    delay(15);                       // espera 15ms para o servo alcancar posicao 
    } 
  }
  
} 
