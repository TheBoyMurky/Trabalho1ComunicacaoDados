const int signalRx = 8;
const int ledDebug = 13;

// Valor dos caracteres
char charArray[9] = {'O', 'L', 'A', 'M', 'U', 'N', 'D', '_'};

int flag1 = 0; // Valor 1
int flag2 = 0; // Valor 2
int flag3 = 0; // Valor 4

unsigned long primeiroSinal = 0;
unsigned long segundoSinal = 0;

void read3SecondDelay(int RXPort, unsigned long signalDelay);
unsigned long sync(int RXPort);

void setup() {
  Serial.begin(9600);
  pinMode(signalRx, INPUT);
  pinMode(ledDebug, OUTPUT);
}

void loop() {
//  delay(3000);
  
  while(!digitalRead(signalRx)) {
    Serial.println("Esperando Primeiro Sinal (RX)");
  }

  unsigned long sinalDelay = sync(signalRx);

  for(int i = 0; i < 9; i++) {
    read3SecondDelay(signalRx, sinalDelay);
    flag1 = 0;
    flag2 = 0;
    flag3 = 0;
  }
  
//  while(true) {
//    read3SecondDelay(signalRx, sinalDelay);
//    flag1 = 0;
//    flag2 = 0;
//    flag3 = 0;
//  }
  
  Serial.println("\nFinalizado Transmissão");
  while(true);
//  delay(3000);
}

unsigned long sync(int RXPort) {
  Serial.println("Sincronizando");
  while(digitalRead(RXPort));
  primeiroSinal = millis();
  while(!digitalRead(RXPort));
  segundoSinal = millis();
  Serial.print("Delay:");
  Serial.println(segundoSinal - primeiroSinal); // Depois subtrair também o 1 segundo de delay entre os HIGHs
  delay(100);
  return 1000 -(segundoSinal - primeiroSinal);
  // Delay para verificar se eu não fiz cagada
//  delay(2100);
}

void read3SecondDelay(int RXPort, unsigned long signalDelay) {
  delay(500 + signalDelay);
  // Leitura primeiro flag
  if (digitalRead(RXPort)) {
//    Serial.println("FLAG 1");  //DEBUG
    flag1 = 1;
    digitalWrite(ledDebug, HIGH);
  }
  delay(1000);
  digitalWrite(ledDebug, LOW);

  // Leitura segundo flag
  if (digitalRead(RXPort)) {
//    Serial.println("FLAG 2"); //DEBUG
    flag2 = 2;
    digitalWrite(ledDebug, HIGH);
  }
  delay(1000);
  digitalWrite(ledDebug, LOW);

  // Leitura terceiro flag
  if (digitalRead(RXPort)) {
//    Serial.println("FLAG 3"); //DEBUG
    flag3 = 4;
    digitalWrite(ledDebug, HIGH);
  }
  delay(500 - signalDelay);
  digitalWrite(ledDebug, LOW);
  
  Serial.print(charArray[flag1 + flag2 + flag3]);
}
