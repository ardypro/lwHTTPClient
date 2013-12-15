#include "lwPowermeterOverHTTP.h"

lwPowermeterOverHTTP::lwPowermeterOverHTTP(const char* userkey, const char* gateway):lwSimpleHTTPClient(userkey,gateway)
{
    //ctor
}

lwPowermeterOverHTTP::~lwPowermeterOverHTTP()
{
    //dtor
}

bool lwPowermeterOverHTTP::postBatchPowerInfo(int watt, float amp, float kwh, float pf, float voltage)
{
    bool ret;

    if (client.connect(LEWEISERVER,80))
        {
            byte len=130; //去除value值之后的所有字符长度
            len += lengthOfInt(watt);
            len += lengthOfDbl(amp);
            len += lengthOfDbl(kwh);
            len += lengthOfDbl(pf);
            len += lengthOfDbl(voltage);

            sendHeader();
            client.println(len);
            client.println("Connection: close");
            client.println();

						client.print("[");
//功率
            client.print("{\"Name\":\"GL");
            client.print("\",\"Value\":\"");
            client.print(watt);
            client.print("\"},");

//电流
            client.print("{\"Name\":\"DL");
            client.print("\",\"Value\":\"");
            client.print(amp);
            client.print("\"},");

//用电量
            client.print("{\"Name\":\"YDL");
            client.print("\",\"Value\":\"");
            client.print(kwh);
            client.print("\"},");

//功率因数
            client.print("{\"Name\":\"GLYS");
            client.print("\",\"Value\":\"");
            client.print(pf);
            client.print("\"},");

//电压
            client.print("{\"Name\":\"DY");
            client.print("\",\"Value\":\"");
            client.print(voltage);
            client.print("\"}");

            client.println ("]");

#ifdef DEBUGGING
            Serial.println(len);
            Serial.println("Connection: close");
            Serial.println();

						Serial.print("[");
//功率
            Serial.print("{\"Name\":\"GL");
            Serial.print("\",\"Value\":\"");
            Serial.print(watt);
            Serial.print("\"},");

//电流
            Serial.print("{\"Name\":\"DL");
            Serial.print("\",\"Value\":\"");
            Serial.print(amp);
            Serial.print("\"},");

//用电量
            Serial.print("{\"Name\":\"YDL");
            Serial.print("\",\"Value\":\"");
            Serial.print(kwh);
            Serial.print("\"},");

//功率因数
            Serial.print("{\"Name\":\"GLYS");
            Serial.print("\",\"Value\":\"");
            Serial.print(pf);
            Serial.print("\"},");

//电压
            Serial.print("{\"Name\":\"DY");
            Serial.print("\",\"Value\":\"");
            Serial.print(voltage);
            Serial.print("\"}");

            Serial.println ("]");
            Serial.println();
            Serial.println();
#endif // DEBUGGING
            ret= true;
        }
    else
        ret=false;

exitHere:
    client.stop();
    return ret;
}
