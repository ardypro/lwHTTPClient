#include "lwHTTPClientLite.h"

//#define DEBUGGING

#ifdef DEBUGGING
#define sendCMD Serial.print
#else
#define sendCMD   httpClient.print
#endif // DEBUGGING


bool lwHTTPClientLite::connect()
{
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
    char lwHTTPServer[] = "open.lewei50.com";

    Serial.println("connectiing");

    if (!active)
        {

            Serial.println("client.begin()");

            if (Ethernet.begin(mac)==0)
                {
                    return false ;
                }
            else
                {
                    active=true ;
                }
        }

    if (active)
        {
            return  httpClient.connect(lwHTTPServer, 80);
        }

}


void lwHTTPClientLite::uploadValue()
{
    //发送上传指令
    bool connected;
#ifdef DEBUGGING
    connected=true;
#else
    connected=connect();
#endif // DEBUGGING
    if(connected)
        {
            sendCMD("POST /api/V1/Gateway/UpdateSensors/");
            sendCMD(gateWay);
            sendCMD(" HTTP/1.1\r\n");
            //sendCMD("Accept: */*\r\n");
            sendCMD("userkey: ");
            sendCMD(userKey);
            sendCMD("\r\n");
            sendCMD("Host: open.lewei50.com\r\n");
            sendCMD("User-Agent: W5100_Arduino\r\n");
            sendCMD("Content-Length: ");
            sendCMD(strlen(cmdJSON));
            sendCMD("\r\n");
            sendCMD("Connection: close\r\n");
            sendCMD("\r\n");
            sendCMD(cmdJSON);
            sendCMD("\r\n");

            //////////
#ifdef DEBUGGING
            Serial.println("sending json");
            Serial.print("POST /api/V1/Gateway/UpdateSensors/");
            Serial.print(gateWay);
            Serial.print(" HTTP/1.1\r\n");
            //Serial.print("Accept: */*\r\n");
            Serial.print("userkey: ");
            Serial.print(userKey);
            Serial.print("\r\n");
            Serial.print("Host: open.lewei50.com\r\n");
            Serial.print("User-Agent: W5100_Arduino\r\n");
            Serial.print("Content-Length: ");
            Serial.print(strlen(cmdJSON));
            Serial.print("\r\n");
            Serial.print("Connection: close\r\n");
            Serial.print("\r\n");
            Serial.print(cmdJSON);
            Serial.print("\r\n");
#endif
            /////////
        }
    else
        Serial.println("NOT CONNECTED!");
#ifdef DEBUGGING
    //do nothing
#else
    httpClient.stop();
#endif // DEBUGGING

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



