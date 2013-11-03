#include "conversion.h"
//#include "stdio.h"
//#include "stdlib.h"
//#include "string.h"
#include "debuglog.h"

#include "HardwareSerial.h"


conversion::conversion()
{
    //ctor
}

conversion::~conversion()
{
    //dtor
}

unsigned int conversion::intToStr(int value, char* &str)
{
    //返回字符串长度
    unsigned int len;
    len=lenOfInt(value)+1;   //null终止符
    str = (char*) malloc(len);
    //itoa();  //arduino style
    snprintf(str,len,"%d",value);

    return strlen(str);

}

char* conversion::charCat(char* one, char* two)
{
    /*
       来源：http://stackoverflow.com/questions/2218290/concatenate-char-array-in-c

       可能需要引用的库文件：
           #include "stdio.h"
           #include "stdlib.h"
           #include "string.h"
           #include "iostream"

    */

    int len = strlen(one) + strlen(two) + 1;
    char* newStr = (char*) malloc(len);
    strncpy(newStr, one, len);
    strncat(newStr, two, len - strlen(newStr));
    return newStr;
}

unsigned int conversion::lenOfInt(const int value)
{
    char s[20];
    itoa(value,s,10);
    return strlen(s);
}


unsigned int conversion::floatToStr(float value,unsigned int digits, char* &str)
{
    //返回字符串长度
    unsigned int len;
    len=lenOfInt(value)+digits+2;   //小数点和null终止符
    str = (char*) malloc(len);

    dtostrf (value, 1, digits, str);  //arduino style

    //snprintf(str,len,"%g",value);


    return strlen(str);
}

unsigned int conversion::appendChar(char* &dest, const char* str)
{
    /*
        char *str;

        // Initial memory allocation
        str = (char *) malloc (15);
        strcpy (str, "tutorialspoint");
        printf ("String = %s,  Address = %u\n", str, str);

        Serial.println (str);
        // Reallocating memory
        str = (char *) realloc (str, 25);
        strcat (str, ".com");
        printf ("String = %s,  Address = %u\n", str, str);

        Serial.println (str);
        free (str);
    */


    dest  = (char *) realloc(dest , strlen(dest)+strlen(str)+1);
    strcat(dest, str);

    return strlen(dest);
}

void conversion::FreeAndNil(char* &value)
{
    free(value);
    value=NULL;
}

unsigned int conversion::longToStr(long value,  char* &str)
{
    str=(char*)malloc(12);
    snprintf(str,12,"%ld",value);
    return strlen(str);
}

unsigned int conversion::ulongToStr(unsigned long value, char* &str)
{
    str=(char*)malloc(12);
    snprintf(str,12,"%lu",value);
    return strlen(str);
}



unsigned int conversion::uintToStr(unsigned int value, char* &str)
{
    str=(char*)malloc(12);
    snprintf(str,12,"%u",value);
    return strlen(str);
}

conversion converter;
