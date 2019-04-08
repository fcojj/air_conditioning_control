byte digits[10][7] = {
// a f e d c g b
  {0,0,0,0,0,1,0},
  {1,1,1,1,0,1,0},
  {0,1,0,0,1,0,0},
  {0,1,1,0,0,0,0},
  {1,0,1,1,0,0,0},
  {0,0,1,0,0,0,1},
  {0,0,0,0,0,0,1},
  {0,1,1,1,0,1,0},
  {0,0,0,0,0,0,0},
  {0,0,1,1,0,0,0}
};
int valueTest = 34;
int DISPLAY_DOZEN = 0;
int DISPLAY_UNIT = 7;
const int SENSOR = A4;
const float  BASE_CELSIUS =  0.4887585532746823069403714565;

void setup() {
  Serial.begin(9600);
  for(int i=2; i<=15; i++){
     pinMode(i,OUTPUT);
  }
}

void loop() {
 writeDisplay(readyTemperature());
 delay(2000);
}

void writeDisplay(int showNumber){
  int dozen = showNumber/10;
  int unit = showNumber % 10;
  writeDisplay(DISPLAY_DOZEN,dozen);
  writeDisplay(DISPLAY_UNIT, unit); 
}

void writeDisplay(int display, int number){
   int begin = 2+display;
   int count = 0;
   for(int i = begin; i < begin+7; i++){
      digitalWrite(i,digits[number][count]);
      count++;
     }
}

float readyTemperature(){
 // float media = 0;
  
//  for(int i=0;i<10;i++){
//    media += (0.00488 / 0.01953 * analogRead(SENSOR) - 0.4 / 0.01953);
 // }
 // media /=10;
  
//  return media;
        int ADVal, Tc_100, whole, fract;

        ADVal = analogRead(4);
        Tc_100 = 25 * ADVal - 2050;
        
        whole = Tc_100 / 100;
        fract = Tc_100 % 100;

        Serial.print(whole);
        Serial.print(".");
        if (fract < 10)
        {
            Serial.print("0");
        }
        Serial.print(fract);
        Serial.write(176);
        Serial.println("C");
        return whole;
}
