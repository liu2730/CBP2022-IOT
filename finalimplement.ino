#include <WiFi.h>
#include <WebServer.h>
#include <WiFiClient.h>

#include "webUpdate.h"

WebServer server(80);

const char* ssid = "Pixel_8972"; //Change according to wifi network you are connecting to (this is my hotspot)
const char* wifi_pass = "tequila12"; //This is the password to my hotspot if you are ever close enough to connect

void initWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, wifi_pass);
  Serial.print("Connecting to WIFI...");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print('.');
    delay(1000);
  }
  Serial.println("Connected!");
  Serial.println(WiFi.localIP()); //Use this IP Address for the Website
}

void handleADC() {
  int turbidityValue = analogRead(35);
  int tdsValue = analogRead(36);
  String adcRead = String(turbidityValue) + " ," + String(tdsValue);
  server.send(200, "text/plain", adcRead);
}

void handleRoot() {
  String s = MAIN_page;
  server.send(200, "text/html", s);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initWifi();

  server.on("/", handleRoot);
  server.on("/readADC", handleADC);

  server.begin();
  Serial.println("Website started.");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  delay(1);

}