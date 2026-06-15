//definindo as bibliotecas
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
#include <Servo.h>

//definindo o servo
Servo servo;

//pino do servo 
int pServo = 11;

//definindo os pinos
const int P1 = 4;
const int P2 = 5;
const int P3 = 6;
const int P4 = 7;

//definindo os pinos PWM
const int A00 = 9;
const int A01 = 10;

//definindo a potência das setinhas
const int potencia_setinhas = 255;

//definindo a potência das setinhas (Curva)
const int potencia_setinhas_curva = 255;

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
}


void ativar_servo(int pino){
  if(servo.attached()){
    servo.detach();
  }
  servo.attach(pino);
  for(int n = 0; n < 90; n++){
    servo.write(n);
    delay(2);
  }
  for(int n = 90; n > 0; n--){
    servo.write(n);
    delay(2);
  }
  servo.detach();
}



void loop(){
  Dabble.processInput(); //atualiza os dados recebidos
  //------ SETINHAS ------//
 
  //Frente
  if (GamePad.isUpPressed()){
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
    digitalWrite(P3, HIGH);
    digitalWrite(P4, LOW);

    analogWrite(A00, potencia_setinhas);
    analogWrite(A01, potencia_setinhas);
  }

  //Trás
  else if (GamePad.isDownPressed()){
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
    digitalWrite(P3, LOW);
    digitalWrite(P4, HIGH);

    analogWrite(A00, potencia_setinhas);
    analogWrite(A01, potencia_setinhas);
  }

  //Direita
  else if (GamePad.isRightPressed()){
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
    digitalWrite(P3, LOW);
    digitalWrite(P4, HIGH);

    analogWrite(A00, potencia_setinhas_curva);
    analogWrite(A01, potencia_setinhas_curva);
  }

  //ativar servo
  else if(GamePad.isTrianglePressed()){
    ativar_servo(pServo);
  }

  //Esquerda
  else if (GamePad.isLeftPressed()){
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
    digitalWrite(P3, HIGH);
    digitalWrite(P4, LOW);

    analogWrite(A00, potencia_setinhas_curva);
    analogWrite(A01, potencia_setinhas_curva);
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


  delay(20);
}
