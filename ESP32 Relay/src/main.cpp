#include <Arduino.h>
#include <WiFi.h>

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin("NETGEAR23-5Ga","rustictree335");
  Serial.begin(115200);
  Serial.println("Hello World!");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(WiFi.status());
    delay(100);
  }
  WiFi.status();
  Serial.println(WiFi.status());
  WiFi.localIP();
  Serial.println(WiFi.localIP());
}

void loop() {
  
}