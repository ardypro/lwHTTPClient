#ifndef LWSIMPLEHTTPCLIENT_H
#define LWSIMPLEHTTPCLIENT_H

#include <Ethernet.h>

#define LEWEISERVER "open.lewei50.com"
#define LENTH 25

#define DEBUGGING

class lwSimpleHTTPClient
{
public:
    lwSimpleHTTPClient(const char* userkey, const char* gateway);
    virtual ~lwSimpleHTTPClient();
    bool begin();
    bool append(const char* sensor, int value);
    bool append(const char* sensor, double value,unsigned int digits=2);
    void send(); //为了兼容保留的，没有实际意义
protected:

private:
    void sendHeader();

    byte lengthOfInt(int value);
    EthernetClient client;
    const char* userKey;
    const char* gateWay;

};

#endif // LWSIMPLEHTTPCLIENT_H
