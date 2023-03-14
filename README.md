# Tp_IoT_2022_LoRa_Bluetooth

On commence le code par l'inclusion de bibliothèques telles que "SPI.h", "WiFi.h" et "PubSubClient.h". Ensuite, nous avons défini quelques constantes et variables utilisées plus tard dans le code. Nous initialisons également la structure "pack" pour stocker des données sous forme de tableaux de 8 bits et de valeurs flottantes.

La fonction "setup" initialise la communication série, configure les broches d'entrée et de sortie, initialise la communication LoRa, se connecte au réseau WiFi et se connecte au serveur MQTT. La fonction "reconnect" est appelée si la connexion au serveur MQTT est perdue.

La fonction "loop" commence par vérifier si la connexion MQTT est active, sinon elle appelle la fonction "reconnect". Ensuite, il publie des données sur le serveur MQTT toutes les 5 secondes. Il envoie également des paquets LoRa contenant les valeurs de d1 et d2, qui sont incrémentées à chaque itération de la boucle "loop". La fonction "delay" est utilisée pour ralentir la boucle et limiter la fréquence d'envoi de paquets.

En résumé, le code permet de communiquer via le réseau LoRa et le réseau WiFi, et de publier des données sur un serveur MQTT. Il est conçu pour envoyer des paquets de données périodiquement.

Notre binôme était du côté emetteur et nous travaillions avec le groupe de Théo, qui était notre receveur.  


Alix LATASTE
Oscar AUGAY
