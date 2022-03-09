#include "sms.h"
void wifiSetup() {
Serial.begin(115200);
WiFi.begin(WIFI_SSID,WIFI_PASS);

Serial.print("Connecting to WiFi");
while (WiFi.status() != WL_CONNECTED){
  Serial.print(".");
  delay(500);
}
//Wifi connected
Serial.println("Wifi Connected!");
Serial.println(WiFi.localIP());
  

delay(200);
WiFiClient client;
Serial.print("Connecting to host...");
if (client.connect(HOST, 80)){
  Serial.println("Host connected!");
  Serial.println("");
} else {
         Serial.println("Host connection failed");
}
}

void sendSMS(){
  WiFiClient w;
HttpClient http = HttpClient(w, HOST, 80);
http.post("/trigger/motion_detected/with/key/E9XwTRnSndghQxBALMPt0");
Serial.println("Making POST request");
delay(2000);
}
