

#include "DHTesp.h"

#include <SoftwareSerial.h>

#define RxNodePin 13
#define TxNodePin 15
#define DHTpin 5 

DHTesp dht;

// Setup UART Communication with 
SoftwareSerial Sigfox =  SoftwareSerial(RxNodePin, TxNodePin);

// 12 bytes message buffer
uint8_t sigfoxMsg[12];

void setup () {
  Serial.begin(115200);
  delay(200);
  Serial.println("\n***** START *****");
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");
  dht.setup(DHTpin, DHTesp::DHT11);

  pinMode(RxNodePin, INPUT);
  pinMode(TxNodePin, OUTPUT);
  Sigfox.begin(9600);
  delay(100);
  Serial.print("Device ID: " + getID()); 
  Serial.print("Device PAC Number: " + getPAC());
  delay(100);
}

void loop () {
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
  
  Serial.println((int)temperature);
  Serial.println((int)humidity);
  
  
  sigfoxMsg[0]=(int)humidity;
  sigfoxMsg[1]=temperature;
  sigfoxMsg[2]=0x00;
  sigfoxMsg[3]=0x00;
  sigfoxMsg[4]=0x00;
  Serial.println("Send message: " + sendMessage(sigfoxMsg, 5));

  // Send every 10 minutes
  delay(60000);
}

// Get device ID
String getID () {
  String deviceId = "";
  char sigfoxBuffer;

  // Send AT$I=10 to WISOL to GET ID number
  Sigfox.print("AT$I=10\r");

  while (!Sigfox.available()){
     delay(10);
  }
  
  while(Sigfox.available()){
    sigfoxBuffer = Sigfox.read();
    deviceId += sigfoxBuffer;
    delay(10);
  }
  return deviceId;
}


// Get PAC number
String getPAC (){
  String pacNumber = "";
  char sigfoxBuffer;

  // Send AT$I=11 to WISOL to GET PAC number
  Sigfox.print("AT$I=11\r");
  while (!Sigfox.available()){
     delay(10);
  }
  while(Sigfox.available()){
    sigfoxBuffer = Sigfox.read();
    pacNumber += sigfoxBuffer;
    delay(10);
  }
  return pacNumber;
}

String sendMessage(uint8_t sigfoxMsg[], int bufferSize) {
  String status = "";
  char sigfoxBuffer;

  // Send AT$SF=xx to WISOL to send XX (payload data of size 1 to 12 bytes)
  Sigfox.print("AT$SF=");
  for(int i= 0;i<bufferSize;i++){
    if (sigfoxMsg[i]<0x10) {
      Sigfox.print("0");
    }
    Sigfox.print(String(sigfoxMsg[i], HEX));
  }

  Sigfox.print("\r");

  while (!Sigfox.available()){
     delay(10);
  }

  while(Sigfox.available()){
    sigfoxBuffer = (char)Sigfox.read();
    status += sigfoxBuffer;
    delay(10);
  }

  return status;
}
