int GREEN = 11;
int YELLOW = 12;
int RED = 13;
int count =  0;
int BUTTON = 10;

void setup() {
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BUTTON,INPUT);
  digitalWrite(RED, LOW);
}

void loop() {
  if (digitalRead(BUTTON) ==  HIGH) {
    showLed(count++);
    delay(200);
    if(count == 3){
        count = 0;
    }  
  }
}

void showLed(int count){
  if (count == 0){
     showRed();
  } else if (count == 1){
     showYellow();
  } else {
    showGreen();
  } 
}

void showRed(){
  digitalWrite(RED,HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
}

void showYellow(){
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
}

void showGreen(){
  digitalWrite(RED,LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
}


