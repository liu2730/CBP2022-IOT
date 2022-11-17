void setup() {
  Serial.begin(9600); //Baud rate: 9600
}

void loop() {
  int turbidityValue = analogRead(35);// read the input on analog pin 35 (Turbidity):
  int tdsValue = analogRead(36);// read the input on analog pin 36 (TDS):
  float turbidityVoltage = turbidityValue * (5.0 / 4096.0); // Convert the analog reading (which goes from 0 - 4096) to a voltage (0 - 5V):
  Serial.println("Turbidity Rating:");
  Serial.println(turbidityVoltage); // print out the turbidity rating:
  Serial.println("TDS Reading (PPM):");
  Serial.println(tdsValue); // print out the turbidity rating:
  delay(5000);

}