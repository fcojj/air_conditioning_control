int POT = A0;
int LED = 11;
int valor=0;
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(POT,INPUT);
  
}

void loop() {
 valor = analogRead(POT);
 analogWrite(LED, valor/4);
}

