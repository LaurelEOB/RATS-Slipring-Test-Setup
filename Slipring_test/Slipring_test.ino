float Vin = 3.286;
float R1 = 98;
float R3 = 98;
float R5 = 98;


void setup() {
  Serial.begin(9600);  
}


void loop() {
float V2 = Vin * analogRead(A10)/1023.0; //ratio (Vb/Vin)*Vin
float V4 = Vin * analogRead(A11)/1023.0;
float V6 = Vin * analogRead(A12)/1023.0;

float R2 = (V2*R1/Vin) / (1-(V2/Vin));
float R4 = (V4*R3/Vin) / (1-(V4/Vin));
float R6 = (V6*R5/Vin) / (1-(V6/Vin));

Serial.print(R2);
Serial.print(", ");
Serial.print(R4);
Serial.print(", ");
Serial.println(R6);

delay(5000);

}


