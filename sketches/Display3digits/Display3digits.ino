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
int numero = 850; // numero a ser exibido
int qt_digitos_ativos;   // quantidade de digitos em uso
unsigned long INTERVALO = 100; // intervalo entre incrementos do numero
unsigned long atualizacao; // momento da atualizacao mais recente


void setup() {                
  int i;
  // configurar e desativar todos os digitos
  for(i=0; i<NUM_DIGITOS; i++) {
    pinMode(pinos_digitos[i], OUTPUT);
    digitalWrite(pinos_digitos[i], LOW);
  }
  // configurar e desativar todos os segmentos
  for(i=0; i<NUM_SEGMENTOS; i++) {
    pinMode(pinos_segmentos[i], OUTPUT);
    // 5V no catodo zera a corrente no segmento
    digitalWrite(pinos_segmentos[i], HIGH);
  }
  atualizacao = millis();
}

int contar_digitos(int n) {
  // calcular quantidade de digitos no numero atual
  int digitos = 0;
  while (n > 0) {
    digitos++;
    n /= 10;
  }
  return digitos;
}

void configurar_segmentos(int algarismo) {
  // usar algarismo -1 para desativar todos os segmentos
  for (int s=0; s<NUM_SEGMENTOS; s++) {
    if (algarismo >= 0 && algarismos[algarismo][s]) {
      // ativar segmento: GND no catodo
      digitalWrite(pinos_segmentos[s], LOW);
    } else {
      // desativar segmento: +5V no catodo
      digitalWrite(pinos_segmentos[s], HIGH);
    }
  }
}

void loop() {
  // percorrer digitos a partir do mais significativo
  // for (int d=qt_digitos-1; d>=0; d--) {
  // percorrer digitos a partir do menos significativo
  for (int d=0; d<qt_digitos_ativos; d++) {
    // ativar digito: +5V no anodo
    digitalWrite(pinos_digitos[d], HIGH);
    int resto = (numero / (int)pow(10, d)) % 10;
    configurar_segmentos(resto);
    // empiricamente verifiquei que este pequeno atraso 
    // maximiza o brilho e nao produz flicker visivel
    delay(3);
    // desativar todos os segmentos
    for (int s=0; s<NUM_SEGMENTOS; s++) {
      digitalWrite(pinos_segmentos[s], HIGH);
    }
   // desativar digito 
    digitalWrite(pinos_digitos[d], LOW);
  }
  unsigned long agora = millis();
  int qt_digitos;
  if ((agora - atualizacao) > INTERVALO) {
     numero = numero < (int)(pow(10, NUM_DIGITOS)-1) ? numero + 1 : 0;
     qt_digitos = contar_digitos(numero);
     if (qt_digitos != qt_digitos_ativos) {
       for (int d = 0; d < NUM_DIGITOS; d++) {
         if (d < qt_digitos) {
           // escrever zeros
           configurar_segmentos(0);      
         } else {
           // apagar digito
           configurar_segmentos(-1);
         }
       }
       qt_digitos_ativos = qt_digitos;
     }
     atualizacao = agora;
  }
}
