#include <Arduino.h>
#include<WiFi.h>
#include<math.h>
#define pi 3.141592653589793238462643383279502884197169399375105820974944

// put function declarations here:

void setup() {
  Serial.begin(115200);
  WiFi.setHostname("Medidor de distância");
  WiFi.begin("mussa", "A1302701");

  while(WiFi.status() != WL_CONNECTED) {
    Serial.println("Não conectou ainda!");
  }
  delay(1000);
  Serial.print("Conectado na rede: ");
  Serial.println(WiFi.SSID());
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Sinal da rede: ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
  delay(3000);
}