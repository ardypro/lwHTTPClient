#include "lwHTTPClientLite.h"

#define DEBUGGING

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
char lwHTTPServer[] = "open.lewei50.com";


#ifdef DEBUGGING
    #define sendCMD Serial.print
#else
    #define sendCMD   httpClient.print
#endif // DEBUGGING


bool lwHTTPClientLite::connect()
{
    Serial.print("User key:\t");
    Serial.println(userKey);
}


void lwHTTPClientLite::uploadValue()
{
    //发送上传指令
    sendCMD("POST /api/V1/Gateway/UpdateSensors/");
    sendCMD(gateWay);
    sendCMD(" HTTP/1.1\n");
    sendCMD("userkey: ");
    sendCMD(userKey);
    sendCMD("\n");
    sendCMD("Host: open.lewei50.com\n");
    sendCMD("User-Agent: W5100@Arduino\n");
    sendCMD("Content-Length: ");
    sendCMD(strlen(cmdJSON));
    sendCMD("\n");
    sendCMD("Connection: close\n");
    sendCMD("\n");
    sendCMD(cmdJSON);
    sendCMD("\n");
}


void lwHTTPClientLite::getValue(const char* sensor, bool &value)
{

}

void lwHTTPClientLite::getValue(const char* sensor, int &value)
{

}

void lwHTTPClientLite::getValue(const char* sensor, unsigned int &value)
{

}

void lwHTTPClientLite::getValue(const char* sensor, long &value)
{

}

void lwHTTPClientLite::getValue(const char* sensor, unsigned long &value)
{

}

void lwHTTPClientLite::getValue(const char* sensor, float &value)
{

}

void lwHTTPClientLite::getValue(const char* sensor, double &value, unsigned int digits)
{

}

void lwHTTPClientLite::getValue(const char* sensor, char* &value)
{

}



