#include<SD.h>
#include <SPI.h>

float Vin = 3.286;
float R1 = 98;
float R3 = 98;
float R5 = 98;

File dataFile;
const int chipSelect = BUILTIN_SDCARD;


void setup() {
  Serial.begin(9600);  
  pinMode(13, OUTPUT);

  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    while (1) {
      // No SD card, so don't do anything more - stay stuck here
    }
  }
  Serial.println("card initialized.");


  dataFile = SD.open("ResistanceData.csv", FILE_WRITE);
  if(dataFile){
    dataFile.println("Time, Res 2, Res 4, Res 6");
    dataFile.close();
  }
}


void loop() {
  float V2 = 0; //ratio (Vb/Vin)*Vin
  float V4 = 0;
  float V6 = 0;

  for (int i=0; i<=5000; i++){
    V2 = V2 + (Vin * analogRead(A10)/1023.0); //ratio (Vb/Vin)*Vin
    V4 = V4 + (Vin * analogRead(A11)/1023.0);
    V6 = V6 + (Vin * analogRead(A12)/1023.0);
  }

  V2 = V2 / 5000;
  V4 = V4 / 5000;
  V6 = V6 / 5000;

  float R2 = (V2*R1/Vin) / (1-(V2/Vin));
  float R4 = (V4*R3/Vin) / (1-(V4/Vin));
  float R6 = (V6*R5/Vin) / (1-(V6/Vin));
  

  Serial.print(R2);
  Serial.print(", ");
  Serial.print(R4);
  Serial.print(", ");
  Serial.print(R6);
  Serial.print(", ");
  Serial.println(80);
  

  dataFile = SD.open("ResistanceData.csv", FILE_WRITE);
  if(dataFile){
    dataFile.print(millis()/1000);
    dataFile.print(",");
    dataFile.print(R2);
    dataFile.print(",");
    dataFile.print(R4);
    dataFile.print(",");
    dataFile.println(R6);
    dataFile.close();
  } else {
    Serial.println("File error");
  }

  delay(2000);

}


