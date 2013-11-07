#include "lwHTTPClientLite.h"

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
char lwHTTPServer[] = "open.lewei50.com";

bool lwHTTPClientLite::connect()
{

}

void lwHTTPClientLite::append(const char* sensor, bool value)
{

}

void lwHTTPClientLite::append(const char* sensor, int value)
{

}

void lwHTTPClientLite::append(const char* sensor, unsigned int value)
{

}

void lwHTTPClientLite::append(const char* sensor, long value)
{

}

void lwHTTPClientLite::append(const char* sensor, unsigned long value)
{

}

void lwHTTPClientLite::append(const char* sensor, double value, unsigned int digits)
{

}

void lwHTTPClientLite::append(const char* sensor, const char* value)
{

}



void lwHTTPClientLite::submit()
{}

void lwHTTPClientLite::uploadValue()
{
    DEBUG.println(cmdJSON);
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

}

void lwHTTPClientLite::appendCommand(const char* cmd)
{

}
