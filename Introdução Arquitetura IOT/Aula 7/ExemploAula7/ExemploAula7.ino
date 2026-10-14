#include <Servo.h>


Servo meuServo;


const int pinoPotenciometro = A0;
const int pinoServo = 9;

void setup() {
  
  meuServo.attach(pinoServo);
}

void loop() {
  
  int valorPot = analogRead(pinoPotenciometro);

  
  valorPot = map(valorPot, 0, 1023, 50, 110);

  
  meuServo.write(valorPot);

  
  delay(15);
}
