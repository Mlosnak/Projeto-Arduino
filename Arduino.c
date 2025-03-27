#include <Servo.h>

// Definir os servos
Servo servoBase;    // Movimento lateral (esquerda/direita)
Servo servoGarra;   // Pegar/largar

// Pinos dos servos
int pinoServoBase = 9;
int pinoServoGarra = 10;

// Pinos dos botões (ajuste conforme sua montagem)
int btnEsquerda = 2;
int btnDireita = 3;
int btnPegar = 4;
int btnLargar = 5;

// Posições iniciais
int posBase = 90;   // Posição central (0-180)
int posGarra = 90;  // 90 = garra fechada

void setup() {
  servoBase.attach(pinoServoBase);
  servoGarra.attach(pinoServoGarra);
  
  pinMode(btnEsquerda, INPUT_PULLUP);
  pinMode(btnDireita, INPUT_PULLUP);
  pinMode(btnPegar, INPUT_PULLUP);
  pinMode(btnLargar, INPUT_PULLUP);
  
 
  servoBase.write(posBase);
  servoGarra.write(posGarra);
  delay(1000);
}

void loop() {

  if (digitalRead(btnEsquerda) == LOW) {
    moverEsquerda();
  }
  if (digitalRead(btnDireita) == LOW) {
    moverDireita();
  }
  if (digitalRead(btnPegar) == LOW) {
    pegarObjeto();
  }
  if (digitalRead(btnLargar) == LOW) {
    largarObjeto();
  }
  delay(50); 
}

void moverEsquerda() {
  if (posBase > 0) {
    posBase -= 10; 
    servoBase.write(posBase);
    delay(100);
  }
}

void moverDireita() {
  if (posBase < 180) {
    posBase += 10;
    servoBase.write(posBase);
    delay(100);
  }
}

void pegarObjeto() {
  for (int i = 90; i >= 45; i--) { 
    servoGarra.write(i);
    delay(15);
  }
}

void largarObjeto() {
  for (int i = 45; i <= 90; i++) { 
    servoGarra.write(i);
    delay(15);
  }
}