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
void sevenseg(int a,int b,int c,int d,int e,int f,int g);

void setup(){
  OTAsetup();

  //-------------------//
  // Custom setup code //
  //-------------------//
    pinMode(13, OUTPUT);  
    pinMode(12, OUTPUT);
    pinMode(14, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(26, OUTPUT);
    pinMode(25, OUTPUT);
    pinMode(33, OUTPUT);            

}

void loop() {
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  //
//  digitalWrite(12, 0); 
//  digitalWrite(13, 1); 
//  digitalWrite(14, 0); 
//  digitalWrite(15, 0); 
//  digitalWrite(16, 0); 
//  digitalWrite(17, 0);     
//  digitalWrite(18, 0); 
sevenseg(0,1,0,0,1,0,0);  
}



//Function to drive the display
void sevenseg(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(13, a); 
  digitalWrite(12, b); 
  digitalWrite(14, c); 
  digitalWrite(27, d); 
  digitalWrite(26, e); 
  digitalWrite(25, f);     
  digitalWrite(33, g); 
}