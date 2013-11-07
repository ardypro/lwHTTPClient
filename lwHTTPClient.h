#ifndef LWHTTPCLIENT_H
#define LWHTTPCLIENT_H

#include <lwHTTPClientLite.h>


class lwHTTPClient : public lwHTTPClientLite
{
    public:
        lwHTTPClient();
        lwHTTPClient(const char* userkey, const char* gateway);//:lwHTTPClientLite(userkey,gateway);
        virtual ~lwHTTPClient();
    protected:
    private:
};

#endif // LWHTTPCLIENT_H
