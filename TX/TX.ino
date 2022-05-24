const int signalTx = 13;

// COMENTA O CÓDIGO QUE NÃO VAI USAR, TAIS CODIGANDO COM SONO O DESGRAÇA

// Protocolo OLAMUND_
const int charO[4] = {0, 0, 0};
const int charL[4] = {1, 0, 0};
const int charA[4] = {0, 1, 0};
const int charM[4] = {1, 1, 0};
const int charU[4] = {0, 0, 1};
const int charN[4] = {1, 0, 1};
const int charD[4] = {0, 1, 1};
const int charEspaco[4] = {1, 1, 1};

// OLD Protocolo OLA!
//const int charO = 1;
//const int charL = 2;
//const int charA = 3;

void ledDelay(int TXPort, int letra[]);

void setup() {
  pinMode(signalTx, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(1000);

  // Sincronizar via botão estava dando erro por mal contato
//  while(!digitalRead(botaoSync)) {
//    Serial.println("Esperando Primeiro Sinal");
//  }

  // Será feito sincronização via Serial mesmo
  Serial.println("Aperte um botão para iniciar a sincronização");
  while(Serial.available() == 0);

  Serial.println("Sincronizando");
  digitalWrite(signalTx, HIGH);
  delay(5000);
  digitalWrite(signalTx, LOW);
  
  // Escrita das letras
  while(true) {
    Serial.println("Enviando O");
    ledDelay(signalTx, charO);
    Serial.println("Enviando L");
    ledDelay(signalTx, charL);
    Serial.println("Enviando A");
    ledDelay(signalTx, charA);
    Serial.println("Enviando _");
    ledDelay(signalTx, charEspaco);
    Serial.println("Enviando M");
    ledDelay(signalTx, charM);
    Serial.println("Enviando U");
    ledDelay(signalTx, charU);
    Serial.println("Enviando N");
    ledDelay(signalTx, charN);
    Serial.println("Enviando D");
    ledDelay(signalTx, charD);
    Serial.println("Enviando O");
    ledDelay(signalTx, charO);
    Serial.println("Enviando _");
    ledDelay(signalTx, charEspaco);
  }
}

// Criar função para as letras e o seu tempo para deixar ligado o led
void ledDelay(int TXPort, int letra[]) {
  // New Protocol
  // Lê um array e manda sinal se tiver um 1
  for (int i = 0; i < 3; i++) {
    if(letra[i] == 1) {
      Serial.println("1"); //DEBUG
      digitalWrite(TXPort, HIGH);
      delay(1000);
      digitalWrite(TXPort, LOW);
    } else {
      Serial.println("0"); //DEBUG
      delay(1000);
    }
  }

  // Old Protocol
  // Envia as letras O = 1, L= 2, A = 3
//  for (int i = 0; i < letra; i++) {
//    Serial.println("Rodando escrita");
//    digitalWrite(TXPort, HIGH);
//    delay(1000);
//    digitalWrite(TXPort, LOW);
//  }
//  for (int i = letra; i < 3; i++) {
//    Serial.println("Rodando delays");
//    delay(1000);
//  }
//  delay(1000);
}
