#include "DHTesp.h"
 
#define DHTpin 5    //D5 of NodeMCU is GPIO14
 
DHTesp dht;
 
void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");
  
  // Autodetect is not working reliable, don't use the following line
  // dht.setup(17);
 
  // use this instead: 
  dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO 17

}
 
void loop()
{
  delay(dht.getMinimumSamplingPeriod());
 
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
 
  //Serial.print(dht.getStatusString());
  //Serial.print("\t\t");
  Serial.print(humidity);
  Serial.print("\t\t");
  Serial.print(temperature);
  Serial.print("\t\t");
  //Serial.print(dht.toFahrenheit(temperature), 1);
  //Serial.print("\t\t");
  //Serial.print(dht.computeHeatIndex(temperature, humidity, false), 1);
  //Serial.print("\t\t");
  //Serial.println(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true), 1);
}
