#include "CAN_SEND.hpp"

CANSend::CANSend(PinName RD,PinName TD) : can(RD,TD){
    for(int i = 0;i < 8;i++){
        DATA[i] = 0;
    }
}

void CANSend::SEND(int id,int num1,int num2,int num3,int num4)
{
    DATA[0] = num1 >> 8;
    DATA[1] = num1 & 0xff;
    DATA[2] = num2 >> 8;
    DATA[3] = num2 & 0xff;
    DATA[4] = num3 >> 8;
    DATA[5] = num3 & 0xff;
    DATA[6] = num4 >> 8;
    DATA[7] = num4 & 0xff;
    CANMessage msg(id,DATA,8);
    can.write(msg);
    wait_ms(2);
}