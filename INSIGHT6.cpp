//Projeto Insight

//Danilo Fragoso 2015


int LED = 6;  // define pino pwm boolean st = true;  
boolean st = true;// boolean pro estado da lampada

void setup() {

	Serial.begin(9600);  //inicia serial com baud rate de 9600
	pinMode(LED, OUTPUT);  // seta pino onda como output
    analogWrite(LED, 255);
}

void loop() {

	int brilho;  //variavel que recebe info da serial
	int command; // variavel de  comandos
	
	if (Serial.read() > 1 && Serial.read() < 255 ){ // Se 1 a 255 brilho

		 brilho = Serial.read();  //atribui serial pra brilho
	 }   

	else if (Serial.read() > 255 && Serial.read() < 268){ // Se 255 a a 268 comandos

		 command = Serial.read(); //atribui serial pra comandos
	 }

	 if (brilho > 1){

	 analogWrite(LED, brilho);  //atribui valor de brilho recebido via serial para pino
	 st = true;
	 }

 if (command == 257){  //toogle de estado

	if (st == true){  //se ligada desliga
		analogWrite(LED, 0);
		st = false;  //reseta estado
	}
	
	else if (st == false){  //se desligada liga
		analogWrite(LED, 255);
		st = true;  //reseta estado
	}
  }
}
