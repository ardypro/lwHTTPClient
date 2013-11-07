#include "lwgenericclient.h"
#include "conversion.h"
//#include <string.h>
//#include <stdio.h>


void CMD_Composite(char* &cmd,const char* s,const char* v)
{
    //生成传感器数值JSON字串 {"Name":"SD","Value":"33"},
    converter.appendChar(cmd,"{\"Name\":\"");
    converter.appendChar(cmd, s);
    converter.appendChar(cmd,"\",\"Value\":\"");
    converter.appendChar(cmd,v);
    converter.appendChar(cmd,"\"},");
}



void lwGenericClient::submit()
{
    //去掉cmdJSON最后面的逗号
    int len;
    len=strlen(cmdJSON);
    cmdJSON[len-1]='\0';
    converter.appendChar(cmdJSON,"]");

    //formatCommand();
    uploadValue(); //由各子类来实现，提交完数据之后，复位cmdJSON和lastTime.
    clearCommand();

    lastTime = millis();

};

void lwGenericClient::clearCommand()
{
    cmdJSON = (char*) realloc(cmdJSON,2);
    strcpy(cmdJSON, "[");
}

void lwGenericClient::appendCommand(const char* cmd)
{
    converter.appendChar(cmdJSON, cmd);
}

void lwGenericClient::append(const char* sensor, bool value)
{
    append(sensor, (int)value);
}

void lwGenericClient::append(const char* sensor, int value)
{

    // TODO (Ardypro#1#): 可以考虑用snPrintf等来实现，要先测试效率

    char* i;
    converter.intToStr(value, i);
    CMD_Composite(cmdJSON,sensor,i);
    converter.FreeAndNil(i);
}

void lwGenericClient::append(const char* sensor, unsigned int value)
{
    char* u ;
    converter.uintToStr(value,u);
    CMD_Composite(cmdJSON,sensor,u);
    converter.FreeAndNil(u);
}

void lwGenericClient::append(const char* sensor, long value)
{
    char* l;
    converter.longToStr(value, l);
    CMD_Composite(cmdJSON,sensor,l);
    converter.FreeAndNil(l);
}

void lwGenericClient::append(const char* sensor, unsigned long value)
{
    char* u;
    converter.ulongToStr(value,u);
    CMD_Composite(cmdJSON,sensor, u);
    converter.FreeAndNil(u);
}

void lwGenericClient::append(const char* sensor, double value,unsigned int digits)
{
    //arduino貌似有ftoa方法
    char* f;
    //f= (char*) malloc(1); //test only
    converter.floatToStr(value, digits,f);
    CMD_Composite(cmdJSON,sensor,f);
    converter.FreeAndNil(f);
}
void lwGenericClient::append(const char* sensor, const char* value)
{
    CMD_Composite(cmdJSON,sensor,value);
}
