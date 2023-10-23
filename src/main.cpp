#include "Arduino.h"
#include <Servo.h>


#define SERVO_BASE 9
#define SERVO_ESQUERDO 10
#define SERVO_DIREITO 8
#define SERVO_GARRA 7


#define MODO_DEBUG "$Debug,enable"
<<<<<<< HEAD
#define Motor_Base "$Base"
#define Motor_Esquerdo "$Esquerdo"
#define Motor_Direito "$Direito"
#define Motor_garra "$Garra"
#define READ_POSITION "$Read"
=======
#define Motor_Base_next "$Base,next"
#define Motor_Esquerdo_next "$Esquerdo,next"
#define Motor_Direito_next "$Direito,next"
#define Motor_garra_next "$Garra,next"
#define Motor_Base_back "$Base,back" 
#define Motor_Esquerdo_back "$Esquerdo,back"
#define Motor_Direito_back  "$Direito,back"
#define Motor_garra_back "$Garra,back" 
>>>>>>> 2429df8bf817fa21f9b25a31b5a27560110081d4

bool DEBUG = false; 
int pos = 0;
int pos_neg = 0;

Servo servo_esquerdo;
Servo servo_direito;
Servo servo_base;
Servo servo_garra;
<<<<<<< HEAD

void read_position();

void setup() {
  servo_direito.attach(SERVO_DIREITO);
  servo_base.attach(SERVO_BASE);
  servo_esquerdo.attach(SERVO_ESQUERDO);
  servo_garra.attach(SERVO_GARRA);
=======

void setup() {
  servo_direito.attach(SERVO_DIREITO);
>>>>>>> 2429df8bf817fa21f9b25a31b5a27560110081d4
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() 
{
 
if (Serial.available() > 0) {
    String mensagem = Serial.readStringUntil('\n');
<<<<<<< HEAD
    int posicaoVirgula1 = mensagem.indexOf(','); 
    String mensagem_fatiada = mensagem.substring(0, posicaoVirgula1);
    posicaoVirgula1++;
  
    int tamanhoTotal = mensagem.length();
    String mensagem_posicao = mensagem.substring(posicaoVirgula1, tamanhoTotal);
    pos = mensagem_posicao.toInt();
    
    
=======
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
>>>>>>> 2429df8bf817fa21f9b25a31b5a27560110081d4
    /*Serial.print("Tamanho total: ");
    Serial.println(tamanhoTotal);
    Serial.print("Posicao da virgula 1: ");
    Serial.println(posicaoVirgula1);
<<<<<<< HEAD
    Serial.print("Posicao: ");
    Serial.println(mensagem_posicao);
    Serial.println(pos);
    Serial.print("Mensagem fatiada: ");
    Serial.println(mensagem_fatiada);
    */
=======
    Serial.print("Posicao da virgula 2: ");
    Serial.println(posicaoVirgula2);
    Serial.print("Mensagem fatiada: ");
    Serial.println(mensagem_fatiada);
    Serial.print("Mensagem posicao: ");
    Serial.println(mensagem_posicao);*/
    Serial.print(pos);
>>>>>>> 2429df8bf817fa21f9b25a31b5a27560110081d4

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
<<<<<<< HEAD
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
=======
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
>>>>>>> 2429df8bf817fa21f9b25a31b5a27560110081d4
