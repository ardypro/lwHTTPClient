#ifndef LWHTTPCLIENTLITE_H
#define LWHTTPCLIENTLITE_H
#define implements public

#include "iget.h"
#include "lwgenericclient.h"
#include "Ethernet.h"
#include <SPI.h>


class lwHTTPClientLite : public lwGenericClient, implements  IGet
{
public:
    lwHTTPClientLite():lwGenericClient()
    {

    }


    lwHTTPClientLite(const char* userkey, const char* gateway):lwGenericClient(userkey,gateway)
    {

    }

    virtual ~lwHTTPClientLite()
    {
    }

    virtual bool connect();

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
    EthernetClient httpClient;
private:

};


#endif // lwHTTPClientLite_H
