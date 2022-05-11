const int botaoSync = 11;
const int signalTx = 13;

void setup() {
  pinMode(signalTx, OUTPUT);
  pinMode(botaoSync, INPUT);
}

void loop() {
  int syncOn = 0;
  if (digitalRead(botaoSync))
    syncOn = 1;
  if (syncOn) {
    digitalWrite(signalTx, HIGH);
    delay(500);
    digitalWrite(signalTx, LOW);
    delay(1000);
  } 
}
