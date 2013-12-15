#include "Ethernet.h"
#include "SPI.h"
#include "Arduino.h"

#include "pwrMeter.h"
//#include "lwSimpleHTTPClient.h"  //upload data one by one
//#include "SoftwareSerial.h"      //communicate with 485 with software serial
#include "lwPowermeterOverHTTP.h"  //upload batch data

#define userkey "029b3884b91e4d00b514158ba1e2ac57"
#define gateway "01"

//SoftwareSerial mySerial(2, 3);
pwrMeter meter;
lwPowermeterOverHTTP *hclient;

void setup()
{
  Serial.begin(4800);
  //meter.begin(&mySerial, 4800);
  meter.begin(&Serial);
  hclient = new lwPowermeterOverHTTP(userkey, gateway);
  if (  hclient->initialize())
    Serial.println("DHCP OK");
  else
    Serial.println("DHCP FAIL");
}

void loop()
{
  if (meter.available(2) > 0)  // 读模块2的缓冲区
  {
    int Watt = 0;
    float Amp = 0;
    float Kwh = 0;
    float Pf = 0;
    float Voltage = 0;

    if (meter.readData(Watt, Amp, Kwh, Pf, Voltage)) // 一次性读入所有的电量数据
    {
      if (Voltage>0)
      {
        hclient->postBatchPowerInfo(Watt,Amp,Kwh, Pf, Voltage);
      }
    }
    else
      //Serial.println("reading error");
      ;
  }
        delay(12000);  
}




