#ifndef DEBUGLOG_H
#define DEBUGLOG_H

//#include <stdio.h>
#include "HardwareSerial.h"


class debuglog
{
public:
    debuglog() {}
    virtual ~debuglog() {}

    void println(char* msg="")
    {
        print(msg);
        //printf("\n");
        //printf("\n");
        Serial.println("");
        Serial.println("");
    }

    void println(long msg)
    {
        print(msg);
        Serial.println("");
        Serial.println("");
    }

    void println(double msg)
    {
        print(msg);
        Serial.println("");
        Serial.println("");
    }

    void print(char* msg)
    {
        //printf("%s", msg);
        Serial.println(msg);
    }

    void print(long msg)
    {
        //printf("%ld",msg);
        Serial.println(msg);
    }

    void print(double msg)
    {
        //printf("%f",msg);
        Serial.println(msg);
    }

protected:
private:
};


static debuglog DEBUG;

#endif // DEBUGLOG_H
