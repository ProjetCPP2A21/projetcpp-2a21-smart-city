#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  // Attendre que la connexion série soit établie
  delay(2000);
  Serial.println("DHT11 initialisé");
}

void loop() {
  // Lire la température
  float temp = dht.readTemperature();

  // Vérifier si la lecture a échoué
  if (isnan(temp)) {
    Serial.println("ERROR");
    Serial.flush(); // Assurer que les données sont envoyées
  } else {
    // Envoyer uniquement la température avec 1 décimale
    Serial.print(temp, 1);
    Serial.println(); // Nouvelle ligne pour marquer la fin
    Serial.flush(); // Assurer que les données sont envoyées
    
    // DEBUG: Afficher aussi sur le moniteur série (optionnel)
    // Serial.print("Température envoyée: ");
    // Serial.println(temp, 1);
  }

  // Attendre 2 secondes entre chaque lecture
  delay(2000);
}