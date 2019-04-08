int RED = 13;
int YELLOW = 12;
int GREEN = 11;

void setup() {
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
 showRed();
 showYellow();
 showGreen();
}

void showRed(){
  digitalWrite(RED,HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  delay(2000);
}

void showYellow(){
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  delay(1000);
}


void showGreen(){
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  delay(2000);
}
