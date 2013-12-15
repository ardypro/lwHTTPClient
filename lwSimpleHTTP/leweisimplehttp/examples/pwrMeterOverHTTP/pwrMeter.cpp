#include "pwrMeter.h"


pwrMeter::pwrMeter()
{
    //ctor
}

pwrMeter::~pwrMeter()
{
    //dtor
}

byte pwrMeter::send_query(unsigned char *query, size_t string_length)
{
    byte i;
    for (i = 0; i < string_length; i++)
    {
        UART->write(query[i]); //JingLi
    }
    /* without the following delay, the reading of the response might be wrong
     * apparently, */
    delay(200);            /* FIXME: value to use? */

    return i;           /* it does not mean that the write was succesful, though */
}

byte pwrMeter::receive_response(unsigned char *received_string)
{
    bytesReceived = 0;
    byte i = 0;

    /* wait for a response; this will block! */
    while (UART->available() == 0)
    {
        delay(1);
        if (i++ > TIMEOUT)
        {
            UART->println("receive timeout.");
#ifdef DEBUGGING
            Serial.println("receive timeout.");
#endif
        }
        return bytesReceived;
    }
    delay(200);
    /* FIXME: does UART->available wait 1.5T or 3.5T before exiting the loop? */
    while (UART->available())
    {
        received_string[bytesReceived] = UART->read();  //ORIGINAL.
        bytesReceived++;
        if (bytesReceived >= MAX_RESPONSE_LENGTH)
        {
            return PORT_ERROR;
        }
    }


    return (bytesReceived);
}



// int pwrMeter::Analysis_data(void) //已经集成到readData()方法中，因此被注释掉
// {
//     int ret;
//     unsigned char i;
//     crcdata crcnow;
//     ret = -1;
//     //if(Comm1.Status==2)
//     {
//         if (RX_Buffer[0] == Read_ID)
//         {
//             crcnow.word16 = chkcrc(RX_Buffer, bytesReceived - 2); //bytesReceived
//             if ((crcnow.byte[0] == RX_Buffer[bytesReceived - 1]) && (crcnow.byte[1] == RX_Buffer[bytesReceived - 2])) //CRC
//             {
//                 Voltage_data = (((unsigned int)(RX_Buffer[3])) << 8) | RX_Buffer[4]; //Voltage_data
//                 Current_data = (((unsigned int)(RX_Buffer[5])) << 8) | RX_Buffer[6]; //Current_data
//                 Power_data = (((unsigned int)(RX_Buffer[7])) << 8) | RX_Buffer[8]; //Power_data
//                 Energy_data = (((unsigned long)(RX_Buffer[9])) << 24) | (((unsigned long)(RX_Buffer[10])) << 16) | (((unsigned long)(RX_Buffer[11])) << 8) | RX_Buffer[12]; ////Energy_data
//                 Pf_data = (((unsigned int)(RX_Buffer[13])) << 8) | RX_Buffer[14]; //Pf_data
//                 ret = 1;
//             }
//         }
//         //Comm1.Status=0;
//     }
//     return ret;
// }

byte pwrMeter::read_data(void)
{
    byte ret;
    union crcdata
    {
        unsigned int word16;
        unsigned char byte[2];
    };
    crcdata crcnow;

    delay(1800);
    Tx_Buffer[0] = Read_ID;
    Tx_Buffer[1] = 0x03;
    Tx_Buffer[2] = 0x00;
    Tx_Buffer[3] = 0x48;
    Tx_Buffer[4] = 0x00;
    Tx_Buffer[5] = 0x06;
    crcnow.word16 = chkcrc(Tx_Buffer, 6);
    Tx_Buffer[6] = crcnow.byte[1]; //CRC
    Tx_Buffer[7] = crcnow.byte[0];

    ret = send_query(Tx_Buffer, TX_BUFFER_SIZE);
#ifdef DEBUGGING
    Serial.println("has incoming data");
#endif
    return ret;
}

byte pwrMeter::available(byte SlaveID)
{
    Read_ID = SlaveID;
    //2013-12-15  因为查询数据的命令是固定的，因而对于常用的slaveID对应的TXBUFFER，直接给予CRC，加快运行速度
    switch (SlaveID)
    {
    case 1:
        UART->write(0x01);
        UART->write(0x03);
        UART->write(0x00);
        UART->write(0x48);
        UART->write(0x00);
        UART->write(0x06);
        UART->write(0x45);
        UART->write(0xDE);
        delay(200);
        break;
    case 2:
        UART->write(0x02);
        UART->write(0x03);
        UART->write(0x00);
        UART->write(0x48);
        UART->write(0x00);
        UART->write(0x06);
        UART->write(0x45);
        UART->write(0xED);
        delay(200);
        break;
    default:
        read_data();  //其余ID需要计算CRC，因此要调用read_data()和send_query()方法
    }

    return  receive_response(RX_Buffer);

}

bool pwrMeter::readData(int &watt, float &amp, float &kwh, float &pf, float &voltage)
{
    //response_length = receive_response(RX_Buffer); //移至available()
    union crcdata
    {
        unsigned int word16;
        unsigned char byte[2];
    };

    if (bytesReceived > 0)
    {
        if (RX_Buffer[0] == Read_ID)
        {
            crcdata crcnow;
            crcnow.word16 = chkcrc(RX_Buffer, bytesReceived - 2); //bytesReceived
            if ((crcnow.byte[0] == RX_Buffer[bytesReceived - 1]) && (crcnow.byte[1] == RX_Buffer[bytesReceived - 2])) //CRC
            {
                voltage = (float) ((((unsigned int)(RX_Buffer[3])) << 8) | RX_Buffer[4]) / 100; //Voltage_data
                amp = (float)((((unsigned int)(RX_Buffer[5])) << 8) | RX_Buffer[6]) / 1000; //Current_data
                watt = (((unsigned int)(RX_Buffer[7])) << 8) | RX_Buffer[8]; //Power_data
                kwh = (float) ((((unsigned long)(RX_Buffer[9])) << 24) | (((unsigned long)(RX_Buffer[10])) << 16) | (((unsigned long)(RX_Buffer[11])) << 8) | RX_Buffer[12]) / 3200; ////Energy_data
                pf = (float) ((((unsigned int)(RX_Buffer[13])) << 8) | RX_Buffer[14]) / 1000; //Pf_data

                return true;
            }
        }
    }
    else
    {
        return false ;
    }
}

#ifdef HARDSERIAL
void pwrMeter::begin(HardwareSerial *serial, int baud)
{
    UART = serial;
    UART->begin(baud);
}
#else
void pwrMeter::begin(SoftwareSerial *serial, int baud)
{
    UART = serial;
    UART->begin(baud);
}
#endif




