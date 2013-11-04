#ifndef LWHTTPCLIENT_H
#define LWHTTPCLIENT_H
#define implements public
#include "iget.h"
#include "lwgenericclient.h"
#include "Ethernet.h"
#include <SPI.h>


class lwHTTPClient : public lwGenericClient, implements  IGet
{
public:
    lwHTTPClient():lwGenericClient()
    {

    }


    lwHTTPClient(const char* userkey, const char* gateway):lwGenericClient(userkey,gateway)
    {

    }

    virtual ~lwHTTPClient()
    {

    }

    virtual bool connect();

    //implements ipost
    void append(const char* sensor, bool value);
    void append(const char* sensor, int value);
    void append(const char* sensor, unsigned int value);
    void append(const char* sensor, long value);
    void append(const char* sensor, unsigned long value);
    void append(const char* sensor, double value,unsigned int digits=2);
    void append(const char* sensor, const char* value);

    virtual void upload();

    //implements iget
    virtual void getValue(const char* sensor, bool &value);
    virtual void getValue(const char* sensor, int &value);
    virtual void getValue(const char* sensor, unsigned int &value);
    virtual void getValue(const char* sensor, long &value);
    virtual void getValue(const char* sensor, unsigned long &value);
    virtual void getValue(const char* sensor, float &value);
    virtual void getValue(const char* sensor, double &value,unsigned int digits=2);//IGet接口中，此处并没有digits参数，但是也能编译成功 （？）
    virtual void getValue(const char* sensor, char* &value);

protected:
    virtual void uploadValue() ;
    virtual void clearCommand();
    virtual void appendCommand(const char* cmd);
private:

    EthernetClient httpClient;

};


#endif // LWHTTPCLIENT_H
