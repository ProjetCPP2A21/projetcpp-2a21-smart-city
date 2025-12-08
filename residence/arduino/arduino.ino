#define RELAYPIN 6  // Pin du relais

void setup() {
  Serial.begin(9600);
  pinMode(RELAYPIN, OUTPUT);
  digitalWrite(RELAYPIN, LOW); // ventilateur éteint au démarrage
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    
    if (command == '1') {
      digitalWrite(RELAYPIN, HIGH);  // Ventilateur ON
      Serial.println("Ventilateur ON");
    } 
    else if (command == '0') {
      digitalWrite(RELAYPIN, LOW);   // Ventilateur OFF
      Serial.println("Ventilateur OFF");
    }
  }
}
