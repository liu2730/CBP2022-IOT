void setup() {
  Serial.begin(9600); //Baud rate: 9600
}

void loop() {
  int turbidityValue = analogRead(36);// read the input on analog pin 36 (Turbidity):
  int tdsValue = analogRead(0);// read the input on analog pin 0 (TDS):
  float turbidityVoltage = turbidityValue * (5.0 / 4096.0); // Convert the analog reading (which goes from 0 - 4096) to a voltage (0 - 5V):
  //float tdsVoltage = tdsValue * (5.0 / 4096.0); // Convert the TDS reading (which goes from 0 - 4096) to a voltage (0 - 5V):
  Serial.println("Turbidity Rating:");
  Serial.println(turbidityVoltage); // print out the turbidity rating:
  Serial.println("TDS Reading:");
  Serial.println(tdsValue); // print out the turbidity rating:
  delay(5000);

}