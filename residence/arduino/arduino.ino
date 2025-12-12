/*const int buttonPin = 2;  // digital pin for button
const int fanPin = 13;    // built-in LED (optional, for testing)

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // button connected to GND when pressed
  pinMode(fanPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);
  if (reading == LOW) {       // button pressed
    // fan is powered directly by 5V, no need to control it in code
    digitalWrite(fanPin, HIGH); // optional: turn on LED to show pressed
  } else {
    digitalWrite(fanPin, LOW);  // optional: turn off LED
  }
}*/
int relayPin = 13;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // relay OFF at start
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char cmd = Serial.read();

    if (cmd == '1') {
      digitalWrite(relayPin, HIGH);  // turn fan ON
      Serial.println("Fan ON");
    }
    else if (cmd =='0'){
      digitalWrite(relayPin, LOW);   // turn fan OFF
      Serial.println("Fan OFF");
    }
  }
}

 
