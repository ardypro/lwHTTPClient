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

}

void lwHTTPClientLite::append(const char* sensor, bool value)
{
    lwGenericClient::append(sensor,value);

}

void lwHTTPClientLite::append(const char* sensor, int value)
{
    lwGenericClient::append(sensor,value);

}

void lwHTTPClientLite::append(const char* sensor, unsigned int value)
{
    lwGenericClient::append(sensor,value);

}

void lwHTTPClientLite::append(const char* sensor, long value)
{
    lwGenericClient::append(sensor,value);

}

void lwHTTPClientLite::append(const char* sensor, unsigned long value)
{
    lwGenericClient::append(sensor,value);

}

void lwHTTPClientLite::append(const char* sensor, double value, unsigned int digits)
{
    lwGenericClient::append(sensor,value);

}

void lwHTTPClientLite::append(const char* sensor, const char* value)
{
    lwGenericClient::append(sensor,value);

}



void lwHTTPClientLite::submit()
{
    lwGenericClient::submit();
}

void lwHTTPClientLite::send(const char* str)
{
#ifdef DEBUGGING
    Serial.print(str);
#else
    httpClient.print(str);
#endif // DEBUGGING
}

void lwHTTPClientLite::uploadValue()
{
    DEBUG.println(cmdJSON);

    send(cmdJSON);
    send("POST /api/V1/Gateway/UpdateSensors/");
    send(gateWay);
    send(" HTTP/1.1\n");
    send("userkey: ");
    send(userKey);
    send("\n");
    send("Host: open.lewei50.com\n");
    send("User-Agent: W5100@Arduino\n");
    send("Content-Length: ");

//#ifdef DEBUGGING
//    Serial.print(strlen(cmdJSON));
//#else
//    httpClient.print(strlen(cmdJSON));
//#endif // DEBUGGING

    sendCMD(strlen(cmdJSON));

    send("\n");
    send("Connection: close\n");
    send("\n");
    send(cmdJSON);







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


void lwHTTPClientLite::clearCommand()
{
    lwGenericClient::clearCommand();
}

void lwHTTPClientLite::appendCommand(const char* cmd)
{
    lwGenericClient::appendCommand(cmd);
}

void lwHTTPClientLite::formatCommand()
{

}
