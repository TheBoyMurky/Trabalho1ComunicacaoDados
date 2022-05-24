const int signalRx = 8;
const int ledDebug = 13;

// Valor dos caracteres
char charArray[9] = {'O', 'L', 'A', 'M', 'U', 'N', 'D', '_'};

int flag1 = 0; // Valor 1
int flag2 = 0; // Valor 2
int flag3 = 0; // Valor 4

void read3SecondDelay(int RXPort);

void setup() {
  Serial.begin(9600);
  pinMode(signalRx, INPUT);
  pinMode(ledDebug, OUTPUT);
}

void loop() {
  
  while(!digitalRead(signalRx)) {
    Serial.println("Esperando Primeiro Sinal");
  }
  
  Serial.println("Sincronizado");
  digitalWrite(ledDebug, HIGH);
  delay(5000);
  digitalWrite(ledDebug, LOW);
  
  while(true) {
    read3SecondDelay(signalRx);
    flag1 = 0;
    flag2 = 0;
    flag3 = 0;
  }
}

void read3SecondDelay(int RXPort) {
  // Leitura primeiro flag
  if (digitalRead(RXPort)) {
    Serial.println("FLAG 1");  //DEBUG
    flag1 = 1;
    digitalWrite(ledDebug, HIGH);
  }
  delay(1000);
  digitalWrite(ledDebug, LOW);

  // Leitura segundo flag
  if (digitalRead(RXPort)) {
    Serial.println("FLAG 2"); //DEBUG
    flag2 = 2;
    digitalWrite(ledDebug, HIGH);
  }
  delay(1000);
  digitalWrite(ledDebug, LOW);

  // Leitura terceiro flag
  if (digitalRead(RXPort)) {
    Serial.println("FLAG 3"); //DEBUG
    flag3 = 4;
    digitalWrite(ledDebug, HIGH);
  }
  delay(1000);
  digitalWrite(ledDebug, LOW);
  
  Serial.println(charArray[flag1 + flag2 + flag3]);
}
