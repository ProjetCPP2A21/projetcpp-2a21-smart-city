#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define RELAY_PIN 7
#define BUZZER_PIN 8

DHT dht(DHTPIN, DHTTYPE);

unsigned long lastTempSend = 0;
bool isFanOn = false; // État actuel du ventilateur

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  // 1. GESTION DES COMMANDES REÇUES DE QT
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      // --- RFID OK ---
      // Code pour ouvrir la porte (Servo, etc.)
    } 
    else if (command == '0') {
      // --- RFID NOK ---
      digitalWrite(BUZZER_PIN, HIGH); delay(1000); digitalWrite(BUZZER_PIN, LOW);
    }
    else if (command == 'H') {
      // --- TEMPÉRATURE ÉLEVÉE (Ordre reçu de Qt) ---
      if (!isFanOn) { // Si on vient juste de passer en mode Alarme
        digitalWrite(RELAY_PIN, HIGH); // Allumer Ventilo
        
        // 3 Bips
        for(int i=0; i<3; i++){
          digitalWrite(BUZZER_PIN, HIGH); delay(100);
          digitalWrite(BUZZER_PIN, LOW); delay(100);
        }
        isFanOn = true;
      }
    }
    else if (command == 'N') {
      // --- TEMPÉRATURE NORMALE ---
      digitalWrite(RELAY_PIN, LOW); // Eteindre Ventilo
      isFanOn = false;
    }
  }

  // 2. ENVOI DE LA TEMPÉRATURE (Toutes les 2 secondes)
  if (millis() - lastTempSend > 2000) {
    float t = dht.readTemperature();
    if (!isnan(t)) {
      Serial.print("TEMP:");
      Serial.println(t);
    }
    lastTempSend = millis();
  }
}
