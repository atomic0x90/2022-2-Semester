//9.2
//온습도 센서
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("EX 9.2 DHT11 Test ");
  Serial.println("");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char t = dht.readTemperature();
  unsigned char h = dht.readHumidity();

  Serial.print("Temperture is ");
  Serial.print(t);
  Serial.println(" C");

  Serial.print("Humisity is ");
  Serial.print(h);
  Serial.println(" %");
  Serial.println(" ");

  delay(2000);
}
