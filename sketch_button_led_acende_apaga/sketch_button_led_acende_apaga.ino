int RED = 13;
int BUTTON = 10;

void setup() {
  pinMode(RED,OUTPUT);
  pinMode(BUTTON,INPUT);
  digitalWrite(RED, LOW);
}

void loop() {
  if (digitalRead(BUTTON) ==  HIGH) {
    digitalWrite(RED, HIGH);  
  } else{
    digitalWrite(RED, LOW);  
  }
}


