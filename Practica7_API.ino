#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>
#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <ArduinoJson.h>

const char* ssid = "UAM-ROBOTICA";
const char* password = "m4nt32024uat";

#define DHTPIN 4      // Cambiado a D4 para el sensor DHT
#define DHTTYPE DHT22 // Cambiar a DHT11 si se usa este sensor
DHT dht(DHTPIN, DHTTYPE);

Adafruit_BMP280 bmp;

const int ledPin = 2;  // Cambiado a D4 para el LED

WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "API ESP32 con DHT y BMP280");
}

void handleSensorData() {
  float t_dht = dht.readTemperature();
  float h = dht.readHumidity();
  float t_bmp = bmp.readTemperature();
  float p = bmp.readPressure();

  StaticJsonDocument<1024> doc;  // Define un tamaño adecuado para el JSON
  doc["temperatura_dht"] = t_dht;
  doc["humedad"] = h;
  doc["temperatura_bmp"] = t_bmp;
  doc["presion"] = p;

  String response;
  serializeJson(doc, response);

  server.send(200, "application/json", response);
}

void handleLedOn() {
  digitalWrite(ledPin, HIGH);
  server.send(200, "text/plain", "LED ON");
}

void handleLedOff() {
  digitalWrite(ledPin, LOW);
  server.send(200, "text/plain", "LED OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  dht.begin();
  Wire.begin(21, 22);  // Inicializa I2C con pines específicos para ESP32

  if (!bmp.begin(0x76)) {
    Serial.println("No se encontró el sensor BMP280");
    while (1);  // Detener el programa si no se encuentra el sensor
  }

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }

  Serial.println("Conectado a WiFi");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/sensor", handleSensorData);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);
  server.begin();  // Iniciar el servidor web
}

void loop() {
  server.handleClient();  // Manejar las solicitudes de los clientes
}
