#include "lwHTTPClient.h"

lwHTTPClient::lwHTTPClient()
{
    //ctor
}

lwHTTPClient::~lwHTTPClient()
{
    //dtor
}

lwHTTPClient::lwHTTPClient(const char* userkey, const char* gateway):lwGenericClient(userkey, gateway)
{

}

void lwHTTPClient::append(const char* sensor, bool value)
{

}

void lwHTTPClient::append(const char* sensor, int value)
{

}

void lwHTTPClient::append(const char* sensor, unsigned int value)
{

}

void lwHTTPClient::append(const char* sensor, long value)
{

}

void lwHTTPClient::append(const char* sensor, unsigned long value)
{

}

void lwHTTPClient::append(const char* sensor, double value, unsigned int digits)
{

}

void lwHTTPClient::append(const char* sensor, const char* value)
{

}


void lwHTTPClient::getValue(const char* sensor, bool &value)
{

}

void lwHTTPClient::getValue(const char* sensor, int &value)
{

}

void lwHTTPClient::getValue(const char* sensor, unsigned int &value)
{

}

void lwHTTPClient::getValue(const char* sensor, long &value)
{

}

void lwHTTPClient::getValue(const char* sensor, unsigned long &value)
{

}

void lwHTTPClient::getValue(const char* sensor, float &value)
{

}

void lwHTTPClient::getValue(const char* sensor, double &value, unsigned int digits)
{

}

void lwHTTPClient::getValue(const char* sensor, char* &value)
{

}

