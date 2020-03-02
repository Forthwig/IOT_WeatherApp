# IOT_WeatherApp

**Introduction**

Pour ce projet d'internet des objets, nous réaliserons une **"*station météo miniature*"** à placer dans un logement, un appartement ou bien même en extérieur ! 

Il existe déjà de nombreux moyens de suivre la météo : la télévision, les journaux et Internet vous livrent toutes des informations sur le temps qu’il fera. Dans ce cas, pourquoi fabriquer une station météo ? Elle permet d’obtenir des informations plus précises en temps réel. Cette fonction est utile pour tout le monde, même si elle est plus orienté pour certaines professions exercant à l’extérieur: jardiniers, les agriculteurs, ouvriers du batiment; ou encore certaines personnes exercant des loisirs extérieurs.

**Choix des technologies**

1. Le matériel

Pour la réalisation de ce projet, notre choix se porte vers des technologies accèsible à tous au quotidien et peu honéreux. 

 - [Une carte Arduino ESP8266](https://www.amazon.fr/Yizhet-NodeMCU-ESP8266-ESP-12E-D%C3%A9veloppement/dp/B07XJWK5F4/ref=sr_1_1_sspa?keywords=arduino+esp8266&qid=1583017212&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExRTlZMzFUVlVGNlo5JmVuY3J5cHRlZElkPUEwMzkyNzIwM0NXWFAxMTFFR0RFNiZlbmNyeXB0ZWRBZElkPUEwMjI2NjM0U0szMlhXN0xQTklVJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)
 

  - [Un capteur de température DHT 11](https://www.amazon.fr/AZDelivery-capteur-dhumidit%C3%A9-temp%C3%A9rature-Raspberry/dp/B07TXR5NQ6/ref=sr_1_1_sspa?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=DHT11&qid=1583017305&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyUk1UVE1ZWkhFOEVaJmVuY3J5cHRlZElkPUEwMzA4MTk5Vkc2NEhKMldRN1pLJmVuY3J5cHRlZEFkSWQ9QTAwMzU4NjczRjdKV1dWSlpFSUtZJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)

  - [Un abonement SigFox](https://www.sigfox.com/en)

2. Le choix du réseau

Pour ce projet, nous choissirons le réseau **SigFox**, et non **LoRa**. Bien qu'ils remplissent la même tâche, pour notre cas d'application, le réseaux SigFox propose des avantages : 

-Une portée urbaine et rurale supérieur (3/10Km et 30/50km)
-Appareil et station protégè par ID unique 
-meilleure portée "indoor"

MQTT Vs HTTP

**Shéma de notre solution**
1. Node MCU -- ESP8266
![Node MCU ESP8266](https://www.bastelgarage.ch/image/cache/catalog/Artikel/420181-420190/420184_5-800x800.jpg)	

2. SNOC Breakout Board - Sigfox BRKWS01
![SNOC Breakout Board - Sigfox BRKWS01](https://qiita-image-store.s3.amazonaws.com/0/172313/0e936214-f347-f9b4-e9e9-bb7327b83d43.png)	

Reliez: 
* RX avec le PIN D8 (TX)
* TX avec le PIN D7 (RX)
* VCC avec 3V
* GND avec GND

3. Dht11 
![DHT11](https://1.bp.blogspot.com/-7cT2bEcG3Ig/XbRys2rV5II/AAAAAAAAB3Y/O-AtFmQDUuEJpW8UJ4q12Q9G471uWH3_QCEwYBhgL/s1600/gambar4.png)	
* VCC avec 3V
* GND avec GND
Le choix du PIN est libre, pour ce projet nous utilisons le PIN D1, libre à vous d'en choisir un autre sans oublier de modifier la déclaration dans le fichier DHT_Sig.ino

```sh
#define DHTpin "PIN"
```


**Instalation et lancement du projet**

1. Installation/Requierements

- [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- [Ngrok]( https://ngrok.com/)
- [Python 3.7](https://www.python.org/downloads/release/python-370/)
- [Flask](https://fr.wikipedia.org/wiki/Flask_(framework))
- [MongoDB](https://www.mongodb.com/fr)

2. Lancement du projet

Avant toute chose, il nous faut créer la base de donnée (MongoDb) dans laquelle les valeurs seront stockés.
Ouvrez le fichier python MongoDB_Connection.py et placez vos identifiant obtenus dans la ligne suivante: 

```sh
def __init__(self,username="YOUR USERNAME",password="YOUR PASSWORD"):
```

Ensuite ouvrez votre IDE Arduino, installez la bilbiothèque ESP82XX et téléversez le programme dédié Par la suite lancez Ngrok, permettant de crée un localhost securisé (ici sur le port 5000)

```sh
ngrok.exe http 5000
```
**Il ne faut pas oublier de déclarer la nouvelle adresse dans les callbacks SigFox !**
Il ne reste plus qu'a executer l'app Flask en vérifiant que nous sommes également sur le port 5000

```sh
cd C:\"YOUR ACCESS PATH"\Site_Weather_App
python app.py
```
Ne reste plus qu'a se rendre sur votre navigateur préféré et profité de votre station météo DIY ! 

```sh
http://localhost:5000/home
```
