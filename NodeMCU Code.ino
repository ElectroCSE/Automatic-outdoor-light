#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#define led 16 

const char *ssid     = "";
const char *password = "";

WiFiUDP ntpUDP;


NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid, password);

 Serial.println("Connecting");
  while ( WiFi.status() != WL_CONNECTED ) {
    delay (200);
    Serial.println( "." );
  }
Serial.println("Connected");
  timeClient.begin();
  timeClient.setTimeOffset(19800);

pinMode(led, OUTPUT);

   
}

void loop() {
  timeClient.update();

  int hours =  timeClient.getHours();

  if(hours > 5 && hours < 18){
    Serial.print("Light OFF, Time in hours : ");
    Serial.println(hours);
    digitalWrite(led, LOW);
  }else{
    Serial.print("Light ON, Time in hours : ");
    Serial.println(hours);
    digitalWrite(led, HIGH);
  }
  
    
  // Serial.println(timeClient.getFormattedTime()); 

  delay(5000);
}
