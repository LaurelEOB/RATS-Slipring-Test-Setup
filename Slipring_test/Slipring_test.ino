float Vin = 3.3;
float R1 = 100.0;
float R2 = 100.0;
float R3 = 100.0;
float R4, Vn ;

int value = 0;

void setup() {
  Serial.begin(9600);  
}


void loop() {
float Vb_Vin = analogRead(A11)/1023.0; //ratio Vb/Vin

float Va_Vin = analogRead(A10)/1023.0; //the ratio Va/Vin

R4 = (Vb_Vin*R3) / (1-Vb_Vin);

Serial.print(Vb_Vin*Vin); //Vb
Serial.print(", ");
Serial.print(Va_Vin*Vin); //Va
Serial.print(", ");
Serial.println(R4);

delay(1000);

}