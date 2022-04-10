
#include "ThingSpeak.h"
#include "WiFi.h"
//#include <Wire.h>  //Include Library for HTU21D
//#include "SparkFunHTU21D.h"

//-------Enter your WiFi Details------//
char ssid[] = "Sra";  //SSID
char pass[] = "sra1712@";  //Password
//-----------------------------------//

int count=0; 
const int trigger=2;
const int echo=0;
long T;
float distance;
//HTU21D htu(HTU21DPIN, HTU21D);
WiFiClient client;

//-------------ThingSpeak Details-----------------//
unsigned long myChannelField = 1644740; //Channel ID
const int ChannelField1 = 3; //for Humidity
const char * myWriteAPIKey = "PSQQREFA7DUMS9BX"; //Your Write API Key
//-----------------------------------------------//

//Create an instance of the object
void setup() {
  Serial.begin(115200);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() 
{
  //-----------------WiFi Setup-------------------//
 /* if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.print("Attempting to Connect to SSID: ");
    Serial.println(ssid);
  }
  while(WiFi.status()!= WL_CONNECTED)
  {
    WiFi.begin(ssid,pass);
    Serial.print(".");
    delay(5000);
  }
  Serial.println("\nConnected.");*/
  //--------------------------------------------// 
  digitalWrite(trigger,LOW);
  delay(1);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  T=pulseIn(echo,HIGH);
  distance=(T *0.034)/2;
  delay(10);
   
 /* if(distance<8)    //counting the object
  {
    count++;   
  } */ 
  Serial.println("DISTANCE IN cm\n");
  Serial.println(distance);
 // Serial.println(count);

  delay(2000);

  //-------------Sending Data to ThingSpeak Cloud---------------//
 // ThingSpeak.writeField(myChannelField,ChannelField1,distance, myWriteAPIKey);
}
