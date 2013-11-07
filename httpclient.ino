#include <Arduino.h>
#include "lwHTTPClientLite.h"
#include "lwHTTPClient.h"
#include "memfree.h"

/*
#include "Ethernet.h"
#include "SPI.h"
*/
//#define userkey "Jack"
//#define gateway "Zhong"

const char* userkey="Jack";
const char* gateway="Zhong";

lwHTTPClientLite clients(userkey,gateway);
const char* sensor="humidity";
int i=-7293;
float f=-98.0301;

void setup()
{
    Serial.begin(9600);
 }


void upload()
{
    clients.submit();
    Serial.println("\n");
}

void loop()
{
    delay(2000);

    bool b=true ;
    clients.append(sensor,b);
    upload();

    i++;
    f++;
    clients.append(sensor,i);
    clients.append(sensor,f);
    upload();

}
