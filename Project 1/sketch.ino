#include <DHT.h>

int dhtPin = 4;       
#define DHTTYPE DHT22 
DHT dht(dhtPin, DHTTYPE);
void setup() {
  Serial.begin(115200); 
  dht.begin();          
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C ");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  delay(2000); 
}   
