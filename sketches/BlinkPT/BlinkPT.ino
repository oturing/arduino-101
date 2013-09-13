
 /*
   Piscar
   Pisca um led
  */
 
 // associar nome 'led' ao numero 13
 int led = 13;

 // executada 1 vez quando Arduino reseta
 void setup() {                
   // inicializar pino do led como saida
   pinMode(led, OUTPUT);     
 }

 // executada repetidamente "para sempre"
 void loop() {
   digitalWrite(led, HIGH); // ligar LED
   delay(1000);             // esperar 1s
   digitalWrite(led, LOW);  // desligar
   delay(1000);             // esperar 1s
 }
