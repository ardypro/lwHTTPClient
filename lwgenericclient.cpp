#include "lwgenericclient.h"
#include "conversion.h"
//#include <string.h>
//#include <stdio.h>


void lwGenericClient::upload()
{
    uploadValue(); //由各子类来实现，提交完数据之后，复位cmdJSON和lastTime.
    clearCommand();

    lastTime = millis();

};

void lwGenericClient::clearCommand()
{
    cmdJSON = (char*) realloc(cmdJSON,1);
    strcpy(cmdJSON, "");
}

void lwGenericClient::appendCommand(const char* cmd)
{
    converter.appendChar(cmdJSON, cmd);
}
