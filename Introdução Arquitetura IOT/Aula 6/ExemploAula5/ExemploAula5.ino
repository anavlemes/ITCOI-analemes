// C++ code
//

#include <Servo.h>
Servo meuServo;
int botao = 7;

void setup()
{
  //define o botao como entrada
  pinMode(botao, INPUT_PULLUP);
}

void loop()
{
  meuServo.attach(9);
  if (digitalRead (botao) == LOW)
  { 
    for ( int angulo = 0; angulo <= 180; angulo++)
    {
      meuServo.write(angulo);
        delay(10);
    }
    delay(10);
    
    for(int angulo = 180; angulo >= 0; angulo--)
    {
      meuServo.write(angulo);
      delay(10);
    }
  }
  
  meuServo.detach();
}
