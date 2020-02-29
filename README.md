# IOT_WeatherApp

**Introduction**

Pour ce projet d'internet des objets, nous réaliserons une **"*station météo miniature*"** à placer dans un logement, un appartement ou bien même en extérieur ! 

Il existe déjà de nombreux moyens de suivre la météo : la télévision, les journaux et Internet vous livrent toutes des informations sur le temps qu’il fera. Dans ce cas, pourquoi fabriquer une station météo ? Elle permet d’obtenir des informations plus précises en temps réel. Cette fonction est utile pour tout le monde, même si elle est plus orienté pour certaines professions exercant à l’extérieur: jardiniers, les agriculteurs, ouvriers du batiment; ou encore certaines personnes exercant des loisirs extérieurs.

**Choix des technologies**

1.Le matériel

Pour la réalisation de ce projet, notre choix se porte vers des technologies accèsible à tous au quotidien et peu honéreux. 

 - [Une carte Arduino ESP8266](https://www.amazon.fr/Yizhet-NodeMCU-ESP8266-ESP-12E-D%C3%A9veloppement/dp/B07XJWK5F4/ref=sr_1_1_sspa?keywords=arduino+esp8266&qid=1583017212&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUExRTlZMzFUVlVGNlo5JmVuY3J5cHRlZElkPUEwMzkyNzIwM0NXWFAxMTFFR0RFNiZlbmNyeXB0ZWRBZElkPUEwMjI2NjM0U0szMlhXN0xQTklVJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)
 

  - [Un capteur de température DHT 11](https://www.amazon.fr/AZDelivery-capteur-dhumidit%C3%A9-temp%C3%A9rature-Raspberry/dp/B07TXR5NQ6/ref=sr_1_1_sspa?__mk_fr_FR=%C3%85M%C3%85%C5%BD%C3%95%C3%91&keywords=DHT11&qid=1583017305&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEyUk1UVE1ZWkhFOEVaJmVuY3J5cHRlZElkPUEwMzA4MTk5Vkc2NEhKMldRN1pLJmVuY3J5cHRlZEFkSWQ9QTAwMzU4NjczRjdKV1dWSlpFSUtZJndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)

  - [Un abonement SigFox](https://www.sigfox.com/en)

2.Le choix du réseau

Pour ce projet, nous choissirons le réseau **SigFox**, et non **LoRa**. Bien qu'ils remplissent la même tâche, pour notre cas d'application, le réseaux SigFox propose des avantages : 

-Une portée urbaine et rurale supérieur (3/10Km et 30/50km)
-Appareil et station protégè par ID unique 
-blablabla

**Shéma de notre solution**

**Shéma éléctronique**


**Instalation et lancement du projet**

```sh
$ cd "Nom du dossier"
```

Test

```sh
$ npm install --production
$ NODE_ENV=production node app
```

