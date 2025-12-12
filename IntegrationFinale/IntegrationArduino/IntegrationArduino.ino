#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// --- CONFIGURATION RFID (Câblage existant) ---
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);

// --- CONFIGURATION ACTIONNEURS ---
Servo myServo;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Changez 0x27 par 0x3F si l'écran reste éteint

void setup() {
  Serial.begin(9600); // Communication avec Qt
  
  // Init RFID
  SPI.begin();
  mfrc522.PCD_Init();

  // Init Servo
  myServo.attach(3);  // Fil signal du Servo sur Pin 3
  myServo.write(0);   // Position fermée au démarrage
  
  // Init LCD
  lcd.init();
  lcd.backlight();
  resetDisplay();
}

void loop() {
  // -----------------------------------------------------------
  // 1. ÉCOUTE DU PC (Qt a-t-il envoyé '1' ou '0' ?)
  // -----------------------------------------------------------
  if (Serial.available() > 0) {
    char data = Serial.read();

    if (data == '1') {
      // --- ACCÈS AUTORISÉ ---
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("   BIENVENUE !  ");
      lcd.setCursor(0, 1);
      lcd.print(" Porte Ouverte  ");
      
      myServo.write(90); // Rotation 90° (Ouvrir)
      delay(3000);       // Garder ouvert 3 secondes
      myServo.write(0);  // Rotation 0° (Fermer)
      
      resetDisplay();
    }
    else if (data == '0') {
      // --- ACCÈS REFUSÉ ---
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  ACCES REFUSE  ");
      lcd.setCursor(0, 1);
      lcd.print(" Carte Inconnue ");
      
      // Petit bip sonore si vous avez un buzzer (optionnel)
      // tone(buzzerPin, 1000, 500);
      
      delay(2000);
      resetDisplay();
    }
  }

  // -----------------------------------------------------------
  // 2. LECTURE RFID (Envoi de l'UID vers Qt)
  // -----------------------------------------------------------
  // Si une carte est présente ET qu'on arrive à lire son série
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    
    // Construction de l'UID
    String content = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
       content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
       content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    
    // Envoi à Qt
    Serial.print(content);
    Serial.println(); // Fin de ligne indispensable pour Qt
    
    // On met le lecteur en pause pour ne pas spammer Qt avec la même carte
    mfrc522.PICC_HaltA();
    delay(500); 
  }
}

// Fonction pour remettre l'écran à l'état initial
void resetDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Systeme Pret...");
  lcd.setCursor(0, 1);
  lcd.print("Scannez badge");
}
