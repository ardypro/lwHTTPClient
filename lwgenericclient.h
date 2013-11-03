#ifndef LWGENERICCLIENT_H
#define LWGENERICCLIENT_H

/*
    乐为物联网客户端基类
    ====================

    这是整个library的基类，其它lib都是在此基类上面通过实现不同的接口而形成。

    由于所有的服务都需要发送数据到服务器,所以基类也实现了IPost接口。



    使用方法：

    创建实例之后，第一步设置好UserKey和GateWay；
    上传数据时，先调用append()方法追加数据，然后统一通过upload()来上传到服务器。

    根据协议，每60秒需要至少调用一次update()方法发送心跳包，保持与服务器的连接。



    子类化注意事项
    ==============

    创建此基类的子类的时候，需要注意upload（）方法并没有真正实现上传数据的功能，
    具体实现的代码在子类的uploadValue()方法中。

*/

/*
    版本历史
    ========

    v1.0 @2013-10-01    创建项目

*/


#include "ipost.h"
#include "debuglog.h"
#include "Arduino.h"


class lwGenericClient : public IPost
{
public:
    lwGenericClient (const char* userkey, const char* gateway)
    {
        userKey = userkey;
        gateWay = gateway;
        cmdJSON=(char*) malloc(9);
        clearCommand();
        lastTime = millis();
    }

    lwGenericClient()
    {
        lastTime = millis();
    }

    void setUserKey (const char* userkey)
    {
        userKey = userkey;
    }

    void setGateWay (const char* gateway)
    {
        gateWay = gateway;
    }

    virtual  void append (const char* sensor, bool value) = 0;
    virtual  void append (const char* sensor, int value) = 0;
    virtual  void append (const char* sensor, unsigned int value) = 0;
    virtual  void append (const char* sensor, long value) = 0;
    virtual  void append (const char* sensor, unsigned long value) = 0;
    virtual  void append (const char* sensor, double value,unsigned int digits=2) = 0;
    virtual  void append (const char* sensor, const char* value) = 0;

    virtual void upload();

protected:
    virtual void uploadValue() = 0;
    const char* userKey;
    const char* gateWay;
    char* cmdJSON;

    virtual void clearCommand();
    virtual void appendCommand(const char* cmd);
    unsigned int interval;
    unsigned long lastTime;
private:

};

#endif // LWGENERICCLIENT_H
