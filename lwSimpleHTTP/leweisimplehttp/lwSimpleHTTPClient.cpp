#include "lwSimpleHTTPClient.h"


lwSimpleHTTPClient::lwSimpleHTTPClient(const char* userkey, const char* gateway)
{
    userKey=userkey;
    gateWay=gateway;
}

lwSimpleHTTPClient::~lwSimpleHTTPClient()
{
    //dtor
}

bool lwSimpleHTTPClient::begin()
{
    // TODO (Jack#1#): 以后增加支持固定IP、代理等
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

    if (Ethernet.begin(mac)==0)
        return false;
    else
        return true;
}

void lwSimpleHTTPClient::sendHeader()
{
    Serial.println("sending json");

    client.print("POST /api/V1/Gateway/UpdateSensors/");
    client.print(gateWay);
    client.println(" HTTP/1.1");
    client.print("userkey: ");
    client.println(userKey);
    client.println("Host: open.lewei50.com");
    client.println("User-Agent: UNO");
    client.print("Content-Length: ");

#ifdef DEBUGGING
    Serial.print("POST /api/V1/Gateway/UpdateSensors/");
    Serial.print(gateWay);
    Serial.println(" HTTP/1.1");
    Serial.print("userkey: ");
    Serial.println(userKey);
    Serial.println("Host: open.lewei50.com");
    Serial.println("User-Agent: UNO");
    Serial.print("Content-Length: ");
#endif
}

bool lwSimpleHTTPClient::append(const char* sensor, int value)
{
    bool ret;
    if (client.connect(LEWEISERVER,80))
        {
            sendHeader();
            client.println(lengthOfInt(value)+LENTH+strlen(sensor));
                       client.println("Connection: close");
                       client.println();
                        client.print("[{\"Name\":\"");
            client.print(sensor);
            client.print("\",\"Value\":\"");
            client.print(value);
            client.println ("\"}]");

#ifdef DEBUGGING
            Serial.println(lengthOfInt(value)+LENTH+strlen(sensor));

            Serial.println("Connection: close");
            Serial.println(""); //必须的空白行
            Serial.print("[{\"Name\":\"");
            Serial.print(sensor);
            Serial.print("\",\"Value\":\"");
            Serial.print(value);
            Serial.println ("\"}]");
#endif // DEBUGGING
            ret= true;
        }
    else
        ret=false;

    client.stop();
    return ret;
}






byte lwSimpleHTTPClient::lengthOfInt(int value)
{
    if (value>0)
        {
            return (int)log10(value)+1;
        }
    else if (value=0)
        return 1;
    else
        return (int) log10((abs(value)))+2;
}

void lwSimpleHTTPClient::send()
{
    //do nothing
}

bool lwSimpleHTTPClient::append(const char* sensor, double value,unsigned int digits)
{
    int i;
    i= (int) value * 10^digits;

    bool ret;
    if (client.connect(LEWEISERVER,80))
        {
            sendHeader();
            client.print(lengthOfInt(i)+LENTH+strlen(sensor));
            client.print("\r\n");
            client.print("Connection: close\r\n");
            client.println("\r\n"); //必须的空白行
            client.print("[{\"Name\":\"");
            client.print(sensor);
            client.print("\",\"Value\":\"");
            client.print(value);
            client.println ("\"}]\r\n");

            ret=true;
        }
    else
        ret=false;

    client.stop();
    return ret;
}
