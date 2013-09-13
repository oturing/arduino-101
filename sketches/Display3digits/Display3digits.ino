/*
  Display3digits

  Controle de um display de 7 segmentos com 3 digitos. 
*/
 
int pinos_digitos[] = {4, 3, 2};
int NUM_DIGITOS = 3;  
//  segmentos datasheet  A   B   C   D   E   F   G
int pinos_segmentos[] = {8,  6, 10, 12, 13,  7,  9};
int NUM_SEGMENTOS = 7;  
int pino_ponto = 11; // dp: decimal point
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
  /* 9 */ {1, 1, 1, 1, 0, 1, 1},
};

int NUM_ALGARISMOS = 10;
int numero;
int qt_digitos;
unsigned long atraso = 500;
unsigned long atualizacao;


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
  atualizacao = millis();
  numero = 0;
}

void loop() {
  qt_digitos = (int)(log(numero) / log(10)) + 1;
  for (int d=qt_digitos-1; d>=0; d--) {
    int resto = (numero / (int)pow(10, d)) % 10;
    digitalWrite(pinos_digitos[d], HIGH);
    for (int s=0; s<NUM_SEGMENTOS; s++) {
      if (algarismos[resto][s]) {
        digitalWrite(pinos_segmentos[s], LOW);
      }
    }
    delay(3);
    for (int s=0; s<NUM_SEGMENTOS; s++) {
      digitalWrite(pinos_segmentos[s], HIGH);
    } 
    digitalWrite(pinos_digitos[d], LOW);
  }
  unsigned long agora = millis();
  if ((agora - atualizacao) > atraso) {
     numero = numero < (int)(pow(10, NUM_DIGITOS)-1) ? numero + 1 : 0;
     atualizacao = agora;
  }
}
