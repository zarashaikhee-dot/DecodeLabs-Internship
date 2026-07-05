const int PIR_PIN = 27;
const int GAS_PIN = 34;
const int GREEN_LED = 2;
const int RED_LED = 4;
const int BUZZER = 5;

volatile bool motionDetected = false;

void ISR() {
  motionDetected = true;
}

void setup() {

  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), ISR, RISING);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BUZZER, LOW);
  Serial.println("Project 4 Started");
}

void loop() {

  int gasValue = analogRead(GAS_PIN);
  if (gasValue > 3800) {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);
    Serial.print("Gas Detected! Value = ");
    Serial.println(gasValue);

  }

  else {

    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
    if (motionDetected) {
      digitalWrite(GREEN_LED, HIGH);
      Serial.println("Motion Detected!");
      delay(3000);
      digitalWrite(GREEN_LED, LOW);
      motionDetected = false;

    }

  }

  delay(100);

}
