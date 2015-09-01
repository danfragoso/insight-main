//Projeto Insight
//Danilo Fragoso 2015

int onda = 6;// define pino 6 como onda (pwm)
boolean st = true;// define variavel booleana para estado da lampada

void setup() {

  Serial.begin(9600);// inicia comunicacao serial a velocidade de 9600
  pinMode(onda, OUTPUT);// define pino 6 como output
  analogWrite(onda, 255);// liga lampada em brilho maximo ao ser ligada na rede

}

void loop() {

  int brilho;// define variavel de brilho
  brilho = Serial.read();// atribui a variavel brilho informacoes recebidas via bluetooth

// encadeamento de if - else para atribuir valores de brilho para o pino 6

   if (brilho == 5)  {
    analogWrite(onda, 25);
  }
  else if (brilho == 10)  {
      analogWrite(onda, 50);
  }
  else if (brilho == 20) {
      analogWrite(onda, 75);
  }
  else if (brilho == 30) {
      analogWrite(onda, 100);
  }
  else if (brilho == 40) {
      analogWrite(onda, 125);
  }
  else if (brilho == 50) {
    analogWrite(onda, 150);
  }
  else if (brilho == 60) {
    analogWrite(onda, 175);
  }
  else if (brilho == 70){
    analogWrite(onda, 200);
  }
  else if (brilho == 80){
    analogWrite(onda, 225);
  }
  else if (brilho == 90){
    analogWrite(onda, 240);
  }
  else if (brilho == 100){
    analogWrite(onda, 255);
  }

  // condicao responsavel por controlar estado booleano da lampada

  else if (brilho == 101){
    if (st == true){
    analogWrite(onda, 0);
    st = false;
  }
    else if (st == false){
    analogWrite(onda, 255);
    st = true;
  }
 }
}
