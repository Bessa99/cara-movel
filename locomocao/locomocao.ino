//definindo as bibliotecas
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

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
const int potencia_setinhas_curva = 200;

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

  //------ JOYSTICK ------//

  //obtendo os dados do eixo x e y
  float x = GamePad.getXaxisData();
  float y = GamePad.getYaxisData();

  //mapeando os dados de y para PWM
  int velocidade = map(abs(y), 0, 7, 0, 255);

  //limite de velocidade
  if (velocidade > 255) {velocidade = 255;}

  //Parar
  if (abs(x) < 1.0 && abs(y) < 1.0){
    digitalWrite(P1, LOW);  
    digitalWrite(P2, LOW);
    digitalWrite(P3, LOW);  
    digitalWrite(P4, LOW);
   
    analogWrite(A00, 0);      
    analogWrite(A01, 0);
  }

  //Frente
  else if (y > 1.0 && abs(x) <= 3.0){
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
    digitalWrite(P3, HIGH);
    digitalWrite(P4, LOW);

    analogWrite(A00, velocidade);
    analogWrite(A01, velocidade);
  }

  //Trás
  else if ( y < -1.0 && abs(x) <= 3.0){
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
    digitalWrite(P3, LOW);
    digitalWrite(P4, HIGH);

    analogWrite(A00, velocidade);
    analogWrite(A01, velocidade);
  }

  //Frente e Direita
    else if (y > 3.0 && x > 3.0){
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
    digitalWrite(P3, HIGH);
    digitalWrite(P4, LOW);

    analogWrite(A00, velocidade);
    analogWrite(A01, velocidade/1.5);
  }

  //Frente e Esquerda
    else if (y > 3.0 && x < -3.0){
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
    digitalWrite(P3, HIGH);
    digitalWrite(P4, LOW);

    analogWrite(A00, velocidade/1.5);
    analogWrite(A01, velocidade);
  }

  //Trás e Direita
    else if (y < -3.0 && x > 3.0){
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
    digitalWrite(P3, LOW);
    digitalWrite(P4, HIGH);

    analogWrite(A00, velocidade);
    analogWrite(A01, velocidade/1.5);
  }

  //Trás e Esquerda
    else if (y < -3.0 && x < -3.0){
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
    digitalWrite(P3, LOW);
    digitalWrite(P4, HIGH);

    analogWrite(A00, velocidade/1.5);
    analogWrite(A01, velocidade);
  }

  //Direita
  else if (x > 3){
    int velocidade_curva = map(abs(x), 0, 7, 0, 255);
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
    digitalWrite(P3, LOW);
    digitalWrite(P4, HIGH);

    analogWrite(A00, velocidade_curva);
    analogWrite(A01, velocidade_curva);
  }

  //Esquerda
  else if (x < -3){
    int velocidade_curva = map(abs(x), 0, 7, 0, 255);
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
    digitalWrite(P3, HIGH);
    digitalWrite(P4, LOW);

    analogWrite(A00, velocidade_curva);
    analogWrite(A01, velocidade_curva);
  }

  delay(20);
}


