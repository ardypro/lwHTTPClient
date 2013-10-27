#ifndef LWGET_H
#define LWGET_H

#include <iget.h>


class lwGet : public IGet
{
public:
    lwGet();
    virtual ~lwGet();

    //implements iget
    virtual void getValue(const char* sensor, bool &value);
    virtual void getValue(const char* sensor, int &value);
    virtual void getValue(const char* sensor, unsigned int &value);
    virtual void getValue(const char* sensor, long &value);
    virtual void getValue(const char* sensor, unsigned long &value);
    virtual void getValue(const char* sensor, float &value);
    virtual void getValue(const char* sensor, double &value,unsigned int digits=2);//IGet接口中，此处并没有digits参数，但是也能编译成功 （？）
    virtual void getValue(const char* sensor, char* &value);
protected:
private:
};

#endif // LWGET_H
