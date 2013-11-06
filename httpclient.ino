#include <Arduino.h>
#include "lwHTTPClientLite.h"
#include "memfree.h"

/*
#include "Ethernet.h"
#include "SPI.h"
*/
#define userkey ""
#define gateway ""

lwHTTPClientLite clients;
const char* sensor="humidity";
int i=23;
float f=98.03;

void setup()
{
    Serial.begin(9600);
    Serial.println("begin test...");

    clients.append(sensor,i);
    clients.append(sensor,f);
    clients.submit();
}



void loop()
{
    delay(2000);
    i++;
    f++;
    clients.append(sensor,i);
    clients.append(sensor,f);
    clients.submit();

    Serial.println("");
    Serial.print("freeMemory()=");
    Serial.println(freeMemory());
}
