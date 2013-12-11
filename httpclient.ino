#include <Arduino.h>
#include "lwHTTPClientLite.h"
#include "lwHTTPClient.h"
#include "memfree.h"

/*
#include "Ethernet.h"
#include "SPI.h"
*/


const char* userkey="029b3884b91e4d00b514158ba1e2ac57";
const char* gateway="02";

lwHTTPClientLite clients(userkey,gateway);
const char* sensor="test";
float f=-8.0301;

void setup()
{
    Serial.begin(9600);
 }


void loop()
{
    delay(12000);


    f++;
    clients.append(sensor,f);
    clients.submit();
    Serial.println("\r\n");

}
