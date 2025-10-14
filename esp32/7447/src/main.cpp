//Code by GVV Sharma
//April 29, 2022
//https://www.gnu.org/licenses/gpl-3.0.en.html
//
//Seven segment diplay OTA
//
//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "npal"  // Replace with your network credentials
#define STAPSK  "npal1234"  
#endif



const char* ssid = STASSID;
const char* password = STAPSK;




void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//
void disp_7447(int D, int C, int B, int A);

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
    pinMode(13, OUTPUT);  
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(27, OUTPUT);

}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  //
disp_7447(0,1,0,1);  
}


//Function to drive the IC
void disp_7447(int D, int C, int B, int A)
{
  digitalWrite(13, A); //LSB
  digitalWrite(12, B); 
  digitalWrite(14, C); 
  digitalWrite(27, D); //MSB

}