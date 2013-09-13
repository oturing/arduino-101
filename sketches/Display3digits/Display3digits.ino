/*
  Display3digits

  Controle de um display de 7 segmentos com 3 digitos. 
*/
 
int pinos_digitos[] = {13, 12, 9};
int NUM_DIGITOS = 3;  
//  segmentos datasheet  A  B   C   D   E   F  G
int pinos_segmentos[] = {10, 11, 5,  7,  6, 4, 3};
int NUM_SEGMENTOS = 7;  
int pino_ponto = 8; // dp: decimal point
int algarismos [][7] = {
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
  /* 9 */ {1, 1, 1, 0, 0, 1, 1},
};

int NUM_ALGARISMOS = 10;

void setup() {                
  int i;
  for(i=0; i<NUM_DIGITOS; i++) {
    pinMode(pinos_digitos[i], OUTPUT);
    digitalWrite(pinos_digitos[i], LOW);
  }
  for(i=0; i<NUM_SEGMENTOS; i++) {
    pinMode(pinos_segmentos[i], OUTPUT);
    digitalWrite(pinos_segmentos[i], HIGH);
  }
}

//     segmentos datasheet  A  B   C   D   E   F  G
// int pinos_segmentos[] = {10, 11, 5,  7,  6, 4, 3};

void loop() {
  int digito = 0;
  digitalWrite(pinos_digitos[digito], HIGH);
  //for (int i=0; i<NUM_SEGMENTOS; i++) {
  int seg = 8;
  digitalWrite(seg, LOW);
  delay(1000);
  digitalWrite(seg, HIGH);
  delay(1000);
}
