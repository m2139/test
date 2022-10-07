#include "CAN_SEND.hpp"

CANSend::CANSend(PinName RD,PinName TD) : can(RD,TD)
{
    for(int i = 0;i < 3;i++){
    DATA[i] = 0;
    }
}

void CANSend::SEND(int id, int data){
    DATA[0] = data % 100;//下2
    DATA[1] = data / 100;//上2
    CANMessage msg(id,DATA,2);
    can.write(msg);
    wait_ms(2);
}