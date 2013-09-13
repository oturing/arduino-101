/*
  SemaforoPot
  Controla tres leds com um potenciometro
 */
 
int led_vermelho = 2;
int led_amarelo = 3;
int led_verde = 4;
int led_aceso = led_vermelho;
 
void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
}
 
void loop() {
  int valor = analogRead(A0); // ler o valor do pot: 0...1023
  digitalWrite(led_aceso, LOW);
  if (valor < 333) {
    led_aceso = led_vermelho;
  } else if (valor < 666) {
    led_aceso = led_amarelo;
  } else {
    led_aceso = led_verde;
  }  
  digitalWrite(led_aceso, HIGH);
}
