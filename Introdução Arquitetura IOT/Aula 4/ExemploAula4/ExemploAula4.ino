
const byte POTENCIOMETRO = A5;


const byte LED = 11;

const byte segmentoA = 2;
const byte segmentoB = 3;
const byte segmentoC = 4;
const byte segmentoD = 5;
const byte segmentoE = 6;
const byte segmentoF = 7;
const byte segmentoG = 8;


const byte numeros[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  pinMode(LED, OUTPUT);

  pinMode(segmentoA, OUTPUT);
  pinMode(segmentoB, OUTPUT);
  pinMode(segmentoC, OUTPUT);
  pinMode(segmentoD, OUTPUT);
  pinMode(segmentoE, OUTPUT);
  pinMode(segmentoF, OUTPUT);
  pinMode(segmentoG, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int valorAnalogico = analogRead(POTENCIOMETRO);

  int valorPWM = map(valorAnalogico, 0, 1023, 0, 255);

  analogWrite(LED, valorPWM);

  float tensao = valorAnalogico * (5.0 / 1023.0);

  int tensaoInteira = round(tensao);

  mostrarNumero(tensaoInteira);

  Serial.print("Leitura analogica: ");
  Serial.print(valorAnalogico);

  Serial.print(" | PWM: ");
  Serial.print(valorPWM);

  Serial.print(" | Tensao: ");
  Serial.print(tensao, 2);
  Serial.println(" V");

  delay(200);
}

void mostrarNumero(byte numero) {
  if (numero > 9) {
    return;
  }

  digitalWrite(segmentoA, numeros[numero][0]);
  digitalWrite(segmentoB, numeros[numero][1]);
  digitalWrite(segmentoC, numeros[numero][2]);
  digitalWrite(segmentoD, numeros[numero][3]);
  digitalWrite(segmentoE, numeros[numero][4]);
  digitalWrite(segmentoF, numeros[numero][5]);
  digitalWrite(segmentoG, numeros[numero][6]);
}
