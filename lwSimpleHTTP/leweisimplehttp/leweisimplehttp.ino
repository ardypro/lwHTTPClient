#include <Arduino.h>
#include "lwSimpleHTTPClient.h"




const char* uk  ="029b3884b91e4d00b514158ba1e2ac57";
const char* gw= "02";

lwSimpleHTTPClient* cl;

int i=-2;

void setup()
{
    Serial.begin(4800);

    cl=new lwSimpleHTTPClient(uk,gw);
    if( cl->begin())
        Serial.println("DHCP OK");
    else
        Serial.println("DHCP Fail");

}

void loop()
{
   if( cl->append("test",i))
		Serial.println("append successfully");
	 else
		Serial.println("append failed");
    cl->send();
    i++;
    delay(12000);
}
