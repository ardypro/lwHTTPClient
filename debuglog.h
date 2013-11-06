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
#ifdef EMULATOR
        printf("\n");
#else
        Serial.println("");
#endif
    }

    void println(long msg)
    {
        print(msg);
        Serial.println("");
    }

    void println(double msg)
    {
        print(msg);
        Serial.println("");
    }

    void print(char* msg)
    {
#ifdef EMULATOR
        printf("%s", msg);
#else
        Serial.print(msg);
#endif
    }

    void print(long msg)
    {
#ifdef EMULATOR
        printf("%ld",msg);
#else
        Serial.print(msg);
#endif
    }

    void print(double msg)
    {
#ifdef EMULATOR
        printf("%f",msg);
#else
        Serial.print(msg);
#endif
    }

protected:
private:
};


static debuglog DEBUG;

#endif // DEBUGLOG_H
