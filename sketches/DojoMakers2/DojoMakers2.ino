/*

- determinar qual segmento esta ligado ao pino 13
- " pino 12
- " pino 11
- " pino 10
- " pino 9
- " pino 8
- " pino 7
- alterar a frequencia de acordo com o potenciometro
- fazer piscar o led A e o led B alternadamente
- alternar mais 3 leds C,D e E
- Incluir o led F ao circuito
- Atualizar mais rapidamente o valor do potenciometro

   A 
   --
F |  | B = 13
  |__|
E |G | C
  |__| . 
   D
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int ledB = 13; // B
int ledA = 12;  // A
int ledF = 11; // F
int ledG = 10; //G
int ledE = 9;
int ledD = 8;
int ledC = 7;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(ledA, OUTPUT);  
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);  
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);  
  pinMode(ledF, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  int sensorValue = analogRead(A0);
  digitalWrite(ledA, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(sensorValue);               // wait for a second
  digitalWrite(ledA, LOW);    // turn the LED off by making the voltage LOW
  
  sensorValue = analogRead(A0);
  digitalWrite(ledB, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(sensorValue);               // wait for a second
  digitalWrite(ledB, LOW);    // turn the LED off by making the voltage LOW
  
  sensorValue = analogRead(A0);
  digitalWrite(ledC, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(sensorValue);               // wait for a second
  digitalWrite(ledC, LOW);    // turn the LED off by making the voltage LOW
  
  sensorValue = analogRead(A0);
  digitalWrite(ledD, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(sensorValue);               // wait for a second
  digitalWrite(ledD, LOW);               // wait for a second
  
  sensorValue = analogRead(A0);
  digitalWrite(ledE, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(sensorValue);               // wait for a second
  digitalWrite(ledE, LOW);    // turn the LED off by making the voltage LOW
  
  sensorValue = analogRead(A0);
  digitalWrite(ledF, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(sensorValue);               // wait for a second
  digitalWrite(ledF, LOW);
}
