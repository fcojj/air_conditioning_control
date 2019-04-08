/*
  SD card read/write

 This example shows how to read and write data to and from an SD card file
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

 created   Nov 2010
 by David A. Mellis
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

#include <SPI.h>
#include <SD.h>

File myFile;

void sdDelete(){  //essa função vai deletar o nosso arquivo, nós podemos criar ele novamente apenas abrindo-o para leritura
  Serial.print("Deletando..."); //na serial que estamos tentando deletar
  SD.remove("test.txt");  //enviamos o comando para deletar
  if(SD.exists("test.txt")){  //verificamos se o arquivo ainda existe
    Serial.println("Falha.");  //se existe, dizemos que não foi possível deletar
  }else{ //se não existe...
    Serial.println("Terminado."); //dizemos que foi deletado
  }
}

String ler_linha(int num_linha) {
  for (int i = 0; i < num_linha; i++) {
    while (myFile.read() != '\n') {
      ;
    }
  }
  String linha = "";
  int c = 0;
  while (myFile.peek() != '\n') {
    linha[c] = myFile.read();
    c++;
  }
  return linha;
}

void createArrayCommand(String comando){
 myFile = SD.open("test.txt");
 if (myFile) {
   Serial.println("test.txt:");
   // read from the file until there's nothing else in it:
    while (myFile.available()) {
      //Serial.write(myFile.read());
      int inChar = myFile.read();
  
      if (isDigit(inChar)) {
        inString += (char)inChar;                         
      }
    }
      int a = 0;
      int b = 4;
    for (int i = 0; i < 57; i++){
      String sezione = inString.substring(a,b);
      myArray[i]= sezione.toInt(); 
      a=a+4;
      b=b+4;
    }

}


void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
     // myFile.print("jonas");
 
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}



void loop() {
  // nothing happens after setup
}


