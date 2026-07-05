const int soilPin = 34;      
const int LedPin = 26;     

int moistureValue;
int threshold = 2000;       

void setup() {
  Serial.begin(115200);

  pinMode(LedPin, OUTPUT);
  digitalWrite(LedPin, LOW);  
}

void loop() {
  moistureValue = analogRead(soilPin);
  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue > threshold) {
    Serial.println("Soil is Dry");
    Serial.println("Pump ON");
    digitalWrite(LedPin, HIGH);   
  }
  else {
    Serial.println("Soil is Wet");
    Serial.println("Pump OFF");
    digitalWrite(LedPin, LOW);    
  }

  Serial.println("------------------------");

  delay(2000);
}
