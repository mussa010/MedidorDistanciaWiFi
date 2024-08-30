#include <Arduino.h>
#include<WiFi.h>
#include<math.h>
#define N 4.0

void setup() {
  Serial.begin(115200);
  WiFi.setHostname("Medidor de distancia");
  WiFi.begin("mussa", "A1302701");

  while(WiFi.status() != WL_CONNECTED) {
    Serial.println("Nao conectou ainda!");
  }
  delay(1000);
  Serial.print("Conectado na rede: ");
  Serial.println(WiFi.SSID());
  
}

void loop() {
  int potSaidaRoteador = 30;
  Serial.print("Sinal de saida do roteador: ");
  Serial.print(potSaidaRoteador);
  Serial.println(" dBm");
  Serial.print("Sinal da rede: ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");

  float dist = pow(10, ((potSaidaRoteador-WiFi.RSSI())/(10*N)));

  Serial.print("A distancia do esp para o roteador eh: ");
  Serial.print(dist/100);
  Serial.println(" m");
  delay(3000);
}