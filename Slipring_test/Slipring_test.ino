float Vin = 3.286;
float R1 = 5.3;
float R2 = R1;
float R3 = R1;
float R4, Vn ;
float Ra = 3.3621084298;
float Rb = 166;
float Vin2 = 0.06;

int value = 0;

void setup() {
  Serial.begin(9600);  
}


void loop() {
float Vb_Vin2 = analogRead(A11)/1023.0; //ratio Vb/Vin2

float Va_Vin2 = analogRead(A10)/1023.0; //the ratio Va/Vin2

R4 = (Vb_Vin*R3) / (1-Vb_Vin);

Serial.print(Vb_Vin2*Vin2); //Vb
Serial.print(", ");
Serial.print(Va_Vin2*Vin2); //Va
Serial.print(", ");
Serial.println(R4);

delay(1000);

}