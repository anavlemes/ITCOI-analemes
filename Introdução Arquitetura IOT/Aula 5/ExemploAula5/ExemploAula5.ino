//Definir Variaveis
int botao = 2;
int led_verm = 3;
int led_azul = 4; //Defini cada componente em suas respectivas portas
int led_verd = 5;
int valor_botao = 0;
//Fase de setup
void setup()
{
  pinMode(botao, INPUT_PULLUP);
  pinMode(led_verm, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_verd, OUTPUT);
}
void ligarVerm(int verm,int azul,int verd){
    digitalWrite(verm, HIGH);
      digitalWrite(azul, LOW);
      digitalWrite(verd, LOW);
}
//Feito à mão por José Gabriel Soares Menon - 22
void ligarAzul(int verm,int azul,int verd){
    digitalWrite(verm, LOW);
      digitalWrite(azul, HIGH);
      digitalWrite(verd, LOW);
}
void ligarVerd(int verm,int azul,int verd){
    digitalWrite(verm, LOW);
      digitalWrite(azul, LOW);
      digitalWrite(verd, HIGH);
}
void desligar(int verm,int azul,int verd){
    digitalWrite(verm, LOW);
      digitalWrite(azul, LOW);
      digitalWrite(verd, LOW);
      valor_botao = 0;
}
//Fase de acao
void loop()
{
  if(digitalRead(botao) == LOW){
      valor_botao++;
    delay(250);
  }
  switch(valor_botao){
      case 1: ligarVerm(led_verm, led_azul, led_verd); break;
    case 2: ligarVerd(led_verm, led_azul, led_verd); break;
    case 3: ligarAzul(led_verm, led_azul, led_verd); break;
    case 4:    desligar(led_verm, led_azul, led_verd); break;
  }
}
