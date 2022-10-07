#ifndef CAN_SEND_H
#define CAN_SEND_H
#include "mbed.h"

/*

CANSend can(D4,D10); RD TD
can.SEND(1,1234); DATAは四桁以下専用です。五桁以上はしりません

*/

class CANSend
{
    
public:
    CANSend(PinName RD,PinName TD);
    void SEND(int,int);//id data
private:
    CAN can;//can通信宣言
    char DATA[2];//DATA[0] 下2 DATA[1] 上2
};
#endif