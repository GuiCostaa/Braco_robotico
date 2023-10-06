#include "Arduino.h"
#include <Servo.h>


#define SERVO_BASE 9
#define SERVO_ESQUERDO 10
#define SERVO_DIREITO 8
#define SERVO_GARRA 7


#define MODO_DEBUG "$Debug,enable"
#define Motor_Base_next "$Base,next"
#define Motor_Esquerdo_next "$Esquerdo,next"
#define Motor_Direito_next "$Direito,next"
#define Motor_garra_next "$Garra,next"
#define Motor_Base_back "$Base,back" 
#define Motor_Esquerdo_back "$Esquerdo,back"
#define Motor_Direito_back  "$Direito,back"
#define Motor_garra_back "$Garra,back" 

bool DEBUG = false; 
int pos = 0;
int pos_neg = 0;

Servo servo_esquerdo;
Servo servo_direito;
Servo servo_base;
Servo servo_garra;

void setup() {
  servo_direito.attach(SERVO_DIREITO);
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  if (Serial.available() > 0) {
    String mensagem = Serial.readStringUntil('\n');
    int posicaoVirgula1 = mensagem.indexOf(',');
    posicaoVirgula1++;
    int tamanhoTotal = mensagem.length();
    int posicaoVirgula2 = mensagem.indexOf(',', posicaoVirgula1);
    String mensagem_fatiada = mensagem.substring(0, posicaoVirgula2);
    int posicaoVirgula2_posicao = posicaoVirgula2++;
    String mensagem_posicao = mensagem.substring(posicaoVirgula2,"\n");
    pos = mensagem_posicao.toInt();
    //mensagem.substring();
      //Serial.println(posicaoVirgula1);
    /*Serial.print("Tamanho total: ");
    Serial.println(tamanhoTotal);
    Serial.print("Posicao da virgula 1: ");
    Serial.println(posicaoVirgula1);
    Serial.print("Posicao da virgula 2: ");
    Serial.println(posicaoVirgula2);
    Serial.print("Mensagem fatiada: ");
    Serial.println(mensagem_fatiada);
    Serial.print("Mensagem posicao: ");
    Serial.println(mensagem_posicao);*/
    Serial.print(pos);

    if (mensagem == MODO_DEBUG) 
    {
      DEBUG = true;
      Serial.println("Modo de depuração ativado.");
    }
    else if (DEBUG && mensagem_fatiada == Motor_Esquerdo_next)
    {
      Serial.println("Esquerdo OK");
      pos = 10;
      servo_esquerdo.write(pos);
    }
    else if (DEBUG && mensagem_fatiada == Motor_Esquerdo_back)
    {
      Serial.println("Direita OK");
      pos_neg = pos * -1;
      servo_esquerdo.write(pos_neg);
    }
    else if (DEBUG && mensagem_fatiada == Motor_Direito_next)
    {
      servo_direito.write(pos);
      Serial.println("DIREITO OK");
      Serial.println(pos);
     /*   for (int i = 0; i <= 180; i += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
      servo_direito.write(i);   
      //Serial.println(myservo.read());// tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
  }*/
    }
    else if (DEBUG && mensagem_fatiada == Motor_Direito_back)
    {
      pos_neg = pos * -1;
      servo_direito.write(pos_neg);
    }
    else if (DEBUG && mensagem_fatiada == Motor_Base_next)
    {
      servo_base.write(pos);
    }
    else if (DEBUG && mensagem_fatiada == Motor_Base_back)
    {
      pos_neg = pos * -1;
      servo_base.write(pos_neg);
    }
  }
}
