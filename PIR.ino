#include "ThingSpeak.h"
#include "WiFi.h"
//-------Enter your WiFi Details------//
char ssid[] = "Sra";  //SSID
char pass[] = "sra1712@";  //Password
//-----------------------------------//
WiFiClient client;
//-------------ThingSpeak Details-----------------//
unsigned long myChannelField = 1644740; //Channel ID
const int ChannelField1 = 4;
const int ChannelField2 = 5;
const char * myWriteAPIKey = "PSQQREFA7DUMS9BX"; //Your Write API Key
//-----------------------------------------------//

int ledPin = 2; // choose the pin for the LED
int inputPin = 0; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
int count=0;
int res;
void setup() 
{
 pinMode(ledPin, OUTPUT); // declare LED as output
 pinMode(inputPin, INPUT); // declare sensor as input
 Serial.begin(115200);
 
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}
void loop(){
  //-----------------WiFi Setup-------------------//
  if(WiFi.status()!= WL_CONNECTED)
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
  Serial.println("\nConnected.");
  //--------------------------------------------//

 val = digitalRead(inputPin); // read input value
 if (val == HIGH) { // check if the input is HIGH
 digitalWrite(ledPin, HIGH); // turn LED ON
 if (pirState == LOW) {
 // we have just turned on
 Serial.println("Motion detected!");
 Serial.println(count);
 count++; 
 res=digitalRead(ledPin);
 Serial.println("LED STATUS");
 Serial.println(res);
 
 // We only want to print on the output change, not state
 pirState = HIGH;
 }
 } else {
 digitalWrite(ledPin, LOW); // turn LED OFF
 if (pirState == HIGH){
 // we have just turned of
 Serial.println("Motion ended!");
 // We only want to print on the output change, not state
 pirState = LOW;
 }
 }
ThingSpeak.writeField(myChannelField,ChannelField1,count, myWriteAPIKey);
ThingSpeak.writeField(myChannelField,ChannelField2,res, myWriteAPIKey);

}