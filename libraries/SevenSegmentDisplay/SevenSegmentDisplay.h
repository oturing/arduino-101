// multi-digit 7 segment display library

/* SevenSegmentDisplay.h

   ____
  | A |
F |   | B
  |___|
  | G |
E |   | C
  |___|    . 
    D      DP
*/

// ensure this library description is only included once
#ifndef SevenSegmentDisplay_h
#define SevenSegmentDisplay_h

class SevenSegmentDisplay {
  public:
    // 3-digit constructor
    SevenSegmentDisplay(int digit_0, int digit_1, int digit_2, 
      int seg_a, int seg_b, int seg_c, int seg_d, int seg_e, int seg_f, int seg_g, int seg_dp);
            
    void show(int number);
    
  private:
    void set_segments(int figure);
    void count_digits(int number);
    int total_digits;
    int current_number = 0;
    int active_digits = 1;
    int digit_pins[4];
    const int total_segments = 7;
    int segment_pins[7];
    int decimal_point_pin;
    const int total_figures = 10;
    const int figures[][7] = {
      //       A  B  C  D  E  F  G
      /* 0 */ {1, 1, 1, 1, 1, 1, 0},
      /* 1 */ {0, 1, 1, 0, 0, 0, 0},
      /* 2 */ {1, 1, 0, 1, 1, 0, 1},
      /* 3 */ {1, 1, 1, 1, 0, 0, 1},
      /* 4 */ {0, 1, 1, 0, 0, 1, 1},
      /* 5 */ {1, 0, 1, 1, 0, 1, 1},
      /* 6 */ {1, 0, 1, 1, 1, 1, 1},
      /* 7 */ {1, 1, 1, 0, 0, 0, 0},
      /* 8 */ {1, 1, 1, 1, 1, 1, 1},
      /* 9 */ {1, 1, 1, 1, 0, 1, 1},
    };
};

#endif
 
