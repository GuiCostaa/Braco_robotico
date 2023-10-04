#include "Arduino.h"
#include <Servo.h>

#define SERVO_BASE 9
#define SERVO_ESQUERDO 10
#define SERVO_DIREITO 8
#define SERVO_GARRA 7


#define MODO_DEBUG "$Debug,enable"
#define Motor_Base "$Base"
#define Motor_Esquerdo "$Esquerdo"
#define Motor_Direito "$Direito"
#define Motor_garra "$Garra"

bool DEBUG = false; 

Servo 

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String mensagem = Serial.readStringUntil('\n');
    int posicaoVirgula1 = mensagem.indexOf(',');

    if (mensagem == MODO_DEBUG) 
    {
      DEBUG = true;
      Serial.println("Modo de depuração ativado.");
    }
    else if (DEBUG && )
  }
}