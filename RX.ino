const int botaoSync = 13;
const int signalRx = 11;

void setup() {
  Serial.begin(9600);
  pinMode(signalRx, INPUT);
  pinMode(botaoSync, INPUT);
}

void loop() {
  int syncOn = 0;
  if (digitalRead(botaoSync))
    syncOn = 1;
  if (syncOn)
    Serial.println(digitalRead(signalRX));
}
