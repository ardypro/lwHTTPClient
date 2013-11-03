#ifndef CONVERSION_H
#define CONVERSION_H

//#include "Arduino.h"

class conversion
{
public:
    conversion();
    virtual ~conversion();

    unsigned int intToStr(int value, char* &str);
    unsigned int longToStr(long value,char* &str);
    char* charCat(char* one, char* two);
    unsigned int floatToStr(float value,unsigned int digits, char* &str);
    unsigned int appendChar(char* &dest, const char* str);
    unsigned int lenOfInt(const int value);
    unsigned int ulongToStr(unsigned long value, char* &str);
    unsigned int uintToStr(unsigned int value, char* &str);
    void FreeAndNil(char* &value);
protected:
private:
};

extern conversion converter;

#endif // CONVERSION_H
