// Definir los pines de los LEDs
int ledPin1 = 13; // Pin del LED 1
int ledPin2 = 12; // Pin del LED 2
int ledPin3 = 11; // Pin del LED 3
int ledPin4 = 7; // Pin del LED 4

void setup() {
  Serial.begin(9600); // Comunicación Serial

  // Configurar los pines como salidas
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read(); // Lee el dato recibido por serial

    // Controlar los LEDs según la letra recibida
    switch (data) {
      case 'L':
        blinkLed(ledPin1, 500); // Parpadea el LED 1
        Serial.println("LED 1 BLINKING");
        break;
      case 'H':
        blinkLed(ledPin2, 500); // Parpadea el LED 2
        Serial.println("LED 2 BLINKING");
        break;
      case 'A':
        blinkLed(ledPin3, 500); // Parpadea el LED 3
        Serial.println("LED 3 BLINKING");
        break;
      case 'Y':
        blinkLed(ledPin4, 500); // Parpadea el LED 4
        Serial.println("LED 4 BLINKING");
        break;
      case 'l':
        digitalWrite(ledPin1, LOW); // Apaga el LED 1
        Serial.println("LED 1 OFF");
        break;
      case 'h':
        digitalWrite(ledPin2, LOW); // Apaga el LED 2
        Serial.println("LED 2 OFF");
        break;
      case 'a':
        digitalWrite(ledPin3, LOW); // Apaga el LED 3
        Serial.println("LED 3 OFF");
        break;
      case 'y':
        digitalWrite(ledPin4, LOW); // Apaga el LED 4
        Serial.println("LED 4 OFF");
        break;
      default:
        // Si se recibe una letra no reconocida, no hacer nada
        break;
    }
  }
}

// Función para hacer parpadear un LED
void blinkLed(int pin, int delayTime) {
  for (int i = 0; i < 5; i++) { // Parpadea 5 veces
    digitalWrite(pin, HIGH); // Enciende el LED
    delay(delayTime); // Espera
    digitalWrite(pin, LOW); // Apaga el LED
    delay(delayTime); // Espera
  }
}