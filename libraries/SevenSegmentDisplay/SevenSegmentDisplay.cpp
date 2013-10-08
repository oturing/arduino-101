#include "Arduino.h"
#include "SevenSegmentDisplay.h"


// 3-digit constructor
SevenSegmentDisplay::SevenSegmentDisplay(int digit_0, int digit_1, int digit_2, 
      int seg_a, int seg_b, int seg_c, int seg_d, int seg_e, int seg_f, int seg_g, int seg_dp)
{
  this->total_digits = 3;
  this->current_number = 0;
  this->active_digits = 1;
  this->digit_pins[0] = digit_0;
  this->digit_pins[1] = digit_1;
  this->digit_pins[2] = digit_2;
  this->segment_pins[0] = seg_a;
  this->segment_pins[1] = seg_b;
  this->segment_pins[2] = seg_c;
  this->segment_pins[3] = seg_d;
  this->segment_pins[4] = seg_e;
  this->segment_pins[5] = seg_f;
  this->segment_pins[6] = seg_g;
  this->decimal_point_pin = seg_dp;
  // setup
  int i;
  // configure and turn off all digits
  for(i=0; i<this->total_digits; i++) {
    pinMode(digit_pins[i], OUTPUT);
    digitalWrite(digit_pins[i], LOW);
  }
  // configure and turn off all segments
  for(i=0; i<this->total_segments; i++) {
    pinMode(segment_pins[i], OUTPUT);
    // 5V at cathode -> no current flows in the segment
    digitalWrite(segment_pins[i], HIGH);
  }
}

void SevenSegmentDisplay::show(int number) {
  for (int d=0; d<this->active_digits; d++) {
    int rest = number % 10;
    number /= 10;
    // activate digit: +5V to anode
    digitalWrite(digit_pins[d], HIGH);
    set_segments(rest);
    // testing has shown that this small delay increases
    // brightness without visible flicker
    delay(3);
    // turn off all segments
    set_segments(-1);
    // turn off digit 
    digitalWrite(digit_pins[d], LOW);
  }
}

void SevenSegmentDisplay::set_segments(int figure) {
  /* use figure -1 to turn off all segments */
  for (int s=0; s<this->total_segments; s++) {
    if (figure >= 0 && figures[figure][s]) {
      // 0V at cathode -> current flows in the segment
      digitalWrite(segment_pins[s], LOW);
    } else {
      // 5V at cathode -> no current flows in the segment
      digitalWrite(segment_pins[s], HIGH);
    }
  }
}

int SevenSegmentDisplay::count_digits(int n) {
  /* count number of digits in n >= 0 */
  int digits = 0;
  if (n == 0) return 1;
  while (n > 0) {
    digits++;
    n /= 10;
  }
  return digits;
}
