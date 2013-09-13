/*

- make LED in pin 13 blink
- make some other segment blink
- map the other segments
- alternate between two segments
- fix dim led by setting it to OUTPUT inside setup()
- remove delay between switching leds
- refactor led lighting code to separate function
- rotate the lighting around the perimeter
- fix bug where led 12 would also blink
- read the delay from the knob

 */
 
int leds[] = {7, 8, 9, 11, 12, 13};

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for (int i = 0; i < 6; ++i) {
    pinMode(leds[i], OUTPUT);
  }    
}

void showLed(int led, int the_delay) {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(the_delay);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
}

// the loop routine runs over and over again forever:
void loop() {
  int the_delay = 0;
  for (int i = 0; i < 6; ++i) {
    int the_delay = analogRead(A0);
    showLed(leds[i], the_delay);
  }
}
