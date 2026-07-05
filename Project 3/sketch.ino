#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

String writeAPIKey = "916V95NF4GSY8AKX";

#define TRIG_PIN 5
#define ECHO_PIN 18
#define LED_PIN 2

long duration;
float distance;

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.thingspeak.com/update?api_key=";
    url += writeAPIKey;
    url += "&field1=";
    url += String(distance);

    http.begin(url);
    int httpCode = http.GET();
    
    Serial.print("ThingSpeak Response: ");
    Serial.println(httpCode);
    
    http.end();
  }

  delay(20000);
}
