#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

// Configura tu sensor
#define DHTPIN 4          // GPIO4 (ajusta si usas otro pin)
#define DHTTYPE DHT11     // DHT11 o DHT22
DHT dht(DHTPIN, DHTTYPE);

// WiFi
const char* ssid = "Luisf25";          // Reemplaza con tu red
const char* password = "L1065857939f";  // Reemplaza con tu clave WiFi

// Servidor Flask (IP de tu PC + puerto)
const char* serverName = "http://192.168.1.4:8050/sensor";  // Ajusta la IP según tu red

void setup() {
  Serial.begin(115200);
  dht.begin();

  // Conectar a WiFi
  WiFi.begin(ssid, password);
  Serial.println("Conectando a WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Conectado a WiFi");
}

void loop() {
  // Leer temperatura y humedad
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Verificar si la lectura es válida
  if (isnan(h) || isnan(t)) {
    Serial.println("Error al leer del sensor DHT11");
    delay(5000);
    return;
  }

  // Mostrar los datos en la consola
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" °C | Humedad: ");
  Serial.print(h);
  Serial.println(" %");

  // Si WiFi conectado, enviar datos
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    // Crear JSON
    String datos = "{\"temperatura\":" + String(t, 2) + ",\"humedad\":" + String(h, 2) + "}";
    Serial.print("Enviando JSON: ");
    Serial.println(datos);

    // Enviar POST
    int codigoRespuesta = http.POST(datos);
    Serial.print("Respuesta HTTP: ");
    Serial.println(codigoRespuesta);

    http.end();
  } else {
    Serial.println("WiFi no conectado");
  }

  delay(10000); // Esperar 10 segundos antes del próximo envío
}
