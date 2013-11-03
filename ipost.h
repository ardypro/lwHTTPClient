#ifndef IPOST_H
#define IPOST_H

/*
    数据发送接口
    v1.0    @ 2013-10-01
*/

#define interface class

//#include "Arduino.h"

interface IPost
{
public:
    virtual void append (const char* sensor, bool value) = 0;
    virtual void append (const char* sensor, int value) = 0;
    virtual void append (const char* sensor, unsigned int value) = 0;
    virtual void append (const char* sensor, long value) = 0;
    virtual void append (const char* sensor, unsigned long value) = 0;
    virtual void append (const char* sensor, double value, unsigned int digits=2) = 0;
    virtual void append (const char* sensor, const char* value) = 0;

    virtual void upload()=0;
};

#endif // IPOST_H
