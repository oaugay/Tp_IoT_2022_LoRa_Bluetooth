#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Alexis";
const char* password = "alexisdore";
const char* mqtt_server ="test.mosquitto.org";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("test");
  }
  Serial.println("Connexion WiFi établie");
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
    Serial.println("Tentative de connexion MQTT...");
    if (client.connect("oscar")) {
      Serial.println("Connecté au serveur MQTT");
      client.publish("srt/al", "868,3;10;40");
      
    } else {
      Serial.print("Erreur de connexion MQTT, code d'erreur=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message reçu sur le topic: ");
  Serial.println(topic);
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.print("Contenu du message: ");
  Serial.println(message);
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Tentative de reconnexion MQTT...");
    if (client.connect("oscar")) {
      Serial.println("Connecté au serveur MQTT");
    } else {
      Serial.print("Erreur de reconnexion MQTT, code d'erreur=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
