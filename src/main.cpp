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
#define READ_POSITION "$Read"

bool DEBUG = false; 
int pos = 0;
int pos_neg = 0;

Servo servo_esquerdo;
Servo servo_direito;
Servo servo_base;
Servo servo_garra;

void read_position();

void setup() {
  servo_direito.attach(SERVO_DIREITO);
  servo_base.attach(SERVO_BASE);
  servo_esquerdo.attach(SERVO_ESQUERDO);
  servo_garra.attach(SERVO_GARRA);
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() 
{
 
if (Serial.available() > 0) {
    String mensagem = Serial.readStringUntil('\n');
    int posicaoVirgula1 = mensagem.indexOf(','); 
    String mensagem_fatiada = mensagem.substring(0, posicaoVirgula1);
    posicaoVirgula1++;
  
    int tamanhoTotal = mensagem.length();
    String mensagem_posicao = mensagem.substring(posicaoVirgula1, tamanhoTotal);
    pos = mensagem_posicao.toInt();
    
    
    /*Serial.print("Tamanho total: ");
    Serial.println(tamanhoTotal);
    Serial.print("Posicao da virgula 1: ");
    Serial.println(posicaoVirgula1);
    Serial.print("Posicao: ");
    Serial.println(mensagem_posicao);
    Serial.println(pos);
    Serial.print("Mensagem fatiada: ");
    Serial.println(mensagem_fatiada);
    */

    if (mensagem == MODO_DEBUG) 
    {
      DEBUG = true;
      Serial.println("Modo de depuracao ativado.");
    }
    else if (DEBUG && mensagem_fatiada == Motor_Esquerdo)
    {
      Serial.println("Esquerdo OK");
      servo_esquerdo.write(pos);
    }
    else if (DEBUG && mensagem_fatiada == Motor_Direito)
    {
      servo_direito.write(pos);
      Serial.println("DIREITO OK");
      //Serial.println(pos);
    }

    else if (DEBUG && mensagem_fatiada == Motor_Base)
    {
      Serial.println("BASE OK");
      //Serial.println(servo_base.read());
      servo_base.write(pos);
    }
    else if (READ_POSITION)
    {
      read_position();
    }
  }
}

void read_position()
{
  Serial.print("Servo da base: ");
  Serial.println(servo_base.read());
  Serial.print("Servo Direito: ");
  Serial.println(servo_direito.read());
  Serial.print("Servo Esquerdo: "); 
  Serial.println(servo_esquerdo.read());
  Serial.print("Servo da Garra: ");
  Serial.println(servo_garra.read());

}