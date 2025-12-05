#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600); // Important : Doit correspondre au baudRate dans Qt
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  // Vérifier si une nouvelle carte est présente
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  // Vérifier si on peut lire le numéro de série
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Construction de l'UID en chaîne de caractères
  String content = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  
  content.toUpperCase();
  Serial.print(content); // Envoie l'UID (ex: "E3A1B2C4") à Qt
  Serial.println();      // Ajoute un retour à la ligne pour marquer la fin
  
  delay(1000); // Pause pour éviter de lire 50 fois la même carte en 1 seconde
}
