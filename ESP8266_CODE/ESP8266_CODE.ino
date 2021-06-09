#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "fauxmoESP.h"

#define ssid "G8X"
#define pass "Saksham@1234"

#define device1 "bedroom light"
#define device2 "TV"

fauxmoESP fauxmo; 

void wifi() 
{
  WiFi.mode(WIFI_STA);

  WiFi.begin(ssid,pass);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(100);
  }
}

void setup() 
{
  Serial.begin(115200);
  wifi();
  fauxmo.createServer(true);
  fauxmo.setPort(80);

  fauxmo.enable(true);
  fauxmo.addDevice(device1);
  fauxmo.addDevice(device2);

  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) {
  Serial.printf("[MAIN](%s) state: %s\n",device_name, state ? "ON" : "OFF");
    if (strcmp(device_name, device1) == 0)
    {
      if (state)
        Serial.print("1");
      else
        Serial.print("2");
    }
    if (strcmp(device_name, device2) == 0)
    {
      if (state)
        Serial.print("3");
      else
        Serial.print("4");
    }
  });
}

void loop() 
{
  fauxmo.handle();
}
