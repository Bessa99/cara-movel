//definindo as bibliotecas
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>

//definindo o servo do tiro
Servo servo;

//pino do servo 
const int pServo = 11;

//definindo servo do ajuste
Servo servoAjuste;

//pino do servo de ajuste
const int pinoServoAjuste = 8;

//angulo do servo de ajuste
int angulo = 90;


//definindo os pinos
const int P1 = 4;
const int P2 = 5;
const int P3 = 6;
const int P4 = 7;

//definindo o pino do motor de corrente contínua e variável ON/OFF
const int pino_motores = 12;
bool ligado = false;
//variavel para o botão quadrado
bool ultimoEstadoQuadrado = false;


//definindo os pinos PWM
const int A00 = 9;
const int A01 = 10;

//definindo a potência das setinhas
const int potencia_setinhas = 255;


void setup(){
  //iniciando
  Serial.begin(9600);
  Dabble.begin(9600);
  //configurando os pinos
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  pinMode(P3, OUTPUT);
  pinMode(P4, OUTPUT);
  pinMode(A00, OUTPUT);
  pinMode(A01, OUTPUT);
  pinMode(pino_motores, OUTPUT);
  pinMode(pinoServoAjuste, OUTPUT);

  //anexando pinos dos servos
  servo.attach(pServo);
  servoAjuste.attach(pinoServoAjuste);

  //organizando os angulos inicias dos servos
  servo.write(75);
  servoAjuste.write(angulo);
}


void ativar_servo(bool ligado){
    for(int n = 75; n > 20; n--){
      servo.write(n);
      delay(5);
    }
    for(int n = 20; n < 75; n++){
      servo.write(n);
      delay(5);
    }

}

bool ativar_motores(int pino){
  if (!ligado){
    ligado = true;
    digitalWrite(pino, 1);
  }
  return true;
}

bool desativar_motores(int pino){
  if(ligado){
    ligado = false;
    digitalWrite(pino, 0);
  }
  return false;
}


void loop(){
  Dabble.processInput(); //atualiza os dados recebidos
  //------ SETINHAS ------//
 
  //Frente
  if (GamePad.isUpPressed()){
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
    digitalWrite(P3, HIGH);
    digitalWrite(P4, LOW);

    analogWrite(A00, potencia_setinhas);
    analogWrite(A01, potencia_setinhas);
  }

  //Trás
  else if (GamePad.isDownPressed()){
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
    digitalWrite(P3, LOW);
    digitalWrite(P4, HIGH);

    analogWrite(A00, potencia_setinhas);
    analogWrite(A01, potencia_setinhas);
  }

  //Direita
  else if (GamePad.isRightPressed()){
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
    digitalWrite(P3, HIGH);
    digitalWrite(P4, LOW);

    analogWrite(A00, potencia_setinhas);
    analogWrite(A01, potencia_setinhas);
  }

  //Esquerda
  else if (GamePad.isLeftPressed()){
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
    digitalWrite(P3, LOW);
    digitalWrite(P4, HIGH);

    analogWrite(A00, potencia_setinhas);
    analogWrite(A01, potencia_setinhas);
  }

  //Parar
  else{
    digitalWrite(P1, LOW);
    digitalWrite(P2, LOW);
    digitalWrite(P3, LOW);
    digitalWrite(P4, LOW);

    analogWrite(A00, 0);
    analogWrite(A01, 0);
  }

  //------ AÇÕES ------//

  bool atualEstadoQuadrado = GamePad.isSquarePressed();

  //ativar servo
  if(GamePad.isTrianglePressed()){
    ativar_servo(ligado);
  }

  //ativar ou desativar motores
  else if(atualEstadoQuadrado && !ultimoEstadoQuadrado){
    if(!ligado){
      ligado = ativar_motores(pino_motores);
    } else if(ligado){
      ligado = desativar_motores(pino_motores);
    }
  }
  ultimoEstadoQuadrado = atualEstadoQuadrado;

  //mover torreta para cima
  if(GamePad.isCrossPressed()){
    angulo++;
  }

  //mover torreta para baixo
  else if(GamePad.isCirclePressed()){
    angulo--;
  }

  //limita o angulo entre 90 e 110
  if(angulo > 110){
    angulo = 110;
  }
  else if(angulo < 90){
    angulo = 90;
  }

  servoAjuste.write(angulo);

  delay(20);
}
